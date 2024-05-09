#include<iostream>
using std::cin;
using std::cout;
using std::endl;

// 回顾：
//1.函数模板
template<typename T>
int add(T a, T b)
{
	return a + b;
}

//2.类模板
template<typename T>
class Student
{
public:
	Student(std::string name= "J", size_t age = 0)
		:_name("W")
		,_age(23)
	{}
	void toString()
	{
		cout << "Student { _naem : " << _name << ", _age : " << _age << " } " << endl;
	}
	T setAge(T a)
	{
		_age = a;
		return _age;
	}
private:
	std::string _name;
	size_t _age;
};

//一、非类型模板参数
// 1. 浮点数、类对象以及字符串是不允许作为非类型模板参数的。
// 2. 无法使用变量传给非类型模板参数
template<class T1, size_t N>
class Array
{
public:
	void arr0(T1 a)
	{
		arr[0] = a;
	}
	T1 print0()
	{
		cout << "capacity : " << N << endl;
		cout << "arr[0] : " << arr[0] << endl;
		return arr[0];
	}
private:
	T1 arr[N];
};


//二、模板的特化
// 1.函数模板特化
// 函数模板
template<class T1, class T2>
void tf(T1 a, T2 b)
{
	cout << "函数模板 T1 tf(T1 a, T2 b)" << endl;
}
template<>
// 函数模板全特化
void tf(int a, double b)
{
	cout << "函数模板全特化：int tf(int a, double b)" << endl;
}
template<>
void tf(double a, double b)
{
	cout << "函数模板全特化：double tf(double a , double b)" << endl;
}
// 函数模板部分特化？ 函数重载？ （看编译器的提示好像是函数重载）
template<typename T1>
void tf(T1 a, double b)
{
	cout << "函数模板的重载：int tf(T1 , double b)" << endl;
}
//函数模板没有部分特化，因为函数有重载机制，函数并不需要偏特化，只要重载一个模板就可以实现偏特化的效果。


// 2.类模板特化
template<typename T1, class T2>
class A
{
public:
	void print()
	{
		cout << "类模板：class A" << endl;
	}
};
// 2.1全特化
template<>
class A<int, int>
{
public:
	void print()
	{
		cout << "类全特化：class A<int, int>" << endl;
	}
};
// 2.2 部分特化
template<class T1>
class A<char, T1>
{
public:
	void print()
	{
		cout << "类部分特化：class A<char, T1>" << endl;
	}
};
// 2.3 偏特化
// a.偏特化为指针类型
template<class T1, class T2>
class A<T1*, T2*>
{
public:
	void print()
	{
		cout << "偏特化为指针类型：class A<T1*, T2*>" << endl;
	}
};
//b.偏特化为引用类型
template<class T1, class T2>
class A<T1&, T2&>
{
public:
	void print()
	{
		cout << "偏特化为引用类型：class A<T1&, T2&>" << endl;
	}
};


int main()
{
	//回顾：函数模板 & 类模板
	{
		cout << "--------------------回顾：函数模板 & 类模板--------------------" << endl;
		// 函数模板
		int a = 1, b = 2;
		cout << add(a, b) << endl;
		Student<int> s1("wyl", 23);

		// 类模板
		s1.setAge(a);
		Student<int>* s2 = new Student<int>(s1);
		s1.toString();
		s2->toString();
	}

	//非类型模板参数
	{
		cout << "----------------------------非类型模板参数----------------------------" << endl;
		int a = 1;
		Array<int, 10> arr1;
		arr1.arr0(a);
		arr1.print0();
	}

	// 函数模板特化
	{
		cout << "-------------------------------函数模板特化--------------------------------" << endl;
		// 1. 函数模板特化
		int a = 1, b = 2;
		double c = 1;

		cout << endl << "tf<char>(a, 1);";
		tf<char>(a, 1); // 函数模板 T1 tf(T1 a, T2 b)

		cout << endl << "tf((int)a, 1.0);";
		tf((int)a, 1.0);         // 模板特化：int tf(T1 , double b)
		cout << endl << "tf<int, double>(a, 1.0);";
		tf<int, double>(a, 1.0); // 模板特化：int tf(int a, double b)
		cout << endl << "tf(1.0, 2.0);";
		tf(1.0, 2.0);            // 模板特化：int tf(T1 , double b)
		cout << endl << "tf<double, double>(1.0, 2.0);";
		tf<double, double>(1.0, 2.0);     //模板特化：double tf(double a, double b)

		//函数模板的部分特化和全特化存在优先级的不确定性，所以推荐只使用函数模板的全特化。
	}

	// 类模板特化
	{
		cout << "-------------------------------类模板特化--------------------------------" << endl;
		A<double,char> a;
		a.print();
		// 2.1全特化
		A<int, int> b;
		b.print();
		// 2.2 部分特化
		A<char, int> c;
		c.print();
		// 2.3 偏特化
		// a.偏特化为指针类型
		A<int*, int*> d;
		d.print();
		//b.偏特化为引用类型
		A<int&, int&> e;
		e.print();
	}
	return 0;
}

//函数模板虽然能部分特化，但还是不推荐使用，因为函数模板的模板参数是由编译器来推衍的
//类模板可以使用部分特化的原因是类模板的模板参数是由我们传入的