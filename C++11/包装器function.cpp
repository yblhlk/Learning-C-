#include<functional> //std::function\std::bind
#include<iostream>
using namespace std;
// 功能相同的函数指针、仿函数、lambda表达式是不同的类型
// 甚至功能相同的lambda表达式也是不同的类型
// 有没有办法统一它们的类型？
// 为此C++11引入了包装器的概念。

/** 1.function包装器：
* std::function，它是一个通用的、类型安全的、可调用的对象包装器，(实际上是一个类模板)
* 它允许你将任何可调用的目标（如函数、仿函数、lambda表达式、成员函数指针等）
* 存储为std::function对象。
* 
* 使用 function包装器需要包含头文件：#include <functional>
* std::function<Ret(Arg...)> 对象名 = 函数/仿函数/lambda表达式/成员函数指针等
* 
* 作用：
* *将可调用对象的类型进行统一，便于管理。
* *包装后明确了可调用对象的返回值和形参类型，更加方便使用者使用。
*/ 

template<typename Fun, class P>
void usefunction(Fun func, P parameter)
{
	static int i = 0;
	cout << "usefunction函数调用次数：" << ++i << endl;
	cout << "静态变量的地址：" << &i << endl;
	func(parameter);
}
// 普通函数
int testFunction(int a)
{
	return a;
}
// 仿函数
class TestFunctor
{
public:
	int operator()(int a) { return a; }
	int testMemberFunctor(int a) { return a; }
	static int testMemberFunctor1(int a) { return a; }
};

int main()
{
	// 1.function包装器（在<functional>下）
	{
		cout << "============================1.function包装器========================" << endl;
		cout << "-----------------------不使用function包装器---------------------" << endl;
		usefunction(testFunction, 1);
		usefunction(TestFunctor(), 1);
		usefunction([](int a)->int {return a; }, 1);
		// 可以发现尽管使用的功能相同的函数、仿函数、lambda表达式，但usefunction函数模板仍是生成了三个函数。
		// 这时就可以用function包装器分别对着三个可调用对象进行包装，
		// 然后再用这三个包装后的可调用对象来调用useF函数，这时就只会实例化出一份useF函数。
		
		cout << "-----------------------使用function包装器---------------------" << endl;
		std::function<int(int)> f1 = testFunction;
		std::function<int(int)> f2 = TestFunctor();
		std::function<int(int)> f3 = [](int a)->int {return a; };
		// 还可以写成：
		std::function<int(int)> f11(testFunction);
		std::function<int(int)> f22(TestFunctor());
		std::function<int(int)> f33([](int a)->int {return a; });
		//因为std::function<Ret(Arg...)> 是个类模板类。可使用（）或=来调用构造函数
		usefunction(f1, 1);
		usefunction(f2, 1);
		usefunction(f3, 1);
		// 使用function包装器将作用相同的函数、仿函数、lambda表达式包装，使其类型统一。
		
		//包装成员函数
		cout << "-----------------------包装成员函数---------------------" << endl;
		// 类普通成员函数：
			//对于类普通成员函数，必须进行&，没有直接报错
			//参数列表还需要加上一个参数：类名，这个参数代表的是 this指针
			//this指针不能显示去传，所以需要用类名替代
		std::function<int(TestFunctor, int)> f4(&TestFunctor::testMemberFunctor);
		f4(TestFunctor(), 1);
			// 报错1：非标准语法；请使用 "&" 来创建指向成员的指针
			//std::function<int(TestFunctor, int)> f5(TestFunctor::testMemberFunctor);
			// 报错2：调用的时候必须要传多一个匿名对象，不传直接报错
			//f4(1); 
		
		// 静态成员函数：可以像普通那样调用，不需要传对象
			// &有没有都行，但是普通成员函数必须有
		std::function<int(int)> f6(&TestFunctor::testMemberFunctor1);
		std::function<int(int)> f7(TestFunctor::testMemberFunctor1);
		usefunction(f6, 1);
		usefunction(f7, 1);
	}
	return 0;
}