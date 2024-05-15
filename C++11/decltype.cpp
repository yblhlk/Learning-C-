#include<iostream>
using namespace std;

//ʹ��decltype()���������ݱ��ʽ�����ͣ������ݱ�������/����ָ������/��������ֵ����
//Ҫ��decltype()���ݺ���ָ�����ͣ����� decltype(&������) ��������Ȼ�����������������һ������ָ�루��һ����������

int add(int a, int b)
{
	return a + b;
}

int main()
{
	//decltype : ����������Ϊ���ʽ����(���ݱ��ʽ������)
	int a = 1;
	double b = 1.42;
	decltype(a * b) c;
	decltype(&a) d;
	cout << typeid(c).name() << endl; //�鿴��������
	cout << typeid(d).name() << endl;
	cout << typeid(decltype(&b)).name() << endl;

	//decltype�������ݺ���&��������ֵ������ 
	decltype(add) e; //��������
	decltype(&add) f; //����ָ�����ͣ��ܵ�����ָ����**
	decltype(add(1, 1)) g = 1; //��������ֵ����
	f = add; // ��������ֵ������ָ��
	cout << f(1, 3) << endl; //ʹ�ú���ָ����ú���
	
	cout << typeid(add).name() << endl;
	cout << typeid(decltype(add)).name() << endl;
	cout << typeid(&add).name() << endl;
	cout << typeid(decltype(&add)).name() << endl;
	cout << typeid(add(1, 2)).name() << endl;
	cout << typeid(decltype(add(1, 2))).name() << endl;
	return 0;
}