#include<thread> //要使用标准库中的线程，必须包含 <thread> 头文件
#include<iostream>
using namespace std;

int add(int a, int b) 
{
	cout << "线程3" << endl;
	return a + b;
}

void doop1()
{
	while (1)
		cout << 1 << ' ';
}
void doop2()
{
	while (2)
		cout << 2 << ' ';
}

int main()
{
	// 0. 理解线程对象的作用 : 并行执行
	{
		//当你创建了一个 std::thread 对象并启动了一个线程后，
		//这个新线程会与主线程(即main函数)和其他任何线程并行运行。
		
		//创建两个执行死循环打印的thread对象：
		thread t1(doop1);
		thread t2(doop2);

		//main()主线程也执行打印死循环打印，观察三者是否同时进行
		while (3)
			cout << 3 << ' ';

		/*t1.join();
		t2.join();*/

		//join():只有执行完t1,t2的线程才会继续往下执行
		cout << "complete doop!" << endl;
	}

	// 1.构造函数 和 operator =
	{
		// a. 无参构造 ：thread t1;
		// b. 移动构造 ：thread t2(add); //执行add函数的线程对象
		//             : thread t3([]{});
		// c. 移动赋值 : t1 = thread([]{});
		// 注意thread类的拷贝构造和拷贝赋值都已经被删除。

		cout << "=====================1.构造函数===================" << endl;
		thread t1; //线程对象没有关联任何线程函数，即没有启动任何线程。
		thread t2([] {cout << "线程1" << endl; }); //移动构造函数
		t2.join();
		cout << t2.get_id() << " : 等待成功" << endl;
		// t1 = t2;
		// 报错，无法调用已经删除的函数
		// thread t3(t2); 
		// 报错，无法调用已经删除的函数
		// 结论 ： thread类 禁止调用拷贝构造和拷贝赋值，拷贝构造和拷贝赋值函数已经被删除。

		t2 = thread([](int a) {cout << "线程2" << endl; }, 2); //看文档可知拷贝赋值也被删除了，这里是移动赋值。
		t2.join();
		cout << t2.get_id() << " : 等待成功" << endl;

		t2 = thread(add, 1, 2);
		t2.join(); 
		cout << t2.get_id() << " : 等待成功" << endl;
		// 现象：已经关联线程函数的thread对象直接用移动赋值切换线程会报错，要使用jion()等待后才可以切换线程。
		// 结论：一旦一个std::thread对象已经关联了一个正在执行或可加入的线程（即该对象已经被一个构造函数成功初始化），就不能再使用赋值操作符给它分配一个新的线程。
	}

	// 2.thread对象的成员函数
	{
		// a. .join() : 等待线程对象完成线程函数，线程函数完成前，调用了join()的主线程（如main函数）会阻塞，等待线程对象完成线程函数。
	}
	return 0;
}
