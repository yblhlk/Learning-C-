#include<iostream>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
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
		map<string, double> a;
		map<string, double> b(a); //拷贝构造
		map<string, double> c(b.begin(), b.end());
		map<string, double, comp> d(b.begin(), b.end()); // 传入第三个参数，比较类：要排升序要写一个比较类，并operator()

		map<string, double> e = { {"tomato", 2.15},{"potato", 0.3} }; //创建时赋初值。使用{{}}
		a = c; // operator =
	}

	// 2. 访问 + 插入数据
	{
		cout << "=============================2. 访问==========================" << endl;
		map<string, double> a = { {"tomato", 2.15},{"a", 0.1} };;
		// a. 使用operator []来访问&插入数据（有就覆盖，没有就插入数据）
		a["tomato"] = 2.14;        
		a["potato"] = 0.82;
		a["apple"] = 5.21;
		a["banana"] = 2.81;
		a["apple"] = 5.00; //key相同的数据会覆盖之前的数据（map和set一样会去重+排序）

		// b. 使用at来访问数据 (返回元素的引用）（at必须访问已有数据，访问没有的数据不会创建而且会报错。）
		a["watermelon"] = 0.7;
		a.at("watermelon") = 1.23; 

		// c. 使用insert+pair 来插入一个键值对
		std::pair<string, double> pa("peach", 4.21); 
		a.insert(pa); 
		////或使用make_pair()函数来返回一个键值对
		a.insert(std::make_pair("pear", 3.14)); 
		//打印
		cout << "map a :" << endl;
		for (auto e : a) cout << e.first << " : " << e.second << endl;

		cout << ">>>map<string, double, comp> b(a.begin(), a.end();" << endl;
		cout << "map b :" << endl;
		map<string, double, comp> b(a.begin(), a.end()); //比较方式不同的map不能直接拷贝构造，但可以用迭代器来构造。
		for (auto e : b) cout << e.first << " : " << e.second << endl;

		cout << ">>>map<string, double> c(a);" << endl;
		cout << "map c :" << endl;
		map<string, double> c(a);
		for (auto e : c) cout << e.first << " : " << e.second << endl;
	}

	// 3. 迭代器 iterator
	{
		cout << "=============================3. 迭代器 iterator==========================" << endl;
		map<string, double> a;
		a["tomato"] = 2.14;
		a["potato"] = 0.82;
		a["apple"] = 5.21;
		a["banana"] = 2.81;
		a["apple"] = 5.00; //key相同的数据会覆盖之前的数据（map和set一样会去重+排序）

		cout << "map a :" << endl;
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
		map<string, double> a{ {"potato", 0.8}, {"tomato", 3.12} };
		a["pear"] = 2.5;
		//a.at("watermelon") = 0.9; //at只能用来访问数据
		a.insert(std::make_pair("peach", 5.2));
		a.insert(std::make_pair("watermelon", 0.8));

		//a. 使用迭代器遍历
		map<string, double>::iterator it = a.begin();
		cout << "map a:" << endl;
		while (it != a.end())
		{
			cout << "      " << (*it).first << " : " << (*it).second << "." << endl;
			++it;
		}
		//b. 使用范围for遍历
		cout << "map a:" << endl;
		for(auto e : a)
			cout << "      " << e.first << " : " << e.second << "." << endl;
	}

	//5.capacity operate
	{
		cout << "============================5.capacity operate=========================" << endl;
		// size
		// empty : 根据size来判断
		// clear : 将size = 0
		typedef map<string, double> msd;
		msd a{ {"potato", 0.41}, {"tomato", 4.12} };
		a["apple"] = 1.2;
		a["banana"] = 2.43;
		a.insert(std::make_pair("peach", 5.21));

		cout << "msd a:" << endl;
		for (auto e : a) cout << "     " << e.first << "->" << e.second << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << ">>>a.clear();" << endl; a.clear();
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << "msd a:" << endl;
		for (auto e : a) cout << "     " << e.first << "->" << e.second << endl;
	}

	//6.modify operate
	{
		// insert
		// erase
		// swap
		cout << "==========================6.modify operate=======================" << endl;
		cout << "--------------------------------erase---------------------------" << endl;
		typedef map<string, double> msd;
		msd a = { {"potato", 0.42}, {"tomato", 3.21} };
		a["watermelon"] = 0.9;
		cout << "msd a : " << endl;
		for (auto e : a) cout << "      " << e.first << " : " << e.second << endl;
		cout << ">>>a.erase(\"watermelon\");" << endl; a.erase("watermelon");
		cout << "msd a : " << endl;
		for (auto e : a) cout << "      " << e.first << " : " << e.second << endl;

		cout << "--------------------------------swap---------------------------" << endl;
		msd b;
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