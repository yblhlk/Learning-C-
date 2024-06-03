#include<thread> //要使用标准库中的线程，必须包含 <thread> 头文件
#include<iostream>
using namespace std;

int add(int a, int b) 
{
	cout << "线程3" << endl;
	return a + b;
}

int main()
{
	// 1.构造函数 和 operator =
	{
		// a. 无参构造 ：thread t1;
		// b. 移动构造 : thread t2([]{});
		// c. 移动赋值 : t1 = thread([]{});
		// 注意thread类的拷贝构造和拷贝赋值都已经被删除。

		cout << "=====================1.构造函数===================" << endl;
		thread t1; //线程对象没有关联任何线程函数，即没有启动任何线程。
		thread t2([] {cout << "线程1" << endl; }); //移动构造函数
		t2.join();
		cout << t2.get_id() << " : 等待成功" << endl;
		// thread t3(t2); 
		// 报错，无法调用已经删除的函数
		// 结论 ： thread类 禁止调用拷贝构造，拷贝构造函数已经被删除。

		t2 = thread([](int a) {cout << "线程2" << endl; }, 2); //看文档可知拷贝赋值也被删除了，这里是移动赋值。
		t2.join();
		cout << t2.get_id() << " : 等待成功" << endl;

		t2 = thread(add, 1, 2);
		t2.join(); 
		cout << t2.get_id() << " : 等待成功" << endl;
		// 现象：已经关联线程函数的thread对象直接用移动赋值切换线程会报错，要使用jion()等待后才可以切换线程。
		// 结论：一旦一个std::thread对象已经关联了一个正在执行或可加入的线程（即该对象已经被一个构造函数成功初始化），就不能再使用赋值操作符给它分配一个新的线程。
	}
	return 0;
}
