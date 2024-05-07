#include<iostream>
using std::cin;
using std::cout;
using std::endl;

//仿函数是 STL 的六大组件之一
//仿函数的实现就是在类中重载 () 操作符，使得该类的对象可以被当作函数来调用。
// 这些对象就叫做仿函数（Functors）或函数对象（Function Objects）


// 命名规范：类名用大驼峰，函数名、变量名用小驼峰，全局变量常量用全大写。
class FunctorGreaterCompare
{
public: 
	bool operator() (int a, int b)
	{
		return a > b;
	}
};

//仿函数支持泛型
template<class T>
class FunctorLessCompare
{
public:
	bool operator()(T a, T b)
	{
		return a < b;
	}
};

//练习写一个算法仿函数，实现pow和sqrt
template<typename Iterator>
class FunctorAlgorithmPow
{
public: // class 默认为私有
	Iterator operator() (Iterator x)
	{
		return x * x;
	}
};

template<typename T4>
class FunctorAlgorithmSqrt
{
public:
	double operator() (T4 x)
	{
		double r = -10000000, l = 10000000, mid;
		while (l - r >= 1e-4)
		{
			mid = (r + l) / 2;
			if (mid * mid < x)
				r = mid;
			else if (mid * mid > x)
				l = mid;
			else
				return mid;
			
		}
		return l;
	}
};


int main()
{
	FunctorGreaterCompare fgc;
	cout << fgc(1, 2) << endl;

	FunctorLessCompare<int> iflc;
	cout << iflc(1, 2) << endl;
	
	FunctorLessCompare<double> dflc1;
	cout << dflc1(11, 2) << endl;

	FunctorAlgorithmPow<double> fap;
	cout << fap(2.0) << endl;

	FunctorAlgorithmSqrt<double> fas;
	cout << fas(4) << endl;
	return 0;
}