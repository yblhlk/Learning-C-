//#include<iostream>
//#include<list>
//#include<algorithm>
//using std::cin;
//using std::cout;
//using std::endl;
//using std::list;
//
//int main()
//{
//	// 构造器
//	{
//		cout << "===================构造器==================" << endl;
//		list<int> e; // 构造一个size为0的list对象
//		cout << e.size() << endl;
//
//		list<int> a(10); //构造一个size为10的list对象，默认初始化为0
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//
//		list<int> b(8, 1);//构造一个size为8的list对象，默认初始化为1
//		cout << "链表b:"; for (auto e : b) cout << e << "->"; cout << "null" << endl;
//		
//		list<int> c(b); //拷贝构造
//		cout << "链表c:"; for (auto e : c) cout << e << "->"; cout << "null" << endl;
//
//		list<int> d(++b.begin(), --b.end()); //使用迭代器进行构造（注意前置++ 和后置++）
//		cout << "链表d:"; for (auto e : d) cout << e << "->"; cout << "null" << endl;
//
//		//list的迭代器没有重载加减，所以不能加上一个数或减去一个数，只能++ 和 --, 一次移动一个位置
//		list<int> f = { 1, 2, 3, 4, 5, 6 };
//		cout << *f.begin() << endl;
//		cout << *(++f.begin()) << endl; //注意前置++ 和后置++
//
//	}
//
//	// 使用数组来创建list对象
//	{
//		cout << "===================使用数组来创建list对象==================" << endl;
//		int arr[] = { 1, 2, 3, 4, 5 };
//		int len = sizeof(arr) / sizeof(int);
//		list<int> a(arr, arr + len);  //使用数组的前len位来创建list
//		cout << "链表b:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//
//		// 上面的写法可以简化为：
//		list<int> b = { 1, 2, 3, 4, 5, 6 };
//		cout << "链表b:"; for (auto e : b) cout << e << "->"; cout << "null" << endl;
//		list<int> c{ 1, 2, 3, 4 };
//		cout << "链表c:"; for (auto e : c) cout << e << "->"; cout << "null" << endl;
//	}
//
//	//operator =
//	{
//		cout << "=================== operator = ==================" << endl;
//		list<int> a{ 1,2,3,4 };
//		list<int> b;
//
//		b = a; //唯一要注意的是：区分构造和赋值
//		cout << "链表b:"; for (auto e : b) cout << e << "->"; cout << "null" << endl;
//
//		// 还能用静态数组进行赋值
//		b = { 0, 1, 2, 3, 4, 5 };
//		cout << "链表b:"; for (auto e : b) cout << e << "->"; cout << "null" << endl;
//	}
//
//	//迭代器
//	{
//		cout << "=================== 迭代器 ==================" << endl;
//		// list的迭代器没有重载加减, 所以不能 +n 或 -n
//		// 只能++ 和 --, 一次移动一个位置(非常符合链表的特性)
//		// 注意前置++ 和后置++
//		list<int> a{ 1, 2, 3, 4, 5, 6 };
//		list<int> b(++a.begin(), --a.end()); //使用迭代器进行构造（注意前置++ 和后置++）
//		cout << "链表b:"; for (auto e : b) cout << e << "->"; cout << "null" << endl;
//
//		list<int> f = { 1, 2, 3, 4, 5, 6 };
//		cout << *f.begin() << endl;
//		//cout << *(f.end()) << endl; 
//		//注意end()永远指向最后一个元素的下一个位置，直接访问会越界
//		cout << *(--f.end()) << endl;
//		cout << *(f.rbegin()) << endl;
//		cout << *(--f.rend()) << endl;
//		// 反向迭代器和正向迭代器完全相反，包括移动方向
//		// 所以反向迭代器++就是往下标小的方向走，--就是往下标大的方向走
//	}
//
//	//访问list对象
//	{
//		cout << "=================== 访问list对象 ===================" << endl;
//		//list对象的元素只能用迭代器 或 front和back 来访问
//		//而且list对象的迭代器只能++和--
//		list<int> a{ 1,2,3,4,5,6 };
//		
//		// 很明显不能使用 [ ] 和 at() 来访问list对象，因为list不支持数据访问(不支持用下标访问)
//		// cout << a[1] << endl;
//		//cout << a.at(1) << endl;
//
//		// 通过迭代器访问
//		cout << *a.begin() << endl;
//		cout << *(++a.begin()) << endl; //访问第二个节点
//		cout << *(++ ++ a.begin()) << endl; //访问第三个节点
//
//		// 通过front和back来访问
//		// front ：返回第一个节点中元素的引用
//		// back ：返回最后一个节点中元素的引用
//		cout << a.front() << endl;
//		a.front()++;
//		cout << a.front() << endl;
//
//		cout << a.back() << endl;
//		a.back()++;
//		cout << a.back() << endl;
//	}
//	
//	// 遍历list对象
//	{
//		cout << "=================== 遍历list对象 ==================" << endl;
//		//只能用迭代器来遍历list对象
//		list<int> a;
//		a = { 1,2,3,4,5,6,7 };
//		
//		//使用list< >::iterator来遍历list对象
//		for (list<int>::iterator it = a.begin(); it != a.end(); ++it)
//		{
//			(*it)++; //++的优先级高于 解引用
//			cout << *it << "->";
//		}
//		cout << "null" << endl;
//
//		//使用范围for来遍历list对象
//		// 不加&不会修改原对象
//		cout << "------------------范围for不加&不会修改原对象------------------" << endl;
//		for (auto e : a)
//		{
//			e++;
//			cout << e << "->";
//		}
//		cout << "null" << endl;
//		for (auto e : a)
//			cout << e << "->";
//		cout << "null" << endl;
//
//		// 加&才能修改原对象
//		cout << "------------------ 范围for加&才能修改原对象 ------------------" << endl;
//		for (auto& e : a)
//		{
//			e++;
//			cout << e << "->";
//		}
//		cout << "null" << endl;
//		for (auto e : a)
//			cout << e << "->";
//		cout << "null" << endl;
//	}
//
//	//容量操作
//	{
//		cout << "=================== 容量操作 ==================" << endl;
//		// size     : 返回有效节点个数
//		// max_size : 返回当前内存下的最大节点个数
//		// empty    : 判空 （根据size）
//		// clear    : 清空 （将size设为0）
//		// resize   : 设置有效节点个数，多出来的默认为0 。
//
//		list<int> a{ 1,2,3,4,5,6 };
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		cout << "size:" << a.size() << endl;
//		cout << "empty:" << a.empty() << endl;
//
//		a.clear();
//		cout << "-------------------a.clear();-------------------" << endl;
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		cout << "size:" << a.size() << endl;
//		cout << "empty:" << a.empty() << endl;
//
//		a.resize(5); // 重新设置有效节点个数，多出来的默认为0
//		cout << "-------------------a.resize(10);-------------------" << endl;
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		cout << "size:" << a.size() << endl;
//
//		a.resize(10, 1);
//		cout << "-------------------a.resize(10, 1);-------------------" << endl;
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		cout << "size:" << a.size() << endl;
//	}
//
//	//修改操作
//	{
//		//push front  在list首元素前插入值为val的元素
//		//pop_front   删除list中第一个元素
//		//push back   在list尾部插入值为val的元素
//		//pop back    删除list中最后一个元素
//		//insert      在list position位置中插入值为val的元素
//		//erase       删除list position位置的元素
//		//swap        交换两个list中的元素
//		//clear       清空list中的有效元素
//		cout << "=================== 修改操作 ==================" << endl;
//		list<int> a{ 1,2,3,4,5,6,7,8 };
//	//尾插尾删
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		a.push_back(9);
//		a.pop_back();	
//
//	//头插头删
//		a.push_front(9);
//		a.pop_front();
//
//	//插入 （要配合迭代器或find使用）
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		cout << "----------------插入--------------" << endl;
//		// 在迭代器的位置插入一个元素，迭代器指向的元素放在插入元素的后面
//		a.insert(a.begin(), 0);
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		// <algorithm>中的find返回的是查找到元素的迭代器，找不到就返回end()
//		auto it = find(a.begin(), a.end(), 4);
//		if (it == a.end())
//			cout << "没有该元素!" << endl;
//		else
//		{
//			a.insert(it, 34);
//			cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		}
//
//		// 不做上述处理就直接插入到end()位置（最后一个元素的下一个位置）
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		a.insert(find(a.begin(), a.end(), 0), -1);
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//
//	//删除 （要配合迭代器或find使用）
//		a.erase(a.begin());
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//
//		// find返回的是查找到元素的迭代器，找不到就返回end()
//		auto it1 = find(a.begin(), a.end(), 100);
//		if (it1 == a.end())
//			cout << "没有该元素!" << endl;
//		else
//		{
//			a.erase(it1);
//			cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//		}
//		
//	//交换 swap是全方位交换，包括size
//		list<int> b{ 1,2,3,4,5,6,7,8 };
//		cout << "链表b:"; for (auto e : b) cout << e << "->"; cout << "null, size:" << b.size() << endl;
//		a.swap(b);
//		cout << "a.swap(b);" << endl;
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//		cout << "链表b:"; for (auto e : b) cout << e << "->"; cout << "null, size:" << b.size() << endl;
//	}
//
//	//其他操作
//	{
//		cout << "=================== 其他操作 ==================" << endl;
//		//list内置了sort，reverse，unique，因为无法使用<algorithm>中的。
//		// std::list 容器确实不能直接使用 <algorithm> 头文件中的 std::sort() 函数进行排序，因为 std::sort() 需要一个随机访问迭代器
//		
//		//find
//		list<int> a{ 1,2,3,4,5,6,7,8 };
//		list<int>::iterator it = find(a.begin(), a.end(), 5);
//		if (it == a.end())
//			cout << "没有找到！" << endl;
//		else
//		{
//			(*it)++;
//			cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		}
//
//		//sort
//		a.sort();
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//		
//		
//		// reverse() 内置了，外置也有
//		a.reverse();
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//		reverse(a.begin(), a.end());
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//
//		// 内置了去重，更方便
//		a.unique();
//		cout << "链表a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//	}
//
//	//比较运算符重载
//	{
//		cout << "=================== 比较运算符重载 ==================" << endl;
//
//		//  vector容器重载了比较运算符
//		//规则是逐个比较
//		list<int> a{ 1, 2, 3, 4 };
//		list<int> b{ 1, 1, 3, 4, 5 };
//	
//		cout << (a == b) << endl;
//		cout << (a != b) << endl;
//		cout << (a >= b) << endl;
//		cout << (a > b) << endl;
//		cout << (a <= b) << endl;
//	}
//	return 0;
//}