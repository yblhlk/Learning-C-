#include<iostream>
#include<functional> //std::function/std::bind
using namespace std;

template<typename F>
void useFunction(F f)
{
	static int i = 0;
	cout << "����ģ����ô�����" << ++i << endl;
	cout << "����ģ���о�̬�����ĵ�ַ" << &i << endl;
}


double add(int a, int b) 
{ 
	cout << a << ' ' << b << endl;
	return a+b;
}

class Add
{
public:
	double operator()(int a, int b)
	{
		cout << a << ' ' << b << endl;
		return a + b;
	}
	double add(int a, int b)
	{
		cout << a << ' ' << b << endl;
		return a + b;
	}

	static double staticAdd(int a, int b)
	{
		cout << a << ' ' << b << endl;
		return a + b;
	}
};

int main()
{
	// 1. ʹ��bind��װ��
	{
		cout << "===================== 1. ʹ��bind��װ��===================" << endl;
		auto f1 = std::bind(add, 1, 2);
		cout << f1() << endl;
		auto f2 = std::bind(Add(), 1, 2);
		cout << f2() << endl;
		auto f3 = std::bind([](int a, int b)->double {
			cout << a << ' ' << b << endl;
			return a + b; }, 3, 4);
		cout << f3() << endl;

		//��װ��Ա����
		cout << "-------------------��װ��Ա����----------------" << endl;
		// ��ͨ��Ա��������ͨ��Ա��������Ҫȡ��ַ �� ����һ������
		auto f4 = bind(&Add::add,Add(), 2, 4);
		f4();
		//����1����ͨ��Ա��������Ҫȡ��ַ �� ����һ������
		//auto f4 = bind(Add::add, 2, 4);

		//��̬��Ա���� : ���Ե���ͨ����ʹ��
		auto f5 = bind(Add::staticAdd, 3, 6);
		f5();
		auto f6 = bind(&Add::staticAdd, 4, 6); //���ܴ��������Ϊ��̬��Ա����û��thisָ�롣
		f6();
		

		// bind��װ����������ͳһ�ɵ��ö��������
		cout << "-------------------bind��װ����������ͳһ�ɵ��ö��������----------------" << endl;
		useFunction(f1);
		useFunction(f2);
		useFunction(f3);
	}

	// 2. bind������
	{
		cout << "===================== 2. bind������===================" << endl;
		// ����һ����װһ����������������ĳЩ������Ϊ�̶���ֵ���������ڵ���ʱ���Բ��ô���ĳЩ������
		auto b1 = std::bind(add, 1, 2);
		b1();
		b1(2, 3);

		// ���ö�����������˳��
		// ����bind��һ����ʽ��auto f = bind(add,arg_list)
		// arg_list�еĲ������ܰ������� _n�����֣�����n��һ����������Щ�����ǡ�ռλ��������ʾ f�Ĳ���������ռ���˴��ݸ�add�Ĳ����� ��λ�á���
		// placeholders_1 ��һ��ռλ����placeholders��ʵ��һ�������ռ�
		// ���±�ʾ��b2�ĵڶ����͵�һ����������add�ĵ�һ���͵ڶ���������
		auto b2 = std::bind(add, placeholders::_2, placeholders::_1);
		b2(3, 4);
		return 0;
	}
}

///** 2.bind��װ����
//* ʹ�� bind��װ����Ҫ����ͷ�ļ���#include <functional>
//* sauto f = bind(add,arg_list)//arg_list�ǲ����б��ռλ����
//* 
//* ���ã�
//* *��װһ����������������ĳЩ������Ϊ�̶���ֵ���������ڵ���ʱ���Բ��ô���ĳЩ������
//* *��������˳��
//*/ 