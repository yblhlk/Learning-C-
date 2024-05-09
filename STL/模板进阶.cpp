#include<iostream>
using std::cin;
using std::cout;
using std::endl;

// �عˣ�
//1.����ģ��
template<typename T>
int add(T a, T b)
{
	return a + b;
}

//2.��ģ��
template<typename T>
class Student
{
public:
	Student(std::string name= "J", size_t age = 0)
		:_name("W")
		,_age(23)
	{}
	void toString()
	{
		cout << "Student { _naem : " << _name << ", _age : " << _age << " } " << endl;
	}
	T setAge(T a)
	{
		_age = a;
		return _age;
	}
private:
	std::string _name;
	size_t _age;
};

//һ��������ģ�����
// 1. ��������������Լ��ַ����ǲ�������Ϊ������ģ������ġ�
// 2. �޷�ʹ�ñ�������������ģ�����
template<class T1, size_t N>
class Array
{
public:
	void arr0(T1 a)
	{
		arr[0] = a;
	}
	T1 print0()
	{
		cout << "capacity : " << N << endl;
		cout << "arr[0] : " << arr[0] << endl;
		return arr[0];
	}
private:
	T1 arr[N];
};


//����ģ����ػ�
// 1.����ģ���ػ�
// ����ģ��
template<class T1, class T2>
void tf(T1 a, T2 b)
{
	cout << "����ģ�� T1 tf(T1 a, T2 b)" << endl;
}
template<>
// ����ģ��ȫ�ػ�
void tf(int a, double b)
{
	cout << "����ģ��ȫ�ػ���int tf(int a, double b)" << endl;
}
template<>
void tf(double a, double b)
{
	cout << "����ģ��ȫ�ػ���double tf(double a , double b)" << endl;
}
// ����ģ�岿���ػ��� �������أ� ��������������ʾ�����Ǻ������أ�
template<typename T1>
void tf(T1 a, double b)
{
	cout << "����ģ������أ�int tf(T1 , double b)" << endl;
}
//����ģ��û�в����ػ�����Ϊ���������ػ��ƣ�����������Ҫƫ�ػ���ֻҪ����һ��ģ��Ϳ���ʵ��ƫ�ػ���Ч����


// 2.��ģ���ػ�
template<typename T1, class T2>
class A
{
public:
	void print()
	{
		cout << "��ģ�壺class A" << endl;
	}
};
// 2.1ȫ�ػ�
template<>
class A<int, int>
{
public:
	void print()
	{
		cout << "��ȫ�ػ���class A<int, int>" << endl;
	}
};
// 2.2 �����ػ�
template<class T1>
class A<char, T1>
{
public:
	void print()
	{
		cout << "�ಿ���ػ���class A<char, T1>" << endl;
	}
};
// 2.3 ƫ�ػ�
// a.ƫ�ػ�Ϊָ������
template<class T1, class T2>
class A<T1*, T2*>
{
public:
	void print()
	{
		cout << "ƫ�ػ�Ϊָ�����ͣ�class A<T1*, T2*>" << endl;
	}
};
//b.ƫ�ػ�Ϊ��������
template<class T1, class T2>
class A<T1&, T2&>
{
public:
	void print()
	{
		cout << "ƫ�ػ�Ϊ�������ͣ�class A<T1&, T2&>" << endl;
	}
};


int main()
{
	//�عˣ�����ģ�� & ��ģ��
	{
		cout << "--------------------�عˣ�����ģ�� & ��ģ��--------------------" << endl;
		// ����ģ��
		int a = 1, b = 2;
		cout << add(a, b) << endl;
		Student<int> s1("wyl", 23);

		// ��ģ��
		s1.setAge(a);
		Student<int>* s2 = new Student<int>(s1);
		s1.toString();
		s2->toString();
	}

	//������ģ�����
	{
		cout << "----------------------------������ģ�����----------------------------" << endl;
		int a = 1;
		Array<int, 10> arr1;
		arr1.arr0(a);
		arr1.print0();
	}

	// ����ģ���ػ�
	{
		cout << "-------------------------------����ģ���ػ�--------------------------------" << endl;
		// 1. ����ģ���ػ�
		int a = 1, b = 2;
		double c = 1;

		cout << endl << "tf<char>(a, 1);";
		tf<char>(a, 1); // ����ģ�� T1 tf(T1 a, T2 b)

		cout << endl << "tf((int)a, 1.0);";
		tf((int)a, 1.0);         // ģ���ػ���int tf(T1 , double b)
		cout << endl << "tf<int, double>(a, 1.0);";
		tf<int, double>(a, 1.0); // ģ���ػ���int tf(int a, double b)
		cout << endl << "tf(1.0, 2.0);";
		tf(1.0, 2.0);            // ģ���ػ���int tf(T1 , double b)
		cout << endl << "tf<double, double>(1.0, 2.0);";
		tf<double, double>(1.0, 2.0);     //ģ���ػ���double tf(double a, double b)

		//����ģ��Ĳ����ػ���ȫ�ػ��������ȼ��Ĳ�ȷ���ԣ������Ƽ�ֻʹ�ú���ģ���ȫ�ػ���
	}

	// ��ģ���ػ�
	{
		cout << "-------------------------------��ģ���ػ�--------------------------------" << endl;
		A<double,char> a;
		a.print();
		// 2.1ȫ�ػ�
		A<int, int> b;
		b.print();
		// 2.2 �����ػ�
		A<char, int> c;
		c.print();
		// 2.3 ƫ�ػ�
		// a.ƫ�ػ�Ϊָ������
		A<int*, int*> d;
		d.print();
		//b.ƫ�ػ�Ϊ��������
		A<int&, int&> e;
		e.print();
	}
	return 0;
}

//����ģ����Ȼ�ܲ����ػ��������ǲ��Ƽ�ʹ�ã���Ϊ����ģ���ģ��������ɱ����������ܵ�
//��ģ�����ʹ�ò����ػ���ԭ������ģ���ģ������������Ǵ����