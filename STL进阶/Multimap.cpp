#include<iostream>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::map;      // 排序 + 去重
using std::multimap; // 只排序，不去重
using std::string;

class comp
{
public:
	bool operator()(const string& a, const string& b) const
	{
		return a > b;
	}
};

int main()
{
	// 1. 构造函数
	{
		multimap<string, double> a;
		multimap<string, double> b(a); //拷贝构造
		multimap<string, double> c(b.begin(), b.end());
		multimap<string, double, comp> d(b.begin(), b.end()); // 传入第三个参数，比较类：要排升序要写一个比较类，并operator()

		multimap<string, double> e = { {"tomato", 2.15},{"potato", 0.3} }; //创建时赋初值。使用{{}}
		a = c; // operator =
	}

	// 2. 访问 + 插入数据
	{
		//multimap中没有  operator[] 和 .at()，因为 multimap 的 Key 可能不唯一

		cout << "=============================2. 访问==========================" << endl;
		multimap<string, double> a = { {"tomato", 2.15},{"a", 0.1} };
		

		// a. 使用insert+pair 来插入一个键值对
		std::pair<string, double> pa("peach", 4.21);
		a.insert(pa);
		////或使用make_pair()函数来返回一个键值对
		a.insert(std::make_pair("pear", 3.14));
		
		//打印
		cout << "multimap a :" << endl;
		for (auto e : a) cout << e.first << " : " << e.second << endl;

		cout << ">>>map<string, double, comp> b(a.begin(), a.end();" << endl;
		cout << "multimap b :" << endl;
		multimap<string, double, comp> b(a.begin(), a.end()); //比较方式不同的map不能直接拷贝构造，但可以用迭代器来构造。
		for (auto e : b) cout << e.first << " : " << e.second << endl;

		cout << ">>>map<string, double> c(a);" << endl;
		cout << "multimap c :" << endl;
		multimap<string, double> c(a);
		for (auto e : c) cout << e.first << " : " << e.second << endl;
	}

	// 3. 迭代器 iterator
	{
		cout << "=============================3. 迭代器 iterator==========================" << endl;
		multimap<string, double> a = { {"tomato", 2.15},{"potato", 0.43} };
		// a["tomato"] = 2.14;  // multimap不支持 operator[] 因为键可能会重复
		//在multimap中key相同的数据不会覆盖之前的数据，而是增加一个键值对
		a.insert(std::make_pair("tomato", 3.41));

		cout << "multimap a :" << endl;
		for (auto e : a) cout << "       " << e.first << " : " << e.second << endl;

		// map会排序+去重，所以begin()返回的是排序后的第一个元素的迭代器。
		cout << "a.begin() -> " << (*a.begin()).first << " : " << (*a.begin()).second << endl;
		cout << "--a.end() -> " << (*--a.end()).first << " : " << (*--a.end()).second << endl;
		cout << "a.rbegin() -> " << (*a.rbegin()).first << " : " << (*a.rbegin()).second << endl;
		cout << "--a.rend() -> " << (*--a.rend()).first << " : " << (*--a.rend()).second << endl;

	}

	// 4.遍历
	{
		cout << "============================4.遍历===========================" << endl;
		multimap<string, double> a{ {"potato", 0.8}, {"tomato", 3.12} };
		//a.at("watermelon") = 0.9; //at只能用来访问数据
		a.insert(std::make_pair("peach", 5.2));
		a.insert(std::make_pair("watermelon", 0.8));
		a.insert(std::make_pair("tomato", 4.12));
		a.insert(std::make_pair("potato", 1.21));

		//a. 使用迭代器遍历
		multimap<string, double>::iterator it = a.begin();
		cout << "multimap a:" << endl;
		while (it != a.end())
		{
			cout << "      " << (*it).first << " : " << (*it).second << "." << endl;
			++it;
		}
		//b. 使用范围for遍历
		cout << "multimap a:" << endl;
		for (auto e : a)
			cout << "      " << e.first << " : " << e.second << "." << endl;
	}

	//5.capacity operate
	{
		cout << "============================5.capacity operate=========================" << endl;
		// size
		// empty : 根据size来判断
		// clear : 将size = 0
		typedef multimap<string, double> mmsd;
		mmsd a{ {"potato", 0.41}, {"tomato", 4.12} };
		a.insert(std::make_pair("apple", 4.26));
		a.insert(std::make_pair("banana", 2.59));
		a.insert(std::make_pair("peach", 5.21));
		a.insert(std::make_pair("apple", 6.26));

		cout << "mmsd a:" << endl;
		for (auto e : a) cout << "     " << e.first << "->" << e.second << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << ">>>a.clear();" << endl; a.clear();
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << "mmsd a:" << endl;
		for (auto e : a) cout << "     " << e.first << "->" << e.second << endl;
	}

	//6.modify operate
	{
		// insert
		// erase : 删掉所有键匹配的键值对
		// swap
		cout << "==========================6.modify operate=======================" << endl;
		cout << "--------------------------------erase---------------------------" << endl;
		typedef multimap<string, double> mmsd;
		mmsd a = { {"potato", 0.42}, {"tomato", 3.21} };
		a.insert(std::make_pair("watermelon", 0.63));
		a.insert(std::make_pair("watermelon", 0.83));
		cout << "mmsd a : " << endl;
		for (auto e : a) cout << "      " << e.first << " : " << e.second << endl;
		cout << ">>>a.erase(\"watermelon\");" << endl; a.erase("watermelon"); //删掉所有键匹配的键值对
		cout << "mmsd a : " << endl;
		for (auto e : a) cout << "      " << e.first << " : " << e.second << endl;

		cout << "--------------------------------swap---------------------------" << endl;
		mmsd b;
		cout << "msd a.size() : " << a.size() << endl;
		for (auto e : a) cout << "      " << e.first << " : " << e.second << endl;
		cout << "msd b.size() : " << b.size() << endl;
		for (auto e : b) cout << "      " << e.first << " : " << e.second << endl;
		cout << ">>> b.swap(a);" << endl;  b.swap(a);
		cout << "msd a.size() : " << a.size() << endl;
		for (auto e : a) cout << "      " << e.first << " : " << e.second << endl;
		cout << "msd b.size() : " << b.size() << endl;
		for (auto e : b) cout << "      " << e.first << " : " << e.second << endl;
	}
	return 0;
}