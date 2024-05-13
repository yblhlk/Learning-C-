#include<iostream>
#include<set> //multiset Ҳ��set�У���set�������ڣ�ֻ���򣬲�ȥ�ء�

using std::cin;
using std::cout;
using std::endl;
using std::multiset;

int main()
{
	//1.���캯��
	{
		cout << "================================1.���캯��===============================" << endl;
		multiset<int> a;   // ����һ���ն���
		multiset<int> b(a); // ��������

		//ʹ������������
		int arr[] = { 10,2,9,4,6,6 };
		multiset<int> c(arr, arr + 6);
		cout << ">>>set<int> c(arr, arr+6);" << endl;
		cout << "c.size : " << c.size() << endl;
		for (auto e : c) //set���õ�����������
			cout << e << ' ';

		//�ɼ򻯳ɣ�
		multiset<int> cc{ 1,2,3,4,5,6,17,8,9,1 };
		cout << "\n>>>multiset<int> cc{ 1,2,3,4,5,6,17,8,9,1 };" << endl;
		cout << "cc.size : " << cc.size() << endl;
		for (auto e : cc) //set���õ�����������
			cout << e << ' ';

		//ʹ�õ�����������
		multiset<int> d(c.begin(), c.end());
		cout << "\n>>>multiset<int> d(c.begin(), c.end());" << endl;
		cout << "d.size : " << d.size() << endl;
		for (auto e : d)
			cout << e << ' ';
		putchar(10);
	}

	// 2. operator =
	{
		cout << "==============================2. operator =============================" << endl;
		typedef multiset<int> si;
		int arr[] = { 1,3,4,5,7 };
		si a(arr, arr + 5);
		si b;
		b = a;

		cout << "b.size : " << b.size() << endl;
		for (auto e : b)
			cout << e << ' ';
		putchar(10);
	}

	// 3. iterators
	{
		cout << "==============================3. iterators =============================" << endl;
		multiset<int> a{ 1,2,3,4,5,6,7,8,9,10 };
		cout << *a.begin() << endl;
		cout << *(--a.end()) << endl; //ֻ��++ �� -- 
		cout << *a.rbegin() << endl;
		cout << *(--a.rend()) << endl;
	}

	//4. capacity operate
	{
		cout << "==============================4. cap  acity operate =============================" << endl;
		multiset<int> a{ 1,2,3,1 };
		cout << ">>>multiset<int> a{1,2,3,1};" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << ">>>a.clear(); " << endl;  a.clear();
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
	}

	//5. Object.swap()
	{
		cout << "==============================5. Object.swap() =============================" << endl;
		multiset<int> a;
		multiset<int> b{ 1,2,3 };
		cout << "a.size() : " << a.size() << endl;
		cout << "b.size() : " << b.size() << endl;
		cout << ">>> a.swap(b);" << endl; a.swap(b); //multiset���ܺ�set����
		cout << "a.size() : " << a.size() << endl;
		cout << "b.size() : " << b.size() << endl;
	}

	//6. Object.find()
	{
		cout << "===============================6. Object.find()==============================" << endl;
		multiset<int> a{ 1,2,3,4,5,6,7,8,9,10 };
		cout << ">>>\nmultiset<int> a{ 1,2,3,4,5,6,7,8,9,10};" << endl;

		multiset<int>::iterator it = a.find(4); //���ز��ҵ������ĵ�����
		cout << *it << endl;

		//set<int>::iterator it = a.rfind(4); //û������rfind����

	}
	return 0;
}