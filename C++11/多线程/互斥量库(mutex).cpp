// 互斥量对象mutex 要配合 线程对象thread 来使用
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

// 1.建立一个全局的互斥量对象（mutex类只有一个无参构造函数，其他的拷贝构造，移动构造，赋值等都没有）
std::mutex mtx;  

// 2.在线程函数中使用mutex对象的lock()和unlock()方法进行加锁和解锁
void print_block(int n, char c) {
	// critical section (关键部分):
	mtx.lock();   // a. 在访问临界资源前加锁
	for (int i = 0; i < n; ++i) { std::cout << c; }
	std::cout << '\n';
	mtx.unlock(); // b. 在结束访问后解锁
}

std::mutex mtx1;
static int shared_num = 0;
void add1AddPrintSnum(std::string s)
{
	while(1)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1)); //让线程暂停一秒钟。
		mtx1.lock();
		shared_num++;
		std::cout << s << "(++shared_num) ==" << shared_num << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << s << shared_num << std::endl;
		mtx1.unlock();
	}
}

// 3.两个线程对象就可以同时访问临界区资源了
int main()
{
	std::thread th1(print_block, 500, '*');
	std::thread th2(print_block, 500, '$');
	th1.join();
	th2.join();

	std::thread t1(add1AddPrintSnum, "t1 : ");
	std::thread t2(add1AddPrintSnum, "t2 : ");
	t1.join();
	t2.join();

	return 0;
}

//使用mutex对象总结：
//1. 创建一个全局的mutex对象(互斥量对象）// std::mutex mtx;
//2. 在访问线程函数的临界区资源时中使用mutex对象的lock()方法进行加锁，unlock()方法进行解锁。
//3. 多个threads对象就可以有序的访问临界区资源了。