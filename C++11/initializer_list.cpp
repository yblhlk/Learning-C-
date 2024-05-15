#include<iostream>
#include<initializer_list>

using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;

//initializer_list本质就是一个 {} 括起来的列表

int main()
{
	// 1. C++11后，我们使用{}进行列表初始化可能会创建一个initializer_list<>对象
	auto in = { 1,3,5,7 };
	cout << typeid(in).name() << endl;  //class std::initializer_list<int>

	// 2. std::initializer_list 一般是作为构造函数的参数，
	//C++11后 STL中的大部分容器就增加了 std::initializer_list作为参数的构造函数
	//如string\vector\list\deque\set\map
	//注：C++98并不支持直接用列表对容器进行初始化，这种初始化方式是在C++11引入initializer_list后才支持的

	// 3.只能使用正向迭代器访问initializer_list 
	// 其迭代器的本质就是数组指针，或说initializer_list的本质就是数组。
	cout << *in.begin() << endl;
	cout << *(in.begin()+2) << endl;
	cout << *(in.end()) << endl; //越界，但不报错

	//.size()
	cout << in.size() << endl;
	return 0;
}