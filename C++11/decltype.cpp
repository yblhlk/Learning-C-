#include<iostream>
using namespace std;

//使用decltype()不但能推演表达式的类型，还能演表函数类型/函数指针类型/函数返回值类型
//要用decltype()推演函数指针类型，必须 decltype(&函数名) 变量名，然后用这个变量名接收一个函数指针（即一个函数名）

int add(int a, int b)
{
	return a + b;
}

int main()
{
	//decltype : 将变量声明为表达式类型(推演表达式的类型)
	int a = 1;
	double b = 1.42;
	decltype(a * b) c;
	decltype(&a) d;
	cout << typeid(c).name() << endl; //查看变量类型
	cout << typeid(d).name() << endl;
	cout << typeid(decltype(&b)).name() << endl;

	//decltype还能推演函数&函数返回值的类型 
	decltype(add) e; //函数类型
	decltype(&add) f; //函数指针类型，能当函数指针用**
	decltype(add(1, 1)) g = 1; //函数返回值类型
	f = add; // 将函数赋值给函数指针
	cout << f(1, 3) << endl; //使用函数指针调用函数
	
	cout << typeid(add).name() << endl;
	cout << typeid(decltype(add)).name() << endl;
	cout << typeid(&add).name() << endl;
	cout << typeid(decltype(&add)).name() << endl;
	cout << typeid(add(1, 2)).name() << endl;
	cout << typeid(decltype(add(1, 2))).name() << endl;
	return 0;
}