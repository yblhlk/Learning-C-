#include<iostream>
#include<queue>
#include<vector>
#include<deque>
#include<list>

using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::deque;
using std::vector;
using std::list;

int main()
{
	// queueҲ�����������������Ǳ�׼����(vector\list\deque)����ײ�����Ĭ��Ϊdeque
	// queue Ҳû�е���������Ϊ��������֧�� queue �����ԣ��Ƚ��ȳ���
	// ����
	{
		cout << "=============================����===============================" << endl;
		//ֻ�ܹ���յ�queue�����ʹ�ñ�׼����������queue
		queue<int> a;
		cout << "a.size() : " << a.size() << endl;

		deque<int> da{ 1,2,3,4,5,6 };
		queue<int> b(da);
		cout << "b.size() : " << b.size() << endl;

		list<int> la{ 1,2,3,4,5,6,7 };
		queue<int, list<int>> c(la);
		cout << "c.size() : " << c.size() << endl;

	}

	// ����
	{
		cout << "=============================����===============================" << endl;

		//empty       �������Ƿ�Ϊ��
		//size        ���ض�������ЧԪ�صĸ���
		//front       ���ض�ͷԪ�ص�����
		//back        ���ض�βԪ�ص�����
		//push        �ڶ���β�������
		//pop         �ڶ���ͷ��������
		// swap()   c++11

		queue<int> a;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		//cout << "a.front() :" << a.front() << endl; // Խ����ʣ�������
		a.push(1);
		cout << ">>>>>>>>> a.push(1);" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << "a.front() : " << a.front() << endl; //���ص������ã������޸�queue�е�����
		cout << "a.back() : " << a.back() << endl;
		a.front()++;
		cout << ">>>>>>>>> a.front()++;" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << "a.front() : " << a.front() << endl; //���ص������ã������޸�queue�е�����
		cout << "a.back() : " << a.back() << endl;
		a.push(3);
		cout << ">>>>>>>>> a.push(3);" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << "a.front(): " << a.front() << endl;
		cout << "a.back() : " << a.back() << endl;

		cout << "-------------------------------------------------" << endl;
		deque<int> da{ 1,2,3,4,5,6,7 };
		cout << "deque<int> da : {"; for (auto e : da) cout << e << ' '; cout << "}, size : "<< da.size() << endl;
		queue<int> b(da);
		cout << "queue<int> b(da);" << endl;
		cout << "b.size() : " << b.size() << endl;
		cout << "b.empty() : " << b.empty() << endl;
		cout << "b.front() : " << b.front() << endl;
		cout << "b.back() : " << b.back() << endl;
		
		b.push(9);
		cout << ">>>>>>>>>>>>> b.push(9);" << endl;
		cout << "b.size() : " << b.size() << endl;
		cout << "b.empty() : " << b.empty() << endl;
		cout << "b.front() : " << b.front() << endl;
		cout << "b.back() : " << b.back() << endl;

		b.back()--;
		cout << ">>>>>>>>>>>>> b.back()--;" << endl;
		cout << "b.size() : " << b.size() << endl;
		cout << "b.empty() : " << b.empty() << endl;
		cout << "b.front() : " << b.front() << endl;
		cout << "b.back() : " << b.back() << endl;

		b.pop();
		cout << ">>>>>>>>>>>>> b.pop();" << endl;
		cout << "b.size() : " << b.size() << endl;
		cout << "b.empty() : " << b.empty() << endl;
		cout << "b.front() : " << b.front() << endl;
		cout << "b.back() : " << b.back() << endl;
	}
	return 0;
}
