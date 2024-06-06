#include<iostream>
#include<mutex>
#include<thread>
#include <iomanip>  // put_time

using namespace std;
std::timed_mutex tmtx;

void testTmtx_tlf()
{
	bool flag = tmtx.try_lock_for(std::chrono::seconds(3));
	if (flag)
	{
		std::this_thread::sleep_for(std::chrono::seconds(5));
		tmtx.unlock();
	}
	else
	{
		cout << "其他线程正在访问临界区，等待5秒后未等到，已退出。" << endl;
	}
}
void testTmtx_tlu()
{
	//1. 设置截止时间：（当前时间的两秒后）
	// dieline 的类型是 std::chrono::system_clock::time_point（时间点类）。
	// 这是因为 std::chrono::system_clock::now() 返回的是时间点类的当前时间点
	auto dieline = std::chrono::system_clock::now() + std::chrono::seconds(2);

	//2. 测试上时间锁：
	bool flag = tmtx.try_lock_until(dieline);
	if (flag)
	{
		std::this_thread::sleep_for(std::chrono::seconds(5));
		tmtx.unlock();
	}
	else
	{
	// 打印 std::chrono::system_clock::time_point（时间点类）：
		//1. 使用
		//   a. 使用 std::chrono::system_clock::to_time_t() 函数将时间点转换为 std::time_t 类型(时间戳类型），
		//   b. 然后使用 C 标准库中的 std::ctime()函数 将 时间戳类对象 转换为可读的字符串格式（将时间戳转为字符串）。
		std::time_t time_t_dieline = std::chrono::system_clock::to_time_t(dieline);
		cout << "其他线程正在访问临界区，已超过截止时间：" << std::ctime(&time_t_dieline) << "，已退出。" << endl;
		//2. 使用 std::put_time 格式化并打印  //<iomanip> —— put_time()
		//   a.先用std::localtime()函数 把 时间戳类对象 转换为 本地时间类对象（std::tm）
		//   b.再用 本地时间类对象（std::tm） 调用 <iomanip>库中的put_time()函数进行格式化打印。
		std::tm* local_time = std::localtime(&time_t_dieline);
		std::cout << "Current time: " << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << std::endl;
	}
}


int main()
{
	// 1. 测试timed_mutex对象的try_lock_for()函数
	{
		std::thread a(testTmtx_tlf);
		std::thread b(testTmtx_tlf);
		a.join();
		b.join(); 
	}

	// 2. 测试timed_mutex对象的try_lock_until()函数
	{
		std::thread a(testTmtx_tlu);
		std::thread b(testTmtx_tlu);
		a.join();
		b.join();
	}
	return 0;
}

// timed_mutex的函数：
// lock()、unlock()、try_lock()
// try_lock_for(): 接受一个"时间段"，表示在这段时限之内线程如果没有获得锁则被阻塞住，超过时限则返回false.
// try_lock_until() : 接受一个"时间点"，表示在这时间点之前……
// 以上两个函数要配合std空间下的chrono命名空间使用：
// // 获取当前时间点：auto now = std::chrono::system_clock::now();
// // 5秒钟：auto lock_duration = std::chrono::seconds(5); 
// // 让线程睡眠5秒：std::this_thread::sleep_for(std::chrono::seconds(3));
// 特性和 std::mutex 大致相同，timed_mutex 比 std::mutex 多了两个成员函数，try_lock_for()，try_lock_until()

// (chrono)计时类的使用：
// std::chrono::seconds(2) : 设置两秒钟。
// std::this_thread::sleep_for(std::chrono::seconds(5)) : 让当前线程休眠5秒。（5秒内啥事不做，硬占着系统资源）
// a. std::chrono::system_clock::now()函数：返回的是时间点类的当前时间点
// b. std::chrono::system_clock::time_point（时间点类）。
// c. 使用 std::chrono::system_clock::to_time_t() 函数将时间点转换为 std::time_t 类型(时间戳类型）
// d. std::ctime()函数 : 将 时间戳类对象 转换为可读的字符串格式（将时间戳转为字符串）。
// e. std::localtime()函数 : 把 时间戳类对象 转换为 本地时间类对象（std::tm）
// f. 再用 本地时间类对象（std::tm） 调用 <iomanip>库中的put_time()函数进行格式化打印。