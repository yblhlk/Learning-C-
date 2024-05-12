#include<iostream>
using std::cin;
using std::cout;
using std::endl;

 /**
   在虚函数的后面写上 = 0 ，且没有函数体，则这个函数为纯虚函数。
   包含纯虚函数的类叫做抽象类（也叫接口类），抽象类不能实例化出对象。
   派生类继承后也不能实例化出对象，只有重写纯虚函数，派生类才能实例化出对象
 */

class Car
{
public:
	virtual void diver() = 0;
};

class BMW : public Car
{
public:
	virtual void diver()
	{
		cout << "BMW is comfortable" << endl;
	}
};

int main()
{
	 // Car c; 抽象类不允许实例化对象。
	Car* c1 = new BMW();
	c1->diver();
	return 0;
}