// C++是一个多继承语言，Java是单继承多接口语言
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

namespace E1
{
	//菱形继承和菱形继承问题
	class A
	{
	public:
		int a = 0;
	};

	class B : public A
	{
	public:
		int b = 1;
	};

	class C : public A
	{
	public:
		int c = 2;
	};

	class D : public B, public C //C++支持多继承
	{
		int d = 3;
	};
}

namespace E2
{
	//使用虚拟继承来解决菱形继承问题
	class A
	{
	public:
		int a = 0;
	};

	class B : virtual public A
	{
	public:
		int b = 1;
	};

	class C : virtual public A
	{
	public:
		int c = 2;
	};

	class D : public B, public C //C++支持多继承
	{
		int d = 3;
	};

	//运行后通过 调试->窗口->内存 打开内存窗口。
	//在监视窗口中通过&d来获取类D对象d的地址
	//在内存窗口中输入对象d的地址,获取该地址前后的信息
	//会发现里面存了两个地址（这里是小端表示要倒着读），通过内存窗口发现这两个地址中的内容是一个地址偏移量
	//用地址+偏移量会找到爷类对象的内容。

	//这两个地址叫虚基表指针，它们分别指向一个虚基表。虚基表中存的偏移量
}

int main()
{
	// 菱形继承的二义性还可以通过指定访问来解决。
	// 菱形继承最大的问题在于数据冗余，子类很有可能从多个父类中继承相同的爷类成员。

	E2::D d;
	return 0;
}