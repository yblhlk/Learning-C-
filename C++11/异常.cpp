/**C语言传统的错误处理机制：
* 1. 终止程序：如 assert; (assert在 release版本下会失效 )
* 2. 使用return + 错误码;
* 3. 还有我们在小项目中的if判断 + 打印错误提示语句。
*/ 

// 异常和上面的思想没有本质的区别，只是将 程序中遇到的错误信息封装成类
// 用if来判断是否出错，如果出错通过throw来抛出异常对象，
// 把可能抛出异常对象的语句用try{}括起，
// 然后用catch(){}来捕获try中抛出的异常，如果符合，则执行catch中的语句。
// 大多数OOP语言都支持异常机制，这种机制允许程序在出现错误时跳出正常的执行流程，并执行相应的错误处理代码。而不是直接终止程序。

//异常是一种处理错误的方式，当一个函数发现自己无法处理的错误时就可以抛出异常，让函数的直接或间接的调用者处理这个错误，使用异常处理错误并不会终止程序

#include<iostream>
#include<functional>
using namespace std;
int main()
{
	// 1.异常的抛出和捕获
	{
		// 使用throw来抛出异常
		// 使用try{}catch来捕获异常
		cout << "=======================1.异常的抛出和捕获=======================" << endl;
		try
		{
			throw "就是想抛一个异常。";// 抛出一个字符串
		}
		catch (const char* ex) //捕获字符串异常
		{
			cout << "抓住你咯。" << endl;
		}

		cout << "事实证明，程序会继续运行。" << endl;

		// catch(...)可以捕获任意异常
		try
		{
			throw "就是想抛一个异常。";// 抛出一个字符串
		}
		catch (...)
		{
			cout << "未知异常" << endl;
		}

		// 抛出的异常没有被捕获则会终止程序。
		/*try
		{
			throw 0;
		}
		catch (const char* ex)
		{
			cout << "未知异常" << endl;
		}*/

		//被选中的处理代码是调用链中与该对象类型匹配且离抛出异常位置最近的那一个。
		try
		{
			throw "就是想抛一个异常。";// 抛出一个字符串
		}
		catch (const char* ex) //捕获字符串异常
		{
			cout << "抓住你咯。" << endl;
		}
		catch (...) //捕获字符串异常
		{
			cout << "我能抓住你吗？" << endl;
		}
		//catch (const char* ex) //报错：“const char* ”: 由“const char* ”在行 60 上捕获
		//{
		// //不能有一模一样的捕获
		//	cout << "我也能抓住你吗？" << endl;
		//}
		

		/**catch(...) 可以捕获任意类型的异常，问题是不知道异常错误是什么。
		 * 在实际中我们最后都要加一个 catch(...)捕获任意类型的异常，否则当有异常没捕获时，程序就会直接终止。
		 */

		/**实际中抛出和捕获的匹配原则有个例外，并不都是类型完全匹配，
		 * 可以抛出的派生类对象，使用基类捕获，这个在实际中非常实用，我们后面会详细讲解这个
		 */
	}
	
	// 2.异常的重新抛出
	{
		cout << "=======================2.异常的重新抛出=======================" << endl;
		/**有可能单个的catch不能完全处理一个异常，
		 * 在进行一些校正处理以后，希望再交给更外层的调用链函数来处理，
		 * catch则可以通过重新抛出将异常传递给更上层的函数进行处理。
		 * （在catch中throw交给上一层函数来处理）
		 */
		function<void(void)> a = [] {
			try {
				throw "你能抓到我么？";
			}catch (const char* ex){
				cout << ex << endl;
				cout << "抓到了，但我放你一马。" << endl;
				throw; //重新抛出异常，交给外层函数处理
			}
		};

		try{
			a();
		}catch (const char* ex){
			cout << ex << endl;
			cout << "抓到了，我可没这么好说话，不放过。" << endl;
		}
	}

	// 3.异常安全问题
	{
		cout << "=======================3.异常安全问题=======================" << endl;
	// a. 资源的释放要在抛异常前完成，或在捕获异常中完成
		// 因为使用throw抛出异常后，会直接跳到外层，直到被捕获。
		// 所以申请了系统资源时抛异常一定要注意这一点，不然会造成内存泄漏等问题。
		function<void(void)> a = [] {
			try {
				throw "主动抛出异常，会跳过后面的内容，不信你看。";
				cout << "资源完成释放！" << endl;
			}
			catch (const char* ex) {
				cout << ex << endl;
				cout << "异常再次抛出，还是会跳过后面的内容，不信你看。" << endl;
				throw; //重新抛出异常，交给外层函数处理
				cout << "资源完成释放！" << endl;
			}
		};

		try {
			a();
		}
		catch (const char* ex) {
			cout << ex << endl;
			cout << "抓到了，我可没这么好说话，不放过。" << endl;
		}

	//b. 针对使用throw抛异常会直接跳到外层，而导致异常安全问题.
	//   对于异常安全问题下面给出几点建议：
		//a.最好不要在构造函数中抛出异常，否则可能导致对象不完整或没有完全初始化
		//b.好不要在析构函数内抛出异常，否则可能导致资源泄漏(内存泄漏、句柄未关闭等)
		//c.在new和delete之间，要小心抛出异常，不然可能导致内存泄漏
		//d.在lock和unlock之间，要小心抛出异常，不然可能导致死锁
		//(C++经常使用 RAII 来解决以上问题，关于 RAII，智能指针这节进行讲解)
	}

	//4. 异常规格说明
	{
		cout << "=======================4. 异常规格说明=======================" << endl;
		/** 异常规格说明是什么？
		 * 可以在函数的后面接throw(类型)，列出这个函数可能抛掷的所有异常类型。（注意是类型，不用带形参）
		 * 函数的后面接throw()，表示函数不抛异常。
		 * 若无异常接口声明，则此函数可以抛掷任何类型的异常。
		 * 
		 * C++11 中新增的 noexcept，表示不会抛异常(这是对 C++98 的异常规范的简化)
		 */

		//a. 可以在函数的后面接throw(类型)，列出这个函数可能抛掷的所有异常类型。
		class ExceptionA{}; //声明一个异常A
		function<void(void)> fa = []()throw(const char* , ExceptionA) {
			throw "是的，我打算抛出一个异常";
			throw ExceptionA();
		};
		//b. 函数的后面接throw()，表示函数不抛异常。
		function<void(void)> fb = []()throw() {
			cout << "我很简单，不会抛异常。" << endl;
		};
		//c. 若无异常接口声明，则此函数可以抛掷任何类型的异常。
		function<void(void)> fc = [](){
			throw "你猜我有没有抛异常？";
			throw ExceptionA();
		};
		//d.  C++11 中新增的 noexcept，表示不会抛异常(不能和throw()同时写。)
		function<void(void)> fd = []()noexcept{
			cout << "我很简单，不会抛异常。" << endl;
		};

		//声明了throw()和noexcept,还是可以在函数中抛异常，不报错，
		//甚至声明了throw()的函数抛出的异常仍可以被捕获，
		//但是声明了noexcept的函数抛出的异常无法被捕获。
		function<void(void)> fdd = []()throw() {
			cout << "我就是要抛异常，throw()大哥保我！" << endl;
			throw "有一个人前来抛异常。";
		};
		try {
			fdd();
		}
		catch (const char* ex) {
			cout << ex << endl;
			cout << "异常的保护伞？该罚！" << endl;
		}

		function<void(void)> fddd = []()noexcept {
			cout << "我就是要抛异常，noexcept大哥保我！" << endl;
			throw "有一个人前来抛异常。";
		};
		try {
			fddd();
		}
		catch (const char* ex) {
			cout << ex << endl;
			cout << "异常的保护伞？该罚！" << endl;
		}
	}
	return 0;
}