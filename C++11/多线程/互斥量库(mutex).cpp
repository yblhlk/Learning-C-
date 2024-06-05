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

// 使用try_lock():
std::mutex mtx2;
static int num = 0;
void print1to10000(std::string str)
{
	for (; num <= 10000; )
	{
		bool flag = mtx2.try_lock();
		if (flag)
		{
			//mtx2.lock();
			num++;
			std::cout << "flag : " << flag <<  str << num << std::endl;
			mtx2.unlock();
		}
		else
		{
			std::cout << "flag : " << flag << str << "，临界区资源正在被其他线程访问" << std::endl;
		}
	}
}

// 3.两个线程对象就可以同时访问临界区资源了
int main()
{
	// a. 试验lock() 和 unlock()
	std::thread th1(print_block, 500, '*');
	std::thread th2(print_block, 500, '$');
	th1.join();
	th2.join();

	//std::thread t1(add1AddPrintSnum, "t1 : ");
	//std::thread t2(add1AddPrintSnum, "t2 : ");
	//t1.join();
	//t2.join();

	// b. 试验try_lock()
	// 如果临界区资源正在被访问，则try_lock()返回false不阻塞调用他的线程；如果临界区资源无人访问则返回ture并上锁。
	// try_lock()函数返回一个布尔值，如果成功锁定了互斥量，则返回true，否则返回false。由于它不会阻塞当前线程，因此它通常用于那些不希望因为等待互斥量而变得不可用的场景。
	std::thread t3(print1to10000, ", t3 : ");
	std::thread t4(print1to10000, ",  t4 : ");
	std::thread t5(print1to10000, ",   t5 : ");
	std::thread t6(print1to10000, ",    t6 : ");
	std::cout << "try_lock不会阻塞线程。" << std::endl;

	t3.join();
	t4.join();
	t5.join();
	t6.join();
	return 0;
}

//使用mutex对象总结：
//1. 创建一个全局的mutex对象(互斥量对象）// std::mutex mtx;
//2. 在访问线程函数的临界区资源时中使用mutex对象的lock()方法进行加锁，unlock()方法进行解锁。
//3. 多个threads对象就可以有序的访问临界区资源了。


//a.lock()：该函数用于锁定互斥量（mutex）。
        // 当调用lock()时，如果互斥量当前未被其他线程锁定，则当前线程将成功锁定它并继续执行后续代码。
		// 然而，如果互斥量已经被其他线程锁定，那么调用lock()的线程将被阻塞，直到互斥量变得可用（即被其他线程解锁）。
//b.try_lock()：该函数 尝试 锁定互斥量（mutex）。
        // 但如果不成功（即互斥量已经被另一个线程锁定），则不会阻塞当前线程，而是立即返回false。
        // 如果互斥量当前未被其他线程锁定，则当前线程将成功锁定它并继续执行后续代码。