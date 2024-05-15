#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>

using std::cin;
using std::cout;
using std::endl;

// 列表初始化的第一个作用：同一初始化语法
// 在C++98中，标准允许使用花括号 {} 对数组或者结构体元素进行统一的列表初始值设定
// C++11后统一了初始化语法：
// 列表初始化——C++11扩大了用大括号括起的列表(初始化列表)的使用范围，使其可用于所有的内置类型和用户自定义的类型。

//列表初始化的第二个作用：禁止缩窄(即禁止隐式类型转换，编译阶段会报错）

struct Student
{
	size_t _age;
	int _num;
};

class Teacher
{
public:
	Teacher(size_t age = 40, int num = 100)
		:_age(32)
		, _num(1)
	{
		_age = age;
		_num = num;
	}
private:
	size_t _age;
	int _num;
};

int main()
{
	//在C++98中，标准允许使用花括号 {} 对数组或者结构体进行初始化
	{
		int i = { 1 };
		int arr[] = { 1,2,3,4 };

		Student s = { 1,2 };
		Student srr[] = { {1,1},{2,2},{3,3} };
	}

	//C++11扩大了用大括号括起的列表(初始化列表)的使用范围，使其可用于所有的内置类型和用户自定义的类型
	//使用初始化列表时，可添加等号(=)，也可不添加
	{
		int i{ 2 };//可加=也可不用=
		int arr[]{ 1,2,3,4 };

		Student s{ 1,2 };
		Student srr[]{ {1,1},{2,2},{3,3} };

		//C++11后支持使用初始化列表来初始化对象（会调用符合的构造函数)，没有默认的initializer_list构造函数
		Teacher t{ 1,2 };
		Teacher t1 = { 2,2 };
		Teacher trr[]{ {1,1},{2,2},{3,3} };

		//new
		Student* s1 = new Student{ 1,1 };
		Student* srr1 = new Student[]{ {1,1},{2,2},{3,3} };

		//STL (不过这里的原理和上面不同，这里是因为有initializer_list的构造函数。
		std::string str = { 'a','b','c' };
		std::string str1{ 'a','b','c' };
		cout << str << ' ' << str << endl;
		std::vector<int> v = { 1,2,3,4,5 };
		std::vector<int> v1{ 1,2,3,4 };
		std::list<int> l = { 1,2,3,4,5,6 };
		std::list<int> l1{ 1,2,3,4 }; 
		std::deque<int> d = { 1,2,3,4 };
		std::deque<int> d1{ 1,2,3,4,5,6 };
		std::set<int> se = { 1,2,3,4,5 };
		std::set<int> se { 1,2,3,4,5 };
		std::map <std::string, double> m = { {"baby_cabbage", 1.0} };
		std::map <std::string, double> m1 { {"cucumber", 1.0} };

	}

	// 列表初始化的另一个重要作用是：禁止缩窄。(即禁止隐式类型转换，编译阶段会报错）
	{
		int i = 123456789;
		//char c{ i }; //报错，列表初始化禁止缩窄。
		cout << i << endl;
	}
}

