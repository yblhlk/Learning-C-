#include<iostream>
#include<unordered_set>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_set;

//特殊之处在于unordered_set没有反向迭代器。
//且unordered_set中的元素不可修改。
//所以unordered_set中的适合用来保存只查不改的数据，因为他的底层是哈希表，读取速度快。

// set 会排序+去重
// multi_set 会排序，但不去重
// unordered_set 只会去重，不排序

// set系列只能用迭代器来访问，且其迭代器只能++和--

int main()
{
	//1.构造器
	{
		cout << "=============================1.构造器===========================" << endl;
		unordered_set<int> a;
		unordered_set<int> b(a);
		unordered_set<int> c(b.begin(), b.end());

		int arr[] = { 1,2,3,4,5 , 5,5,5}; //unordered_set 只会去重，不排序
		unordered_set<int> d(arr, arr + 5);
		//可简写为：
		unordered_set<int> e = { 1,2,3,4,5 };
		//或：
		unordered_set<int> f{ 1,2,3,4,5 };
		cout << d.size() << e.size() << f.size() << endl;
		
		//operator =
		a = f;
	}

	//2. Iterator & 访问(只能用迭代器访问)
	{
		cout << "===========================2. Iterator & 访问(只能用迭代器访问)========================" << endl;
		unordered_set<int> a{ 1,2,3,4,5 };
		cout << ">>>unordered_set<int> a{1,2,3,4,5};" << endl;
		cout << "(*a.begin()) : " << (*a.begin()) << endl;
		cout << "(*--a.end()) : " << (*--a.end()) << endl;
		//cout << "(*a.rbegin()) : " << (*a.rbegin()) << endl; //没有反向迭代器。
	}

	//3.遍历
	{
		cout << "================================3.遍历=============================" << endl;
		unordered_set<int> a{ 6,8,1,2,3,4,5,5 }; //只去重，不排序
		cout << ">>>unordered_set<int> a{ 6,8,1,2,3,4,5,5 };" << endl;
		cout << "使用迭代器遍历unordered_set<int> a:" << endl;
		for (unordered_set<int>::iterator it = a.begin(); it != a.end(); ++it)
			cout << (*it)  << ' ';
		putchar(10);

		cout << "使用范围for遍历unordered_set<int> a:" << endl;
		for (auto e : a)
			cout << e << ' ';
		putchar(10);
	}

	//4.capacity operate
	{
		cout << "=============================4.capacity operate========================" << endl;
		//.size();
		//.empty();  判断size是否为0
		//.clear();  将size置为0
		//.swap();

		typedef unordered_set<int> useti;
		useti a{ 10,1,2,3,4,5,6,6 };
		cout << ">>>useti a{10,1,2,3,4,5,6,7};" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << ">>>a.clear();" << endl; a.clear();
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;

		unordered_set<int> b{ 1,2,3,4,5,6 };
		cout << ">>> unordered_set<int> b{ 1,2,3,4,5,6 };" << endl;
		cout << "useti a { "; for (auto e : a) cout << e << " "; cout << " }; ";
		cout << "a.size() : " << a.size() << endl;
		cout << "useti b { "; for (auto e1 : b) cout << e1 << " "; cout << " }; ";
		cout << "b.size() : " << b.size() << endl;
		cout << ">>>a.swap(b);" << endl; a.swap(b);
		cout << "useti a { "; for (auto e : a) cout << e << " "; cout << " }; ";
		cout << "a.size() : " << a.size() << endl;
		cout << "useti b { "; for (auto e1 : b) cout << e1 << " "; cout << " }; ";
		cout << "b.size() : " << b.size() << endl;
	}

	//5.find()
	{
		cout << "===========================5.find()=========================" << endl;
		unordered_set<int> a{ 1,2,3,4,5,6,7 };
		cout << ">>> unordered_set<int> a{1,2,3,4,5,6,7};" << endl;
		cout << "*a.find(4) : " << *a.find(4) << endl;
	}
}