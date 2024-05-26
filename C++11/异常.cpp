/**C语言传统的错误处理机制：
* 1. 终止程序：如 assert; (assert在 release版本下会失效 )
* 2. 使用return + 错误码;
* 3. 还有我们在小项目中的if + 打印错误提示语句。
*/ 

// 异常和上面的思想没有本质的区别，只是将 程序中遇到的错误信息封装成类
// 用if来判断是否出错，如果出错通过throw来抛出异常对象，
// 把可能抛出异常对象的语句用try{}括起，
// 然后用catch(){}来捕获try中抛出的异常，如果符合，则执行catch中的语句。
// 大多数OOP语言都支持异常机制，这种机制允许程序在出现错误时跳出正常的执行流程，并执行相应的错误处理代码。而不是直接终止程序。

//异常是一种处理错误的方式，当一个函数发现自己无法处理的错误时就可以抛出异常，让函数的直接或间接的调用者处理这个错误，使用异常处理错误并不会终止程序

#include<iostream>
using namespace std;
int main()
{
	// 抛出一个字符串
	try 
	{
		throw "就是想抛一个异常。";
	}
	catch (const char* ex)
	{
		cout << "抓住你咯。" << endl;
	}
	cout << "事实证明，程序会继续运行。" << endl;
	return 0;
}