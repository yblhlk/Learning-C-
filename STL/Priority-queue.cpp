#include<iostream>
//优先队列在头文件<queue>中
#include<queue>
#include<vector>
#include<deque>
#include<list>
#include<functional>


// 优先级队列 priority_queue 也是容器适配器，其底层容器默认为 vector（class Container = vector<T>），第三个模板参数是仿函数
// 默认情况下 priority_queue 是大堆（即降序）
using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
using std::deque;

int main()
{
	//构造
	{
		cout << "========================构造=======================" << endl;
		// 构造空对象
		priority_queue<int> a;
		cout << a.size() << endl;

		// 使用各种标准容器的迭代器来构造 (特有的构造方法，至少queue没有这种构造方法)
		std::vector<int> va{ 1,2,3,4,5 };
		priority_queue<int> b(va.begin(), va.end());
		cout << b.size() << endl;

		std::deque<int> da{ 1,2,3,4,5,6 };
		priority_queue<int> c(da.begin(), da.end());
		cout << c.size() << endl;

		std::list<int> la{ 1,2,3,4,5,6,7 };
		priority_queue<int> d(la.begin(), la.end());
		cout << d.size() << endl;

		// 使用数组来构造（不能简写）
		int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
		int len = sizeof(arr) / sizeof(int);
		priority_queue<int> f(arr, arr + len);
		cout << f.size() << endl;

		// 拷贝构造 C++11
		priority_queue<int> e(d); 
		cout << e.size() << endl;
	}

	// 操作
	{
		cout << "=========================操作======================" << endl;
		//size()	返回优先级队列中有效元素的个数
		//empty()	检测优先级队列是否为空，是返回true，否则返回false
		//top()	    返回优先级队列中最大(最小元素)，即堆顶元素的const 引用不可修改
		//push(x)	在优先级队列中插入元素x
		//pop()	    删除优先级队列中最大(最小)元素，即堆顶元
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
		
		//a.top() -= 19; //返回的是const引用不能修改值
		
		a.pop(); // pop()没有返回值
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
		a.swap(b); //全方位交换，包括内容，size
		cout << ">>>>>>>>>>>>>>> a.swap(b);" << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.top() : " << a.top() << endl;
		cout << "b.size() : " << b.size() << endl;
		cout << "b.top() : " << b.top() << endl;
	}

	// 创建小堆
	{
		cout << "======================创建小堆====================" << endl;
		//第三个参数是仿函数，这里我们先使用std::greater<int>
		//std::greater<int> 在头文件<functional>下。
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
		//cout << "b.top() : " << b.top() << endl; //size==0，越界，报错捏。
	}
	return 0;
}