#include<functional> //std::function\std::bind
#include<iostream>
using namespace std;
// ������ͬ�ĺ���ָ�롢�º�����lambda���ʽ�ǲ�ͬ������
// ����������ͬ��lambda���ʽҲ�ǲ�ͬ������
// ��û�а취ͳһ���ǵ����ͣ�
// Ϊ��C++11�����˰�װ���ĸ��

/** 1.function��װ����
* std::function������һ��ͨ�õġ����Ͱ�ȫ�ġ��ɵ��õĶ����װ����(ʵ������һ����ģ��)
* �������㽫�κοɵ��õ�Ŀ�꣨�纯�����º�����lambda���ʽ����Ա����ָ��ȣ�
* �洢Ϊstd::function����
* 
* ʹ�� function��װ����Ҫ����ͷ�ļ���#include <functional>
* std::function<Ret(Arg...)> ������ = ����/�º���/lambda���ʽ/��Ա����ָ���
* 
* ���ã�
* *���ɵ��ö�������ͽ���ͳһ�����ڹ���
* *��װ����ȷ�˿ɵ��ö���ķ���ֵ���β����ͣ����ӷ���ʹ����ʹ�á�
*/ 

template<typename Fun, class P>
void usefunction(Fun func, P parameter)
{
	static int i = 0;
	cout << "usefunction�������ô�����" << ++i << endl;
	cout << "��̬�����ĵ�ַ��" << &i << endl;
	func(parameter);
}
// ��ͨ����
int testFunction(int a)
{
	return a;
}
// �º���
class TestFunctor
{
public:
	int operator()(int a) { return a; }
	int testMemberFunctor(int a) { return a; }
	static int testMemberFunctor1(int a) { return a; }
};

int main()
{
	// 1.function��װ������<functional>�£�
	{
		cout << "============================1.function��װ��========================" << endl;
		cout << "-----------------------��ʹ��function��װ��---------------------" << endl;
		usefunction(testFunction, 1);
		usefunction(TestFunctor(), 1);
		usefunction([](int a)->int {return a; }, 1);
		// ���Է��־���ʹ�õĹ�����ͬ�ĺ������º�����lambda���ʽ����usefunction����ģ����������������������
		// ��ʱ�Ϳ�����function��װ���ֱ���������ɵ��ö�����а�װ��
		// Ȼ��������������װ��Ŀɵ��ö���������useF��������ʱ��ֻ��ʵ������һ��useF������
		
		cout << "-----------------------ʹ��function��װ��---------------------" << endl;
		std::function<int(int)> f1 = testFunction;
		std::function<int(int)> f2 = TestFunctor();
		std::function<int(int)> f3 = [](int a)->int {return a; };
		// ������д�ɣ�
		std::function<int(int)> f11(testFunction);
		std::function<int(int)> f22(TestFunctor());
		std::function<int(int)> f33([](int a)->int {return a; });
		//��Ϊstd::function<Ret(Arg...)> �Ǹ���ģ���ࡣ��ʹ�ã�����=�����ù��캯��
		usefunction(f1, 1);
		usefunction(f2, 1);
		usefunction(f3, 1);
		// ʹ��function��װ����������ͬ�ĺ������º�����lambda���ʽ��װ��ʹ������ͳһ��
		
		//��װ��Ա����
		cout << "-----------------------��װ��Ա����---------------------" << endl;
		// ����ͨ��Ա������
			//��������ͨ��Ա�������������&��û��ֱ�ӱ���
			//�����б���Ҫ����һ���������������������������� thisָ��
			//thisָ�벻����ʾȥ����������Ҫ���������
		std::function<int(TestFunctor, int)> f4(&TestFunctor::testMemberFunctor);
		f4(TestFunctor(), 1);
			// ����1���Ǳ�׼�﷨����ʹ�� "&" ������ָ���Ա��ָ��
			//std::function<int(TestFunctor, int)> f5(TestFunctor::testMemberFunctor);
			// ����2�����õ�ʱ�����Ҫ����һ���������󣬲���ֱ�ӱ���
			//f4(1); 
		
		// ��̬��Ա��������������ͨ�������ã�����Ҫ������
			// &��û�ж��У�������ͨ��Ա����������
		std::function<int(int)> f6(&TestFunctor::testMemberFunctor1);
		std::function<int(int)> f7(TestFunctor::testMemberFunctor1);
		usefunction(f6, 1);
		usefunction(f7, 1);
	}
	return 0;
}