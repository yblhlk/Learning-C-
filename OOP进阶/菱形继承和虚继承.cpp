// C++��һ����̳����ԣ�Java�ǵ��̳ж�ӿ�����
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

namespace E1
{
	//���μ̳к����μ̳�����
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

	class D : public B, public C //C++֧�ֶ�̳�
	{
		int d = 3;
	};
}

namespace E2
{
	//ʹ������̳���������μ̳�����
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

	class D : public B, public C //C++֧�ֶ�̳�
	{
		int d = 3;
	};

	//���к�ͨ�� ����->����->�ڴ� ���ڴ洰�ڡ�
	//�ڼ��Ӵ�����ͨ��&d����ȡ��D����d�ĵ�ַ
	//���ڴ洰�����������d�ĵ�ַ,��ȡ�õ�ַǰ�����Ϣ
	//�ᷢ���������������ַ��������С�˱�ʾҪ���Ŷ�����ͨ���ڴ洰�ڷ�����������ַ�е�������һ����ַƫ����
	//�õ�ַ+ƫ�������ҵ�ү���������ݡ�

	//��������ַ�������ָ�룬���Ƿֱ�ָ��һ�������������д��ƫ����
}

int main()
{
	// ���μ̳еĶ����Ի�����ͨ��ָ�������������
	// ���μ̳��������������������࣬������п��ܴӶ�������м̳���ͬ��ү���Ա��

	E2::D d;
	return 0;
}