#include<iostream>
//#include<typeinfo>
#include<algorithm>
#include<vector>
#include<list>
#include<deque>
using namespace std;

//在之前学习sort函数中，为了实现降序，我们还要在类中重载< 或写一个仿函数、函数，有点麻烦，
//本质上我们只是需要一个使用一次的排序函数罢了，所以C++11引入了lambda表达式来

//lambda表达式是一个匿名函数，恰当使用lambda表达式可以让代码变得简洁，并且可以提高代码的可读性

//lambda表达式书写格式：
//[capture - list](parameters) mutable -> return-type{ statement }
//[capture-list] : 捕捉列表，捕捉所有父作用域中的变量让其能在函数体中使用。
//(parameters)：参数列表。如果不需要参数传递，则可以连同 () 一起省略。
// mutable：默认情况下，lambda函数总是一个const函数，mutable修饰符可以取消其常量性。使用该修饰符时，参数列表不可省略(即使参数为空)
// ->returntype：返回值类型。可以省略，由编译器来推导
//{statement}：函数体。在该函数体内，除了可以使用其参数外，还可以使用所有捕获到的变量

/** 0. 在lambda函数定义中，参数列表和返回值类型都是可选部分，而捕捉列表和函数体可以为空。
 *  但是捕捉列表和函数体必须要有，即使为空。
 *  因此C++11中最简单的lambda函数为：[]{} ; 该lambda函数不能做任何事情
 */

/** 1. 捕获列表详解
* [var]：表示值传递方式捕捉变量var （值传递无法修改原变量）
* [=]：表示值传递方式捕获所有父作用域中的变量(包括this)
* [&var]：表示引用传递捕捉变量var （引用传递，可以修改原变量）
* [&]：表示引用传递捕捉所有父作用域中的变量(包括this)
* [this]：表示值传递方式捕捉当前的this指针
*/

// 2. lambda表达式的底层就是仿函数（而且是独一无二的仿函数）

/** 3. 可以借助 auto 将lambda表达式赋值给一个变量。
*   lambda表达式实际上可以理解为无名函数，该函数无法直接调用，
*   如果想要直接调用，可借助 auto 将其赋值给一个变量。
*/

int global_a = 0; //全局变量不需要捕获可直接当&捕获来用
int static_a = 0;
auto gfa = [] {}; //全局的lambda表达式捕获列表必须为空。
//auto gfb = [a] {}; //报错：未定义标识符"a"。全局的lambda表达式捕获列表必须为空。
int main()
{
	// 0. lambda表达式必须有捕获列表和函数体，[]{}就是最简单的lambda表达式，什么也做不了
	{
		cout << "=======================0. lambda表达式必须有捕获列表和函数体======================" << endl;
		auto functiona = [] {};
		functiona(); 

		auto fc = [](int a) { cout << a << endl; };
		fc(1);
	}
	
	// 1. 捕获列表详解
	const int static_b = 0;
	{
		cout << "=======================1. 捕获列表详解======================" << endl;
		int a = 1;
		int b = 2;
		cout << "--------------------- [var] 和 [=] ----------------------" << endl;
		// 报错1：必须是可修改的左值
		// 原因： [var] 和 [=] 捕获的变量无法被修改。
		//auto fca = [global_a, a, b] {
		//	a++; b++; //报错：必须是可修改的左值。
		//	cout << global_a << a << b << endl; 
		//};
		
		// 报错2：无法在 lambda 中捕获带有静态存储持续时间的变量
		// 原因：全局变量不需要也不能捕获，可以直接使用。(全局变量默认被&捕获)
		// 注：非全局变量（包括局部静态变量和const修饰的局部变量）都需要被捕获后才能使用。
		//auto fca = [global_a, a, b] {cout << global_a << a << b << endl; };
		auto fca = [static_b, a, b] {cout << static_a << static_b << global_a << a << b << endl;};
		fca();
		auto fcb = [=] {cout << global_a << a << b << endl; };
		fcb();
		cout << global_a << a << b << endl;
		// 报错3：封闭函数局部变量不能在 lambda 体中引用，除非其位于捕获列表中.
		// 原因：父作用域中的局部变量必须捕获后才能在lambda 体中使用。
		//auto fcb = [] {cout << a << b << endl; }; 
		
		// 报错4：显式捕获与默认设置匹配（有重复）
		// 原因：捕捉列表不允许变量被重复捕获，错误用法有：使用[=]捕获了，又使用[var]来捕获
		//auto fcc = [=, a] {}; //报错，显式捕获与默认设置匹配（有重复）
		auto fcc = [=, &a] {}; 
		
		cout << "--------------------- [&var] 和 [&] ----------------------" << endl;
		auto fcd = [&a, &b] {
			static_a++, a++, b++;
			cout << static_a << global_a << a << b << endl;
		};
		fcd();
		auto fce = [&] {
			global_a++, a++, b++;
			cout << static_a << global_a << a << b << endl;
		};
		fce();
		cout << static_a << global_a << a << b << endl;

		cout << "--------------------- [this] ----------------------" << endl;
		class S
		{
			int a = 1;
		public:
			void test()
			{
				auto fcd = [this] {cout << (*this).a << endl; }; //[this]用在类的成员函数中的lambda表达式。
				fcd();
			}
		};
		S s;
		s.test();
	}

	// 2. lambda表达式的底层就是仿函数（而且是独一无二的仿函数）
	{
		cout << "==============2. lambda表达式的底层就是仿函数（而且是独一无二的仿函数）==============" << endl;
		/*实际上当我们定义一个lambda表达式后，编译器会自动生成一个类，在该类中对()运算符进行重载，实际 lambda函数体的实现就是这个仿函数的 operator()的实现。
		在调用 lambda表达式时，参数列表和捕获列表的参数，最终都传递给了仿函数的 operator()
		该类的名字是编译器随机生成的，该类名只有编译器可以认识，
		这也是我们为什么要借助 auto 将其赋值给一个变量的原因
		这也是lambda表达式之间不能相互赋值的原因*/
		
		//通过反汇编我们可以很清楚的看到，执行lambda表达式时call的是一个operator()。
		// 运行程序->选中代码右击->反汇编

		/*在VS下，lambda表达式在底层会被处理为函数对象，该函数对象对应的类名叫做 <lambda_uuid>。
		类名中的 uuid叫做通用唯一识别码（Universally Unique Identifier），简单来说，uuid就是通过算法生成一串字符串，保证在当前程序当中每次生成的uuid都不会重复。
		lambda表达式底层的类名包含 uuid，这样就能保证每个 lambda表达式底层类名都是唯一的
		因此每个lambda表达式的类型都是不同的，这也就是lambda表达式之间不能相互赋值的原因，
		我们可以通过 typeid(变量名).name() 的方式来获取lambda表达式的类型*/

		// 可以通过 typeid(变量名).name() 的方式来获取lambda表达式的类型
		// 每个lambda表达式的类型都是不同的
		auto fc = [] {};
		auto fb = [] {};
		cout << typeid(fc).name() << endl;
		cout << typeid(fb).name() << endl;
	}
	return 0;
}