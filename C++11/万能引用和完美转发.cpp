#include<iostream>
#include<utility> //forword在utility下
using std::cin;
using std::cout;
using std::endl;

//C++为什么没有没有右值引用的函数的形参能接收右值?
//C++在没有引入右值引用之前，右值会被隐式地转换为左值引用，而不是直接接收右值。

//万能引用 : 模板中的&&表示万能引用，即既能接收左值，又能接收右值。

//完美转发：把实参的右值属性转发给了其他函数
// 为什么需要完美转发？
//右值被引用后会导致右值被存储到特定位置，这时这个右值可以被取到地址，并且可以被修改，所以在 PerfectForward函数中调用Func函数时会将t识别成左值
//也就是说，右值经过一次参数传递后其属性会退化成左值，我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要使用完美转发
// 怎么进行完美转发？
// 在使用要进行完美转发的函数时，用std::forword()将实参扩起来。（forword()在<utility>下

void func(int&& a)
{
	cout << "右值引用" << endl;
}
void func(int& a)
{
	cout << "左值引用" << endl;
}
template <typename T>
class A
{
public:
	//C++在没有引入右值引用之前，右值会被隐式地转换为左值，而不是直接接收右值。
	//最好用const来接收，像以下的写法就是极其不安全的:
	//void a(int b)
	//{
	//	//b++;
	//	cout << "" << endl;
	//};
	void a(T&& b)
	{
		cout << "类中成员函数的万能引用" << endl;
		func(b); //左值引用（没办法，形参会被识别成左值，因为此时形参引用的右值被放到了特定的位置）
		func(std::forward<T>(b)); //右值引用，完美转发（把实参的右值属性转发给了其他函数）
	}
};

template <typename T>
void funca(T&& b)
{
	cout << "类中成员函数的万能引用" << endl;
	func(b); //左值引用（没办法，形参会被识别成左值，因为此时形参引用的右值被放到了特定的位置）
	func(std::forward<T>(b)); //右值引用，完美转发（把实参的右值属性转发给了其他函数）
}

int main()
{
	int i = 1, j = 2;
	A<int> classa;
	// 模板类的成员函数的万能引用和完美转发
	classa.a(std::move(i));
	// 模板函数的万能引用和完美转发
	funca(std::move(i));
	return 0;
}