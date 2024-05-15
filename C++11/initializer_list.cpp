#include<iostream>
#include<initializer_list>

using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;

//initializer_list���ʾ���һ�� {} ���������б�

int main()
{
	// 1. C++11������ʹ��{}�����б��ʼ�����ܻᴴ��һ��initializer_list<>����
	auto in = { 1,3,5,7 };
	cout << typeid(in).name() << endl;  //class std::initializer_list<int>

	// 2. std::initializer_list һ������Ϊ���캯���Ĳ�����
	//C++11�� STL�еĴ󲿷������������� std::initializer_list��Ϊ�����Ĺ��캯��
	//��string\vector\list\deque\set\map
	//ע��C++98����֧��ֱ�����б���������г�ʼ�������ֳ�ʼ����ʽ����C++11����initializer_list���֧�ֵ�

	// 3.ֻ��ʹ���������������initializer_list 
	// ��������ı��ʾ�������ָ�룬��˵initializer_list�ı��ʾ������顣
	cout << *in.begin() << endl;
	cout << *(in.begin()+2) << endl;
	cout << *(in.end()) << endl; //Խ�磬��������

	//.size()
	cout << in.size() << endl;
	return 0;
}