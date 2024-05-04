#include<iostream>
#include<vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	// 构造器
	{
		cout << "------------------构造器-----------------" << endl;
		
		vector<int> a;    // 无参构造，区分无参构造和函数声明
		vector<int> b(3); // 开辟一个大小为3的保存int的vector容器，默认初始化为0
		for (auto e : b) cout << e << ' ';
		putchar(10);

		vector<char> c(4, 'a');  // 开辟一个大小为4的保存char的vector容器，默认初始化为'a'
		for (auto e : c) cout << e << ' ';
		putchar(10);

		vector<int> aa(4, 1); //开辟一个大小为4的保存int的vector容器，默认初始化为1
		for (auto e : aa) cout << e << ' ';
		putchar(10);

		vector<int> d(b); //拷贝构造
		for (auto e : d) cout << e << ' ';
		putchar(10);

		vector<int> e(b.begin(), b.end()-1); //使用迭代器进行构造
		for (auto e : e) cout << e << ' ';
		putchar(10);

		
	}

	//使用已有的静态数组来构造vector
	{
		cout << "------------------使用已有的静态数组来构造vector-----------------" << endl;
		
		// 使用静态数组来创建
		int arr[] = { 1, 2, 3, 4 };
		int len = sizeof arr / sizeof(int);
		vector<int> a(arr, arr + len); // 左闭右开，所以要 arr + 数组长度
		for (auto e : a) cout << e << ' ';
		putchar(10);

		//以上写法可简化为
		vector<int> b = { 1, 2, 3, 4 };
		for (auto e : b) cout << e << ' ';
		putchar(10);

		vector<int> c { 1, 2, 3, 4 };
		for (auto e : c) cout << e << ' ';
		putchar(10);
		
	}

	//重载=
	{
		cout << "------------------重载=-----------------" << endl;
		vector<int> a(10, 2);
		vector<int> b;

		b = a; // 区分构造和赋值。
		for (auto e : b) cout << e << ' ';
		putchar(10);

		b = { 1, 2 }; // 可以把一个静态数组赋值给vector对象
		for (auto e : b) cout << e << ' ';
		putchar(10);

		/*int c[] = { 1, 2 }; 
		b = c;*/ //不能用int[] 转 vector
	}

	//迭代器：vector<int>::iterator
	{
		cout << "------------------迭代器-----------------" << endl;
		vector<int> a{ 1, 2, 3, 4, 5 };
		cout << "a数组：";
		for (auto e : a) cout << e << ' ';
		putchar(10);

		cout << "a.begin() -> " <<  * a.begin() << endl;
		//cout << *a.end() << endl; //注意end()指向的是最后一个元素的下一个位置，直接访问会越界。
		cout << "a.end()-1 -> " << *(a.end() - 1) << endl;
		cout << "a.rbegin() -> " << *a.rbegin() << endl;
		//cout << *a.rend() << endl; //注意rend()指向的是第一个元素的下一个位置，直接访问会越界。
		cout << "a.rend()-1 -> " << *(a.rend() - 1) << endl;

		//      1  2  3  4  5   6
	  //  rend rend-1          rbegin
	  // 所以反向迭代器+1就是往下标小的方向走，-1就是往下标大的方向走，和正向迭代器相反
	}

	// 遍历vector对象的数组
	{
		cout << "-----------遍历vector对象的数组--------" << endl;
		vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		//重载[]，让我们能像访问数组那样访问vector对象的数组
		//返回的是下标i处的引用,所以能修改原字符串。
		for (int i = 0; i < a.size(); ++i)
		{
			a[i]++;
			cout << a[i] << ' ';
		}
		putchar(10);

		//at(),返回的也是下标i处的引用,所以能修改原字符串。
		for (int i = 0; i < a.size(); i++)
		{
			a.at(i)++;
			cout << a.at(i) << ' ';
		}
		putchar(10);

		// 迭代器:vector<int>::iterator -> auto 可以当指针来使用
		for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
		{
			(*it)++;
			cout << *it << ' ';
		}
		putchar(10);

		// 范围for不加&无法修改原数组
		cout << "-----------范围for不加&无法修改原数组--------" << endl;
		for (auto e : a)
		{
			e++;
			cout << e << ' ';
		}
		putchar(10);
		for (auto e : a)
			cout << e << ' ';
		putchar(10);

		// 范围for加&才能修改原数组
		cout << "-----------范围for加&才能修改原数组--------" << endl;

		for (auto& e : a)
		{
			e++;
			cout << e << ' ';
		}
		putchar(10);
		for (auto e : a)
			cout << e << ' ';
		putchar(10);
	}

	// 容量操作
	{
		cout << "------------------容量操作-----------------" << endl;
		//size	            获取数据个数
		//capacity	        获取容量大小
		//empty          	判断是否为空
		//clear          	清空
		//resize（重点）	改变设置size的大小
		//reserve（重点）	改变设置capacity的大小

		vector<int> a(10, 1);
		cout << "a.size : " << a.size() << endl;
		cout << "a.capacity : " << a.capacity() << endl;
		
		cout << "------------------empty && clear-----------------" << a.empty() << endl;
		cout << "a.size :" << a.size() << endl;
		cout << "a.empty :" << a.empty() << endl;
		a.clear();
		cout << "a.clear();" << endl; //clear()通过将size修改为0来清空vector容器
		cout << "a.size :" << a.size() << endl;
		cout << "a.empty :" << a.empty() << endl; //empty通过size==0来判断是否为空，为空返回true

		cout << "------------------resize-----------------" << endl;
		cout << "a数组：";
		for (auto e : a) cout << e << ' ';
		putchar(10);
		cout << "a.size :" << a.size() << endl;

		a.resize(1, 1); //修改数据个数为1，多出来的用1填充
		cout << "a.resize(1, 1);" << endl;

		cout << "a数组：";
		for (auto e : a) cout << e << ' ';
		putchar(10);
		cout << "a.size :" << a.size() << endl;

		cout << "------------------reserve-----------------" << endl;
		cout << "a.capacity : " << a.capacity() << endl;
		a.reserve(2);
		cout << "a.reserve(2);" << endl; //当所给值小于容器当前的 capacity时，什么也不做（不会缩小容量）。
		cout << "a.capacity : " << a.capacity() << endl; 

		cout << "------------------vs的扩容机制-----------------" << endl;
		vector<int> aa;
		int f = 0;
		for (int i = 0; i < 100; i++)
		{
			aa.push_back(0);
			if (f != aa.capacity())
			{
				f = aa.capacity();
				cout << "a.capacity : " << aa.capacity() << endl;
			}
		}
	}

	// 修改操作
	{
		cout << "------------------修改操作-----------------" << endl;
		vector<int> a{ 1, 2, 3, 4, 5 };
		vector<int> b{ 1, 2, 3, 4, 5 };
	//尾插尾删
		a.push_back(6);
		a.pop_back();
	//插入
		cout << "------------------插入-----------------" << endl;
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
		a.insert(a.begin(),0); //在迭代器处插入一个0
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
		a.insert(a.begin(), 1, 1); //在迭代器处插入1个1
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
		a.insert(a.end(), b.begin(), b.end()-1); //在迭代器处插入b容器[b.begin(), b.end())内的内容
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);

	//删除
		cout << "------------------删除-----------------" << endl;
		a.erase(a.begin()); //删除迭代器处的一个字符
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
		a.erase(a.end() - 4, a.end()); //删除容器[a.end() - 4, a.end())内的内容
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
	//交换两个容器中的内容(全方位交换：包括size和capacity)
		cout << "------------------交换-----------------" << endl;
		cout << "a数组："; for (auto e : a) cout << e << ' '; cout << " size :" << a.size() << " capacity:" << a.capacity(); putchar(10);
		cout << "b数组："; for (auto e : b) cout << e << ' '; cout << " size :" << b.size() << " capacity:" << b.capacity(); putchar(10);
		a.swap(b);
		cout << "a数组："; for (auto e : a) cout << e << ' '; cout << " size :" << a.size() << " capacity:" << a.capacity(); putchar(10);
		cout << "b数组："; for (auto e : b) cout << e << ' '; cout << " size :" << b.size() << " capacity:" << b.capacity(); putchar(10);
	}


	// find\sort\reverse\unique函数都在头文件 <algorithm> 中
	// 查找
	{
		cout << "------------------find<algorithm>-----------------" << endl;
		vector<int> a{ 1, 2, 3, 4, 5, 6, 1 };
		auto it = find(a.begin(), a.end(), 1); // 使用迭代器进行正向查找
		*it = 0;
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);

		auto it1 = find(a.rbegin(), a.rend(), 1); //使用反向迭代器进行反向查找
		*it1 = 7;
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
	}
	
	// 排序
	
	{
		cout << "------------------sort<algorithm>-----------------" << endl;
		vector<int> a{ 1, 2, 3, 4, 5, 6, 1 ,0};
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
		sort(a.begin(), a.end()); //默认排升序
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
		
		// bool cmp(int a, int b) { return a > b; } //为真时第一个参数放前面。
		bool cmp(int a, int b); 
		sort(a.begin(), a.end(), cmp); //排降序，等价于下面的写法
		sort(a.begin(), a.end(), [](int a, int b) { return a > b; });
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
	}

	// 多级排序 ： 按成绩排名
	{
		cout << "------------------多级排序 ： 按成绩排名-----------------" << endl;
		class score {
		public:
			int c;
			int m;

			score(int c, int m) : c(c), m(m) {}

			// 重载 < 运算符以用于排序  
			bool operator<(const score& other) const {
				// 如果c不同，则按c的降序排序  
				if (this->c != other.c) {
					return this->c > other.c;
				}
				// 如果c相同，则按m的降序排序  
				return this->m > other.m;
			}
		};

		
		std::vector<score> scores = {
			{90, 85},
			{85, 90},
			{90, 80},
			{80, 95}
		};

		// 使用sort函数和自定义的比较函数进行排序  
		std::sort(scores.begin(), scores.end());

		// 输出排序后的结果  
		for (const auto& s : scores) {
			std::cout << "c: " << s.c << ", m: " << s.m << std::endl;
		}
		
	}
	
	// 翻转
	{
		cout << "------------------reverse<algorithm>-----------------" << endl;
		vector<int> a{ 1, 2, 3, 4, 5 };
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
		reverse(a.begin(), a.end());
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
	}
	// 去重
	{
		// unique是把所有相邻的相同元素留一个，其他都放到末尾，然后返回修改后的容器中末尾第一个相邻元素的迭代器
		cout << "------------------sort+ unique = 去重<algorithm>-----------------" << endl;
		vector<int> a{ 5, 4, 1, 2, 1, 2, 3, 3, 4, 5, 1, 2, 3 };
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
		a.erase(unique(a.begin(), a.end()), a.end());
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);

		// 所有要先排序才能完成去重
		sort(a.begin(), a.end());
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
		a.erase(unique(a.begin(), a.end()), a.end());
		cout << "a数组："; for (auto e : a) cout << e << ' '; putchar(10);
	}
	
	//比较运算符重载
	{
		cout << "-----------------比较运算符重载-----------------" << endl;

		//vector容器重载了比较运算符
		//规则是逐个比较
		vector<int> a{ 1,2,3,4 };
		vector<int> b{ 1,2, 3, 4, 5 };

		cout << (a == b) << endl;
		cout << (a != b) << endl;
		cout << (a >= b) << endl;
		cout << (a > b) << endl;
		cout << (a <= b) << endl;
		cout << (a < b) << endl;
	}
	
	
	//动态开辟vector?
	//vector类的底层是一个支持动态增长的数组(由new来动态分配内存)，因此vector也被称为变长数组。
	//所以底层已经帮我们用new来动态开辟了，没必要多此一举。

	// 二维vector
	{
		// 法一：
		//vector<vector<int>> data(N1, vector<int>(N2, value));
		//N1 为行，N2 为列，默认值为 value
		vector<vector<int>> a(3, vector<int>(4, 0)); // 创建一个3行4列，值都为0的二维vector

		// 法二：
		// 已知值的情况下也可以直接创建：
		vector<vector<int>> arr = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };  
	}
	return 0;
}

bool cmp(int a, int b) { return a > b; }