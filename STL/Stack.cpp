//#include<iostream>
//#include<deque>
//#include<stack>
//#include<vector>
//using std::cin;
//using std::cout;
//using std::endl;
//using std::stack;
//using std::deque;
//using std::vector;
//
//int main()
//{
//	// stack<T>类不是标准容器，而是一种容器适配器(即其底层是一个标准容器)，stack的底层是deque容器
//	// stack 没有了迭代器，因为迭代器不支持 stack 的特性（后进先出）
//	
//	// 构造函数
//	{
//		cout << "======================构造函数=======================" << endl;
//		// 只能构造空的stack对象，或使用标准容器（如deque和vector\list）来构造
//		// 构造空的stack对象
//		stack<int> a;
//		cout << a.size() << endl;
//		//auto it = a.rbegin(); //没有迭代器捏。
//
//		// 使用deque来构造stack
//		deque<int> da{ 1,2,3,4 };
//		stack<int> b(da);
//		cout << b.size() << endl;
//
//		// 使用vector来构造stack，不过要调整底层容器类型
//		vector<int> va{ 1,2,3,4,5 };
//		stack<int, vector<int>> c(va); //第二个模板参数是调整底层容器类型为vector
//		cout << c.size() << endl;
//	}
//
//	// 操作函数
//	{
//		//empty()	检测stack是否为空
//		//size()	返回stack中元素的个数
//		//top()	    返回栈顶元素的引用
//		//push()	将元素val压入stack中
//		//pop()  	将stack中尾部的元素弹出
//		// swap()   c++11
//
//		cout << "======================操作函数=======================" << endl;
//		stack<int> a;
//		cout << "size ：" << a.size() << endl;
//		cout << "empty ：" << a.empty() << endl;
//		//cout << "top ：" << a.top() << endl; //返回的是引用，支持修改，为空时会越界
//
//		a.push(1);
//		cout << "a.push(1);" << endl;
//		cout << "size ：" << a.size() << endl;
//		cout << "empty ：" << a.empty() << endl;
//		cout << "top ：" << a.top() << endl; //返回的是引用，支持修改
//		++a.top(); //返回的是引用，支持修改
//		cout << "++a.top(); "<< endl; 
//		cout << "top ：" << a.top() << endl; //返回的是引用，支持修改
//
//		a.push(3);
//		cout << "a.push(3);" << endl;
//		cout << "size ：" << a.size() << endl;
//		cout << "empty ：" << a.empty() << endl;
//		cout << "top ：" << a.top() << endl; //返回的是引用，支持修改
//		++a.top(); //返回的是引用，支持修改
//		cout << "++a.top(); " << endl;
//		cout << "top ：" << a.top() << endl; //返回的是引用，支持修改
//
//		a.pop();
//		cout << "a.pop();" << endl;
//		cout << "size ：" << a.size() << endl;
//		cout << "empty ：" << a.empty() << endl;
//		cout << "top ：" << a.top() << endl; //返回的是引用，支持修改
//
//		cout << "o--------------------------------l" << endl;
//		deque<int> da{ 1,2,3,4,5 };
//		cout << "deque<int> da : "; for (auto e : da) cout << e << ' '; cout << endl;
//		stack<int> b(da);
//		cout << "stack<int> b(da);" << endl;
//		cout << "b.top():" << b.top() << endl;
//		cout << "b.size():" << b.size() << endl;
//		b.push(6);
//		cout << "b.push(6);" << endl;
//		cout << "b.top():" << b.top() << endl;
//		cout << "b.size():" << b.size() << endl;
//		b.pop();
//		b.pop();
//		b.pop();
//		cout << "b.pop; * 3" << endl;
//		cout << "b.top():" << b.top() << endl;
//		cout << "b.size():" << b.size() << endl;
//
//		cout << "o--------------------------------l" << endl;
//		cout << "a.top():" << a.top() << endl;
//		cout << "a.size():" << a.size() << endl;
//		cout << "b.top():" << b.top() << endl;
//		cout << "b.size():" << b.size() << endl;
//		a.swap(b);
//		cout << endl << "a.swap(b)" << endl << endl;
//		cout << "a.top():" << a.top() << endl;
//		cout << "a.size():" << a.size() << endl;
//		cout << "b.top():" << b.top() << endl;
//		cout << "b.size():" << b.size() << endl;
//	}
//	return 0;
//}