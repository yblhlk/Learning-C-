#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>

using std::cin;
using std::cout;
using std::endl;

// �б��ʼ���ĵ�һ�����ã�ͬһ��ʼ���﷨
// ��C++98�У���׼����ʹ�û����� {} ��������߽ṹ��Ԫ�ؽ���ͳһ���б��ʼֵ�趨
// C++11��ͳһ�˳�ʼ���﷨��
// �б��ʼ������C++11�������ô�����������б�(��ʼ���б�)��ʹ�÷�Χ��ʹ����������е��������ͺ��û��Զ�������͡�

//�б��ʼ���ĵڶ������ã���ֹ��խ(����ֹ��ʽ����ת��������׶λᱨ��

struct Student
{
	size_t _age;
	int _num;
};

class Teacher
{
public:
	Teacher(size_t age = 40, int num = 100)
		:_age(32)
		, _num(1)
	{
		_age = age;
		_num = num;
	}
private:
	size_t _age;
	int _num;
};

int main()
{
	//��C++98�У���׼����ʹ�û����� {} ��������߽ṹ����г�ʼ��
	{
		int i = { 1 };
		int arr[] = { 1,2,3,4 };

		Student s = { 1,2 };
		Student srr[] = { {1,1},{2,2},{3,3} };
	}

	//C++11�������ô�����������б�(��ʼ���б�)��ʹ�÷�Χ��ʹ����������е��������ͺ��û��Զ��������
	//ʹ�ó�ʼ���б�ʱ������ӵȺ�(=)��Ҳ�ɲ����
	{
		int i{ 2 };//�ɼ�=Ҳ�ɲ���=
		int arr[]{ 1,2,3,4 };

		Student s{ 1,2 };
		Student srr[]{ {1,1},{2,2},{3,3} };

		//C++11��֧��ʹ�ó�ʼ���б�����ʼ�����󣨻���÷��ϵĹ��캯��)��û��Ĭ�ϵ�initializer_list���캯��
		Teacher t{ 1,2 };
		Teacher t1 = { 2,2 };
		Teacher trr[]{ {1,1},{2,2},{3,3} };

		//new
		Student* s1 = new Student{ 1,1 };
		Student* srr1 = new Student[]{ {1,1},{2,2},{3,3} };

		//STL (���������ԭ������治ͬ����������Ϊ��initializer_list�Ĺ��캯����
		std::string str = { 'a','b','c' };
		std::string str1{ 'a','b','c' };
		cout << str << ' ' << str << endl;
		std::vector<int> v = { 1,2,3,4,5 };
		std::vector<int> v1{ 1,2,3,4 };
		std::list<int> l = { 1,2,3,4,5,6 };
		std::list<int> l1{ 1,2,3,4 }; 
		std::deque<int> d = { 1,2,3,4 };
		std::deque<int> d1{ 1,2,3,4,5,6 };
		std::set<int> se = { 1,2,3,4,5 };
		std::set<int> se { 1,2,3,4,5 };
		std::map <std::string, double> m = { {"baby_cabbage", 1.0} };
		std::map <std::string, double> m1 { {"cucumber", 1.0} };

	}

	// �б��ʼ������һ����Ҫ�����ǣ���ֹ��խ��(����ֹ��ʽ����ת��������׶λᱨ��
	{
		int i = 123456789;
		//char c{ i }; //�����б��ʼ����ֹ��խ��
		cout << i << endl;
	}
}

