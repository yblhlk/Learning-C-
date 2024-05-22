#include<iostream>
#include<functional> //std::function/std::bind
using namespace std;

template<typename F>
void useFunction(F f)
{
	static int i = 0;
	cout << "函数模板调用次数：" << ++i << endl;
	cout << "函数模板中静态变量的地址" << &i << endl;
}


double add(int a, int b) 
{ 
	cout << a << ' ' << b << endl;
	return a+b;
}

class Add
{
public:
	double operator()(int a, int b)
	{
		cout << a << ' ' << b << endl;
		return a + b;
	}
	double add(int a, int b)
	{
		cout << a << ' ' << b << endl;
		return a + b;
	}

	static double staticAdd(int a, int b)
	{
		cout << a << ' ' << b << endl;
		return a + b;
	}
};

int main()
{
	// 1. 使用bind包装器
	{
		cout << "===================== 1. 使用bind包装器===================" << endl;
		auto f1 = std::bind(add, 1, 2);
		cout << f1() << endl;
		auto f2 = std::bind(Add(), 1, 2);
		cout << f2() << endl;
		auto f3 = std::bind([](int a, int b)->double {
			cout << a << ' ' << b << endl;
			return a + b; }, 3, 4);
		cout << f3() << endl;

		//包装成员函数
		cout << "-------------------包装成员函数----------------" << endl;
		// 普通成员函数：普通成员函数必须要取地址 和 传入一个对象
		auto f4 = bind(&Add::add,Add(), 2, 4);
		f4();
		//报错1：普通成员函数必须要取地址 和 传入一个对象
		//auto f4 = bind(Add::add, 2, 4);

		//静态成员函数 : 可以当普通函数使用
		auto f5 = bind(Add::staticAdd, 3, 6);
		f5();
		auto f6 = bind(&Add::staticAdd, 4, 6); //不能传入对象，因为静态成员函数没有this指针。
		f6();
		

		// bind包装器并不具有统一可调用对象的作用
		cout << "-------------------bind包装器并不具有统一可调用对象的作用----------------" << endl;
		useFunction(f1);
		useFunction(f2);
		useFunction(f3);
	}

	// 2. bind的作用
	{
		cout << "===================== 2. bind的作用===================" << endl;
		// 作用一：封装一个函数，将函数的某些参数绑定为固定的值，让我们在调用时可以不用传递某些参数。
		auto b1 = std::bind(add, 1, 2);
		b1();
		b1(2, 3);

		// 作用二：调整传参顺序
		// 调用bind的一般形式：auto f = bind(add,arg_list)
		// arg_list中的参数可能包含形如 _n的名字，其中n是一个整数，这些参数是“占位符”，表示 f的参数，它们占据了传递给add的参数的 “位置”。
		// placeholders_1 是一个占位符，placeholders其实是一个命名空间
		// 以下表示将b2的第二个和第一个参数传给add的第一个和第二个参数。
		auto b2 = std::bind(add, placeholders::_2, placeholders::_1);
		b2(3, 4);
		return 0;
	}
}

///** 2.bind包装器：
//* 使用 bind包装器需要包含头文件：#include <functional>
//* sauto f = bind(add,arg_list)//arg_list是参数列表或占位符。
//* 
//* 作用：
//* *封装一个函数，将函数的某些参数绑定为固定的值，让我们在调用时可以不用传递某些参数。
//* *调整传参顺序
//*/ 