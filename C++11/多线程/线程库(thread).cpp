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
		cout << 1 << endl;
}
void doop2()
{
	while (2)
		cout << 22 << endl;
}

void foo(string s1) {
	std::cout << s1 << " Thread ID: " << std::this_thread::get_id() << std::endl;
}

int main()
{
	// 0. 理解线程对象的作用 : 并行执行
	{
	//	//当你创建了一个 std::thread 对象并启动了一个线程后，
	//	//这个新线程会与主线程(即main函数)和其他任何线程并行运行。
	//	
	//	//创建两个执行死循环打印的thread对象：
	//	thread t1(doop1);
	//	thread t2(doop2);

	//	//main()主线程也执行打印死循环打印，观察三者是否同时进行
	//	while (3)
	//		cout << 3 << ' ';

	//	/*t1.join();
	//	t2.join();*/

	//	//join():只有执行完t1,t2的线程才会继续往下执行
	//	cout << "complete doop!" << endl;

	//	// 结论：
	//	//	线程类thread的作用：创建线程让函数和主线程（main()函数）一起并行执行。
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

		// a. join() : 等待线程对象完成线程函数，线程函数完成前，
					 //调用了某线程对象join()的线程（如main函数）会阻塞，等待该线程对象完成线程函数才会继续执行。
		// b. joinable() : 判断某线程对象代表的线程是否还在执行。
		// c. get_id() : 获取线程对象的id，返回一个 std::thread::id 类型的对象，这个类型可以用于比较线程ID是否相同。
					   //拓：想要获得函数当前的线程id,可以使用在函数中使用this_thread::get_id()来获取。
					   //用法：判断是不是主线程。
		// d. detach() : 分离线程，将线程与创建它的线程（通常是主线程）分离。
					   //当一个线程被分离后，它的执行将独立于创建它的线程，且其生命周期不再受创建线程的控制。
                       //一旦线程被分离，你就不能再对它调用 join() 或 joinable()。这是因为分离后的线程在其生命周期结束时会自动清理其资源，而不需要你显式地调用 join()。
					   //分离线程后主线程就可以继续执行，而不需要等待子线程完成。
		cout << "=====================2.thread对象的成员函数===================" << endl;
		////a.测试join()
		//thread t1(doop1);
		//thread t2(doop2);
		//t1.join(); 
		//while (3) cout << 33 << endl;
		// 结论：main()函数调用了t1的join()函数，所以会等t1执行完后再执行。

		//b.测试joinable()
		thread t1([](int a)->int {return a; }, 1);
		thread t2([](int a)->int {return a; }, 1);

		while (3)
		{
			if (t1.joinable())
				cout << "t1.joinable() : " << t1.joinable() << ", 线程1还在执行！！！！！" << endl;
			if (t2.joinable())
				cout << "t2.joinable() : " << t2.joinable() << ", 线程2还在执行！！！！！" << endl;
			if (!t1.joinable() && (!t2.joinable()))
			{
				cout << "线程1和2结束执行: " << "t1.joinable() : " << t1.joinable() << ", t2.joinable() : " << t2.joinable()<< endl;
				break;
			}
			t1.join();
			t2.join();
		}
		
	}

	// 3.测试get_id()
	{
		// 线程类thread的get_id()方法返回当前线程的唯一标识符。
		// 普通函数可以使用td::this_thread::get_id()来获取当前线程的唯一标识符。
		cout << "================3.测试get_id()===============" << endl;
		std::thread t1(foo, "T1");
		std::thread t2(foo, "T2");

		std::cout << "Main Thread ID: " << std::this_thread::get_id() << std::endl;
		std::cout << "Thread 1 ID: " << t1.get_id() << std::endl;
		std::cout << "Thread 2 ID: " << t2.get_id() << std::endl;

		t1.join();
		t2.join();
	}

	// 4.测试detach()
	{
		cout << "================4.测试detach()===============" << endl;
		// d. 测试detach() : 分离线程 (可以用来启动匿名thread对象）
		/*thread (doop1).join();
		thread (doop2).join();
		thread ([] {while (3) cout << 333 << endl; }).detach();
		thread ([] {while (4) cout << 4444 << endl; }).detach();*/
		// 结论：匿名对象在创建它的作用域结束时就被销毁了。所以要使用detach()或join()来启动线程。

		// 其实detach()主要是用来分离线程的，让线程的生命周期不再受thread对象的控制。
		// 当你对一个std::thread对象调用detach()方法后，该线程就不再与原始的std::thread对象关联，也就是说，原始的std::thread对象不再管理这个线程的生命周期。
		/*thread t3(doop1);
		t3.detach();*/
		//t3.join(); //报错
		// 现象：不使用detach()分离线程，主程序结束后线程对象还没有结束会报错。（“abort() has been called”崩溃：在这里是因为主线程尝试结束而子线程还在运行，并且由于线程对象没有被join()等待，所以其析构函数会尝试进行所谓的“终止”）
		// 使用detach()分离线程和thread对象后，不报错。
		// 原因：因为此时线程不由thread对象管理，不会造成主程序关闭，thread对象未关闭的情况。
		// 分离的线程也由操作系统来接管。（分离的线程不会随着程序的“正常”关闭而“自动”终止。它们是被操作系统作为进程的一部分而终止的。）

	}

	// 5. 线程函数如何修改实参？
	{
		// 线程函数的参数是以值拷贝的方式拷贝到线程栈空间中的，
		// 因此：即使线程参数为引用类型，在线程中修改后也不能修改外部实参，因为其实际引用的是线程栈中的拷贝，而不是外部实参
		
		// 如果要通过线程函数的形参改变外部的实参（输出型参数），可以参考以下三种方式：
		// 引用传参 + std::ref()函数、 指针、 lambda表达式的捕捉列表

		// 观察0： 线程函数的参数为引用类型时，直接传参会报错
		void modify_1(int& x);
		int a = 0;
		//std::thread t0(modify_1, a); //运行时报错
		// 结论：如果线程函数的参数为引用类型，直接传参会报错
		
		// 观察1： 使用 引用传参 + std::ref()函数 来修改实参
		void modify_1(int& x);
		a = 0;
		std::thread t1(modify_1, ref(a));
		cout << a << endl;
		t1.join();
		cout << a << endl; //线程函数结束后(join()后)才能在主线程中观察到修改，因为线程是并行执行的。
		// 结论1：线程函数的引用类型参数，要用std::ref()函数封装后传递才能正常使用。
		// 结论2：要在线程函数结束后才能在其他线程中看到结果，最好用join()来保证线程结束。

		// 观察2： 使用 指针 来修改实参
		void modify_2(int* x);
		std::thread t2(modify_2, &a); //& :取地址符
		cout << a << endl;
		t2.join();
		cout << a << endl; //线程函数结束后(join()后)才能在主线程中观察到修改
		// 结论：指针参数可以正常修改实参

		// 观察3：lambda表达式的捕捉列表
		std::thread t3([&a]{a = 3; });
		cout << a << endl;
		t3.join();
		cout << a << endl; //线程函数结束后(join()后)才能在主线程中观察到修改
	}
	return 0;
}

void modify_1(int& x) { x = 1; }
void modify_2(int* x) { *x = 2; }