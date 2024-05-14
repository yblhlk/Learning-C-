#include<iostream>
#include<unordered_set>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_set;

//����֮������unordered_setû�з����������
//��unordered_set�е�Ԫ�ز����޸ġ�
//����unordered_set�е��ʺ���������ֻ�鲻�ĵ����ݣ���Ϊ���ĵײ��ǹ�ϣ����ȡ�ٶȿ졣

// set ������+ȥ��
// multi_set �����򣬵���ȥ��
// unordered_set ֻ��ȥ�أ�������

// setϵ��ֻ���õ����������ʣ����������ֻ��++��--

int main()
{
	//1.������
	{
		cout << "=============================1.������===========================" << endl;
		unordered_set<int> a;
		unordered_set<int> b(a);
		unordered_set<int> c(b.begin(), b.end());

		int arr[] = { 1,2,3,4,5 , 5,5,5}; //unordered_set ֻ��ȥ�أ�������
		unordered_set<int> d(arr, arr + 5);
		//�ɼ�дΪ��
		unordered_set<int> e = { 1,2,3,4,5 };
		//��
		unordered_set<int> f{ 1,2,3,4,5 };
		cout << d.size() << e.size() << f.size() << endl;
		
		//operator =
		a = f;
	}

	//2. Iterator & ����(ֻ���õ���������)
	{
		cout << "===========================2. Iterator & ����(ֻ���õ���������)========================" << endl;
		unordered_set<int> a{ 1,2,3,4,5 };
		cout << ">>>unordered_set<int> a{1,2,3,4,5};" << endl;
		cout << "(*a.begin()) : " << (*a.begin()) << endl;
		cout << "(*--a.end()) : " << (*--a.end()) << endl;
		//cout << "(*a.rbegin()) : " << (*a.rbegin()) << endl; //û�з����������
	}

	//3.����
	{
		cout << "================================3.����=============================" << endl;
		unordered_set<int> a{ 6,8,1,2,3,4,5,5 }; //ֻȥ�أ�������
		cout << ">>>unordered_set<int> a{ 6,8,1,2,3,4,5,5 };" << endl;
		cout << "ʹ�õ���������unordered_set<int> a:" << endl;
		for (unordered_set<int>::iterator it = a.begin(); it != a.end(); ++it)
			cout << (*it)  << ' ';
		putchar(10);

		cout << "ʹ�÷�Χfor����unordered_set<int> a:" << endl;
		for (auto e : a)
			cout << e << ' ';
		putchar(10);
	}

	//4.capacity operate
	{
		cout << "=============================4.capacity operate========================" << endl;
		//.size();
		//.empty();  �ж�size�Ƿ�Ϊ0
		//.clear();  ��size��Ϊ0
		//.swap();

		typedef unordered_set<int> useti;
		useti a{ 10,1,2,3,4,5,6,6 };
		cout << ">>>useti a{10,1,2,3,4,5,6,7};" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << ">>>a.clear();" << endl; a.clear();
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;

		unordered_set<int> b{ 1,2,3,4,5,6 };
		cout << ">>> unordered_set<int> b{ 1,2,3,4,5,6 };" << endl;
		cout << "useti a { "; for (auto e : a) cout << e << " "; cout << " }; ";
		cout << "a.size() : " << a.size() << endl;
		cout << "useti b { "; for (auto e1 : b) cout << e1 << " "; cout << " }; ";
		cout << "b.size() : " << b.size() << endl;
		cout << ">>>a.swap(b);" << endl; a.swap(b);
		cout << "useti a { "; for (auto e : a) cout << e << " "; cout << " }; ";
		cout << "a.size() : " << a.size() << endl;
		cout << "useti b { "; for (auto e1 : b) cout << e1 << " "; cout << " }; ";
		cout << "b.size() : " << b.size() << endl;
	}

	//5.find()
	{
		cout << "===========================5.find()=========================" << endl;
		unordered_set<int> a{ 1,2,3,4,5,6,7 };
		cout << ">>> unordered_set<int> a{1,2,3,4,5,6,7};" << endl;
		cout << "*a.find(4) : " << *a.find(4) << endl;
	}
}