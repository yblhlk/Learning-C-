#include<iostream>
using std::cin;
using std::cout;
using std::endl;

 /**
   ���麯���ĺ���д�� = 0 ����û�к����壬���������Ϊ���麯����
   �������麯��������������ࣨҲ�нӿ��ࣩ�������಻��ʵ����������
   ������̳к�Ҳ����ʵ����������ֻ����д���麯�������������ʵ����������
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
	 // Car c; �����಻����ʵ��������
	Car* c1 = new BMW();
	c1->diver();
	return 0;
}