#include<iostream>
#include<set> //multiset 也在set中，与set区别在于，只排序，不去重。

using std::cin;
using std::cout;
using std::endl;
using std::multiset;

int main()
{
	//1.构造函数
	{
		cout << "================================1.构造函数===============================" << endl;
		multiset<int> a;   // 构造一个空对象
		multiset<int> b(a); // 拷贝构造

		//使用数组来构造
		int arr[] = { 10,2,9,4,6,6 };
		multiset<int> c(arr, arr + 6);
		cout << ">>>set<int> c(arr, arr+6);" << endl;
		cout << "c.size : " << c.size() << endl;
		for (auto e : c) //set可用迭代器来访问
			cout << e << ' ';

		//可简化成：
		multiset<int> cc{ 1,2,3,4,5,6,17,8,9,1 };
		cout << "\n>>>multiset<int> cc{ 1,2,3,4,5,6,17,8,9,1 };" << endl;
		cout << "cc.size : " << cc.size() << endl;
		for (auto e : cc) //set可用迭代器来访问
			cout << e << ' ';

		//使用迭代器来构造
		multiset<int> d(c.begin(), c.end());
		cout << "\n>>>multiset<int> d(c.begin(), c.end());" << endl;
		cout << "d.size : " << d.size() << endl;
		for (auto e : d)
			cout << e << ' ';
		putchar(10);
	}

	// 2. operator =
	{
		cout << "==============================2. operator =============================" << endl;
		typedef multiset<int> si;
		int arr[] = { 1,3,4,5,7 };
		si a(arr, arr + 5);
		si b;
		b = a;

		cout << "b.size : " << b.size() << endl;
		for (auto e : b)
			cout << e << ' ';
		putchar(10);
	}

	// 3. iterators
	{
		cout << "==============================3. iterators =============================" << endl;
		multiset<int> a{ 1,2,3,4,5,6,7,8,9,10 };
		cout << *a.begin() << endl;
		cout << *(--a.end()) << endl; //只能++ 或 -- 
		cout << *a.rbegin() << endl;
		cout << *(--a.rend()) << endl;
	}

	//4. capacity operate
	{
		cout << "==============================4. cap  acity operate =============================" << endl;
		multiset<int> a{ 1,2,3,1 };
		cout << ">>>multiset<int> a{1,2,3,1};" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << ">>>a.clear(); " << endl;  a.clear();
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
	}

	//5. Object.swap()
	{
		cout << "==============================5. Object.swap() =============================" << endl;
		multiset<int> a;
		multiset<int> b{ 1,2,3 };
		cout << "a.size() : " << a.size() << endl;
		cout << "b.size() : " << b.size() << endl;
		cout << ">>> a.swap(b);" << endl; a.swap(b); //multiset不能和set交换
		cout << "a.size() : " << a.size() << endl;
		cout << "b.size() : " << b.size() << endl;
	}

	//6. Object.find()
	{
		cout << "===============================6. Object.find()==============================" << endl;
		multiset<int> a{ 1,2,3,4,5,6,7,8,9,10 };
		cout << ">>>\nmultiset<int> a{ 1,2,3,4,5,6,7,8,9,10};" << endl;

		multiset<int>::iterator it = a.find(4); //返回查找到的数的迭代器
		cout << *it << endl;

		//set<int>::iterator it = a.rfind(4); //没有内置rfind方法

	}
	return 0;
}