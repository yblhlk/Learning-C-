#include<iostream>
//���ȶ�����ͷ�ļ�<queue>��
#include<queue>
#include<vector>
#include<deque>
#include<list>
#include<functional>


// ���ȼ����� priority_queue Ҳ����������������ײ�����Ĭ��Ϊ vector��class Container = vector<T>����������ģ������Ƿº���
// Ĭ������� priority_queue �Ǵ�ѣ�������
using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
using std::deque;

int main()
{
	//����
	{
		cout << "========================����=======================" << endl;
		// ����ն���
		priority_queue<int> a;
		cout << a.size() << endl;

		// ʹ�ø��ֱ�׼�����ĵ����������� (���еĹ��췽��������queueû�����ֹ��췽��)
		std::vector<int> va{ 1,2,3,4,5 };
		priority_queue<int> b(va.begin(), va.end());
		cout << b.size() << endl;

		std::deque<int> da{ 1,2,3,4,5,6 };
		priority_queue<int> c(da.begin(), da.end());
		cout << c.size() << endl;

		std::list<int> la{ 1,2,3,4,5,6,7 };
		priority_queue<int> d(la.begin(), la.end());
		cout << d.size() << endl;

		// ʹ�����������죨���ܼ�д��
		int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
		int len = sizeof(arr) / sizeof(int);
		priority_queue<int> f(arr, arr + len);
		cout << f.size() << endl;

		// �������� C++11
		priority_queue<int> e(d); 
		cout << e.size() << endl;
	}

	// ����
	{
		cout << "=========================����======================" << endl;
		//size()	�������ȼ���������ЧԪ�صĸ���
		//empty()	������ȼ������Ƿ�Ϊ�գ��Ƿ���true�����򷵻�false
		//top()	    �������ȼ����������(��СԪ��)�����Ѷ�Ԫ�ص�const ���ò����޸�
		//push(x)	�����ȼ������в���Ԫ��x
		//pop()	    ɾ�����ȼ����������(��С)Ԫ�أ����Ѷ�Ԫ
		// swap()   c++11
		priority_queue<int> a;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		a.push(10);
		cout << ">>>>>>>>>>>>>>> a.push(10);" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.top() : " << a.top() << endl;
		a.push(0);
		cout << ">>>>>>>>>>>>>>> a.push(0);" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.top() : " << a.top() << endl;
		a.push(20);
		cout << ">>>>>>>>>>>>>>> a.push(20);" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.top() : " << a.top() << endl;
		
		//a.top() -= 19; //���ص���const���ò����޸�ֵ
		
		a.pop(); // pop()û�з���ֵ
		cout << ">>>>>>>>>>>>>>> a.pop();" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.top() : " << a.top() << endl;

		priority_queue<int> b;
		cout << ">>>>>>>>>>>>>>> priority_queue<int>b;" << endl;
		b.push(100);
		cout << ">>>>>>>>>>>>>>> b.push(100);" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.top() : " << a.top() << endl;
		cout << "b.size() : " << b.size() << endl;
		cout << "b.top() : " << b.top() << endl;
		a.swap(b); //ȫ��λ�������������ݣ�size
		cout << ">>>>>>>>>>>>>>> a.swap(b);" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.top() : " << a.top() << endl;
		cout << "b.size() : " << b.size() << endl;
		cout << "b.top() : " << b.top() << endl;
	}

	// ����С��
	{
		cout << "======================����С��====================" << endl;
		//�����������Ƿº���������������ʹ��std::greater<int>
		//std::greater<int> ��ͷ�ļ�<functional>�¡�
		priority_queue<int, std::vector<int>, std::greater<int>> a;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		a.push(10);
		cout << ">>>>>>>>>>>>>>> a.push(10);" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.top() : " << a.top() << endl;
		a.push(0);
		cout << ">>>>>>>>>>>>>>> a.push(0);" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.top() : " << a.top() << endl;
		a.push(20);
		cout << ">>>>>>>>>>>>>>> a.push(20);" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.top() : " << a.top() << endl;
		a.push(-1);
		cout << ">>>>>>>>>>>>>>> a.push(-1);" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.top() : " << a.top() << endl;

		std::vector<int> va{ 1,2,3,4,5,6,7,8,9,0 };
		cout << "vector<int> va : {"; for (auto e : va) cout << e << ' '; cout << "}, size() : " << va.size() << endl;
		priority_queue<int, std::vector<int>, std::greater<int>> b(va.begin(), va.end());
		cout << "priority_queue<int, vector<int>, greater<int>> b(va.begin(), va.end());" << endl;
		for (int i = 0; i < va.size(); ++i)
		{
			cout << "b.size() : " << b.size() << endl;
			cout << "b.top() : " << b.top() << endl;
			b.pop();
			cout << ">>>>>>>>>>> b.pop();" << endl;
		}
		cout << "b.size() : " << b.size() << endl;
		//cout << "b.top() : " << b.top() << endl; //size==0��Խ�磬������
	}
	return 0;
}