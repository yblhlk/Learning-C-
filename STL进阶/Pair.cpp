#include<iostream>
#include<string>
#include<utility>  // std::pair, std::make_pair
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::pair;



int main()
{
	// 1.构造函数
	{
		cout << "===============================1.构造函数==========================" << endl;
		pair<string, double> a;    // default constructor
		pair<string, double> b(a); // copy constructor
		pair<string, double> c("tomato", 2.15); 

		cout << a.first << " : " << a.second << "。\n";
		a.first = "potato";
		a.second = 1.23;
		cout << a.first << " : " << a.second << "。\n";
	}

	//2.初始化
	{
		// 使用typedef重命名后直接初始化
		typedef pair<string, double> psd;
		psd a("tomato", 2.15);

		// 使用std::make_pair()
		psd b;
		b = std::make_pair("potato", 1.14);
	}

	//3.访问
	{
		cout << "===========================3.访问========================" << endl;
		//pair是一个用 struct 定义的类模板，访问权限为public，可以直接访问其属性：
		//a. 使用first属性保存其键，second属性保存其值。
		pair<int, double> a(1, 1.2);
		cout << ">>>pair<int, double> a(1, 1.2);" << endl;
		cout << "a.first: " << a.first << ", a.second: " << a.second << endl;

		//b. 使用std::get<0>()来获取其键，std::get<1>来获取其值
		std::get<0>(a) = 2;
		std::get<1>(a) = 2.3;
		cout << ">>> std::get<0>(a) = 2;\n";
		cout << ">>> std::get<1>(a) = 2.3;\n";
		cout << "std::get<0>(a): " << std::get<0>(a) << ", std::get<1>(a): " << std::get<1>(a) << endl;
		cout << "a.first: " << a.first << ", a.second: " << a.second << endl;
	}

	//4.和vector一起使用，形成键值对数组。
	{
		cout << "===========================4.和vector一起使用，形成键值对数组。========================" << endl;
		typedef pair<string, double> psd;
		std::vector<psd> a;
		a.push_back(std::make_pair("potato", 1.14));
		a.push_back(std::make_pair("tomato", 2.24));

		for (int i = 0; i < a.size(); i++)
		{
			cout << a[i].first << " : " << a[i].second << ";" << endl;
		}
	}

	return 0;
}