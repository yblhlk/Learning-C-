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
	// queue也是容器适配器，不是标准容器(vector\list\deque)，其底层容器默认为deque
	// queue 也没有迭代器，因为迭代器不支持 queue 的特性（先进先出）
	// 构造
	{
		cout << "=============================构造===============================" << endl;
		//只能构造空的queue对象或使用标准容量来构造queue
		queue<int> a;
		cout << "a.size() : " << a.size() << endl;

		deque<int> da{ 1,2,3,4,5,6 };
		queue<int> b(da);
		cout << "b.size() : " << b.size() << endl;

		list<int> la{ 1,2,3,4,5,6,7 };
		queue<int, list<int>> c(la);
		cout << "c.size() : " << c.size() << endl;

	}

	// 操作
	{
		cout << "=============================操作===============================" << endl;

		//empty       检测队列是否为空
		//size        返回队列中有效元素的个数
		//front       返回队头元素的引用
		//back        返回队尾元素的引用
		//push        在队列尾部入队列
		//pop         在队列头部出队列
		// swap()   c++11

		queue<int> a;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		//cout << "a.front() :" << a.front() << endl; // 越界访问，报错捏。
		a.push(1);
		cout << ">>>>>>>>> a.push(1);" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << "a.front() : " << a.front() << endl; //返回的是引用，可以修改queue中的内容
		cout << "a.back() : " << a.back() << endl;
		a.front()++;
		cout << ">>>>>>>>> a.front()++;" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << "a.front() : " << a.front() << endl; //返回的是引用，可以修改queue中的内容
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
