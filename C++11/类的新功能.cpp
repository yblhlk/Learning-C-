#include<iostream>
using namespace std;
/**1.final：（写在类名或虚函数的函数声明后）
* a. 修饰虚函数：表示该虚函数不能再被重写
* b. 修饰类：表示该类不能被继承（C++11前只能把构造函数进行私有来防止类被继承） 
*/

/** 2.override: （写在派生类的虚函数的函数声明后）
* 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错。（注意是用来检查虚函数的）
*/

/** 3.默认移动构造函数（C++11后新增的默认成员函数）
* 默认移动构造函数的生成条件是在C++11及之后的版本中，当类没有自己实现移动构造函数，
* 并且也没有自己实现析构函数、拷贝构造函数和赋值重载函数时，编译器会默认生成一个移动构造函数。
* 
* 对于自定义类型成员，如果其实现了就调用移动构造，没有实现就调用拷贝构造。
*/

/** 4.默认移动赋值函数（C++11后新增的默认成员函数）
* 默认移动赋值函数的生成条件和上面相似：在C++11及之后的版本中，当类没有自己实现移动赋值函数和移动构造函数，
* 并且也没有自己实现移动构造函数、析构函数、拷贝构造函数和拷贝赋值函数时，编译器会默认生成一个移动赋值函数。
*
* 对于自定义类型成员，如果其实现了就调用移动赋值，没有实现就调用拷贝赋值。
* (默认移动赋值跟上面移动构造完全类似，就多了一个没有移动构造函数)
*/

/** 5.C++11允许在类定义时给成员变量初始缺省值
* C++11后才能在定义类时给成员变量赋一个缺省值。（注意：这里不是初始化，给的的值是缺省值）
*/

/** 6.= default：（先写一个默认函数的函数声明，再加一个= default, 没有函数体）
* 强制编译器生成某个默认函数
* 比如：提供了拷贝构造，就不会生成移动构造。这时可以用= default。
*/

/** 7.= delete：（先写一个默认函数的函数声明，再加一个= delete, 没有函数体）
* 禁止生成默认函数 
* 要让一个类不能被拷贝，可以用 =delete 修饰将该类的拷贝构造和赋值重载。
*/

// 1 final
namespace Test1{
	//a. final修饰的类
	class F1 final
	{};
	//class S1 : public F1 //报错：不能将"final"类类型用作基类
	//{};

	//b.final修饰虚函数
	class F2
	{
	public:
		virtual void func() final;
		/*void func1() final //报错：不能用final修饰非虚函数
		{}*/
	};
	//class S2 : public F2
	//{
	//	void func(){} //报错：无法重写"final" 函数
	//};
}

// 2. override (写在派生类的虚函数声明后)
namespace Test2
{
	class F
	{
	public:
		//virtual void func() override; //报错：使用"override"声明的成员函数不能重写基类成员
		virtual void func(); //不被子类重写也没关系，只要纯虚函数才必须被子类重写，不然不能创建对象
	};

	class S : public F
	{
	public:
		virtual void func() override //override用来检查子类是否重写父类虚函数，C++的重写只发生在虚函数中
		{}
	};
	class S1
	{
	public:
		//virtual void func() override {}  //报错：使用"override"声明的成员函数不能重写基类成员
		S1(){}
		virtual void func(){}
	};

	class S2
	{
	public:
		//virtual void func() override {}  //报错：使用"override"声明的成员函数不能重写基类成员
		S2() 
		{}
		S2(const S2& s2)
		{
			cout << "调用拷贝构造" << endl;
		}
		S2 operator = (const S2& s2)
		{
			cout << "调用赋值重载" << endl;
			return s2;
		}
		virtual void func() {}
	};
}

// 5. = default
namespace Test3
{
	class Student
	{
	public:
		Student(const Student& s2)
		{
			cout << "调用拷贝构造" << endl;
		}
		Student& operator = (const Student& s2)
		{
			cout << "调用赋值重载" << endl;
			return *this;
		}
		Student(Student&& s2) = default;
		Student() = default;
		Student& operator = (Student&& s2) = default;
		// Student operator = (Student&& s2) = default; //报错：无法重载仅按返回类型区分的函数
	};

	class Teacher
	{
	public:
		Teacher() = delete;
		//Teacher(Teacher&& t) = delete; 
		//显示写了拷贝构造，编译器也不会生成默认构造函数,尽管你删除了它
		Teacher& operator = (Teacher&& t) = delete;
	};
}

int main()
{
	// 3. 默认移动构造函数 （没有显示写：析构函数、拷贝构造函数和赋值重载函数）
	cout << "======================3. 默认移动构造函数=====================" << endl;
	Test2::S1 s1(std::move(Test2::S1()));
	Test2::S2 s2(std::move(Test2::S2())); //调用拷贝构造（确实没有默认移动构造函数）

	// 4. 默认移动赋值函数
	cout << "======================4. 默认移动赋值函数=====================" << endl;
	s1 = std::move(Test2::S1());
	s2 = std::move(Test2::S2()); //调用赋值重载 调用拷贝构造（确实没有默认移动赋值函数）

	// 5. = default
	cout << "======================5. = default=====================" << endl;
	Test3::Student st(std::move(Test3::Student())); //没有打印，证明调用的是默认移动构造。
	st = std::move(Test3::Student()); //没有打印，证明调用的是默认移动赋值。

	// 6. = delete
	cout << "======================6. = delete=====================" << endl;
	//Test3::Teacher(); //显示写了拷贝构造，编译器也不会生成默认构造函数,尽管你删除了它
	//std::move(Test3::Teacher()); //报错：无法引用 的默认构造函数 -- 它是已删除的函数
	//Test3::Teacher t(std::move(Test3::Teacher())); //报错：无法引用 *** -- 它是已删除的函数
	return 0;
}