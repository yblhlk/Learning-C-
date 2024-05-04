//#include<iostream>
//#include<string>
//using std::cin;
//using std::cout;
//using std::endl;
//using std::string;
//
//int main()
//{
//	std::ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	
//	// string类的构造函数
//	{
//		//string() （重点）	构造空的string类对象，即空字符
//		//string(const char* s) （重点）	用字符数组来构造string类对象
//		//string(const string & s) （重点）	拷贝构造函数
//		//string(size_t n, char c)	用n个c字符来构造string类对
//		cout << "----------string类的构造函数---------" << endl;
//		string a; 
//		//string a(); 不是在调用构造器创建一个空的string对象，而是在声明一个返回值为string的无参函数。
//		string b("abcd");  //使用字符数组构造
//		string c(b);  //拷贝构造
//		string d(3, 'a');
//
//		const char* e = "abcdefg";
//		string f(e);
//		char g[] = { 'a', 'b' }; //char数组结尾一定要加一个'\0'
//		string h(g);
//
//		cout << a << endl;
//		cout << b << endl;
//		cout << c << endl;
//		cout << d << endl;
//		cout << e << endl;
//		cout << f << endl;
//		cout << g << endl;
//		cout << h << endl;
//	}
//
//	// 赋值运算符重载
//	{
//		//string& operator= (const string & str);
//		//string & operator= (const char* s);
//		//string& operator= (char c);
//		cout << "----------赋值运算符重载---------" << endl;
//		
//		string a("abcdefg");
//		string b = a;  //区分构造和赋值，这里b还没有创建所以调用的是构造函数
//		
//		b = a;  //这里b已经创建，所以调用的是赋值运算符重载
//		cout << b << endl;
//		b = "abcd";
//		cout << b << endl;
//		b = 'a';
//		cout << b << endl;
//	}
//
//	// 有关容量的操作
//	{
//		//	size（重点）	返回字符串有效字符长度
//		//	length	        返回字符串有效字符长度
//		//	capacity	    返回空间总大小
//		//	empty（重点）	检测字符串是否为空串，是返回true，否则返回false
//		//	clear（重点）	清空有效字符
//		//	reserve（重点）	为字符串预留空间
//		//	resize（重点）	设置字符串长度，用指定字符填充多出来的位置
//		cout << "-----------有关容量的操作---------" << endl;
//		string a("abcdefg");
//		cout << a.size() << endl;
//		cout << a.length() << endl;
//		cout << a.capacity() << endl;
//
//		// 判空：根据size()判断
//		cout << a.empty() << endl;
//		// 不同于字符数组是以'\0'来判断结尾，stirng对象判断字符串的结尾是根据size属性。
//
//		// 清空字符串：修改size()
//		a.clear();
//		cout << "a.clear();" << endl;
//		cout << a.size() << endl;
//		cout << a.empty() << endl;
//
//		// 为stirng对象预留空间，修改capacity = n + 1;
//		a.reserve(30);
//		cout << "a.reserve(30);" << endl;
//		cout << a.capacity() << endl;
//		cout << a.size() << endl;
//
//		// 设置string对象的有效长度，多出来的长度默认用'\0'填充
//		cout << a << " 的长度： " << a.size() << endl;
//		a.resize(10);
//		cout << "a.resize(20);" << endl;
//		cout << a << " 的长度： " << a.size() << endl;
//		a.resize(20, '.');
//		cout << "a.resize(20, '.');" << endl;
//		cout << a << " 的长度： " << a.size() << endl;
//		cout << "string对象是以size来判断结尾的，看不到的字符可能是'\0'";
//	}
//
//	//访问string对象的字符数组
//	{
//		cout << "---------访问string对象的字符数组--------" << endl;
//		string a;
//		a = "abcd";
//
//		cout << a << endl; //重载<< 让我们能自己打印string对象的内容。
//
//		cout << a[0] << endl;
//		cout << a.at(1) << endl;
//		cout << *a.begin() << endl;
//		cout << *(a.begin() + 2) << endl;
//
//		string::iterator it = a.end()-1;
//		cout << *it << endl;
//	}
//
//	//遍历string对象的字符数组
//	{
//		cout << "---------遍历string对象的字符数组--------" << endl;
//		string a("abcdefghijklmn");
//
//		cout << "operator [ ]和at() 返回的是string对象的字符数组的i下标处的引用。" << endl;
//		cout << "使用[]遍历string对象的字符串" << endl;
//		for (int i = 0; i < a.size(); i++)
//		{
//			//operator [ ]返回的是string对象的字符数组的i下标处的引用。
//			a[i]++;
//			cout << a[i];
//		}	
//		putchar(10);
//
//		cout << "使用at()遍历string对象的字符串" << endl;
//		for (int i = 0; i < a.size(); i++)
//		{
//			// at() 返回的也是string对象的字符数组的i下标处的引用
//			a.at(i)++;
//			cout << a.at(i);
//		}
//		putchar(10);
//
//		cout << "使用迭代器遍历string对象的字符串" << endl;
//		for (string::iterator i = a.begin(); i != a.end(); i++)
//		{
//			(*i)++; //++的优先级大于*，所以要使用（）
//			cout << *i;
//		}
//		putchar(10);
//
//		string::iterator it = a.begin();
//		while (it != a.end())
//		{
//			(*it)++;
//			cout << *it;
//			it++;    //如果会忘记写it++，建议使用for循环
//		}
//		putchar(10);
//
//		cout << "使用范围for+迭代器遍历string对象的字符串" << endl;
//		//不使用&的范围for是无法修改原数组的
//		cout << "a. 使用范围for访问，不用加&" << endl;
//		for (auto e : a)
//		{
//			e++; //这里的e不过是一个临时变量。
//			cout << e;
//		}
//		putchar(10);
//		cout << a << endl;
//
//		//使用&的范围for才能修改原数组的
//		cout << "b. 使用范围for修改，要加&" << endl;
//		for (auto& e : a)
//		{
//			e++;
//			cout << e;
//		}
//		putchar(10);
//		cout << a << endl;
//	}
//
//
//	//string对象的修改
//	{
//		cout << "-----------string对象的修改-----------" << endl;
//	//追加
//		//operator+=(重点)	在字符串后追加字符串/string对象/字符
//		//push_back	        在字符串后尾插字符
//		//append(重点)     	在字符串后追加一个字符串
//		cout << "-----------追加-----------" << endl;
//		string a("abc");
//		a += 'd';
//		a += "efg";
//		string b("hij");
//		a += b;
//		cout << a << endl;
//
//		a.push_back('k'); // 只能尾插一个字符。
//		//a.push_back("lmn");
//
//		a.append("lmn");
//		string c("opq");
//		a.append(c);
//		cout << a << endl;
//
//		a.append("rstuvw", 3); // 尾插一个字符串，取其前3个字符
//		cout << a << endl;
//		a.append("rstuvwxyz123", 3, 6); // 尾插一个字符串，从下标3开始，取其前6个字符
//		cout << a << endl;
//		a.append(3, ' '); //尾插3个' '字符
//		cout << a << endl;
//
//
//	//插入 insert
//		cout << "-----------插入-----------" << endl;
//		a = "abcdefghijklmnopqrstuvwxyz  ";
//		a.insert(0, "123"); // 在0下标处插入一个字符串
//		cout << a << endl;
//		a.insert(3, "456789", 3); // 在3下标处插入，一个字符串的前3个字符
//		cout << a << endl;
//		a.insert(6, "4567891011", 3, 5); //在6下标处插入，一个字符串从下标3开始的5个字符
//		cout << a << endl;
//
//	//删除 erase
//		cout << "-----------删除-----------" << endl;
//		a = "12345678910abcdefghijklmnopqrstuvwxyz   .";
//		a.erase(37, 3); //删除下标37开始的3个字符
//		cout << a << endl;
//		a.erase(10); //删除下标10后的所有字符
//		cout << a << endl;
//		a.erase(a.begin() + 9); //删除下标为9的字符
//		cout << a << endl;
//
//	}
//
//	//string对象的常用操作
//	{
//		//c_str(重点) 返回C格式字符串
//		//ﬁnd(重点)	  从前往后查找子串，返回起始位置的下标
//		//rﬁnd	      从后往前查找子串，返回起始位置的下标
//		//substr	  截取子串，并返回一个string对象
//		cout << "---------------------------" << endl;
//		string a;
//		a = "abcdefgdefg";
//		cout << a.c_str() << endl;
//
//		cout << a.find("defg") << endl; //找到就返回在主串中起始位置的下标
//		if (a.find("defgh") == string::npos) //找不到返回string::npos(约为42亿9千万)
//			cout << "未找到" << endl;
//
//		cout << a.rfind("defg") << endl; //从后往前找。
//		cout << a.rfind("defg", 3) << endl; //从第4个字符开始，从后往前找。
//		cout << a.rfind("defg", 2) << endl; //从第3个字符开始，从后往前找。
//
//
//		a = "abcdefgdefg";
//		cout << a.substr(1) << endl;        //从下标1的字开始截取到结尾
//		cout << a.substr(1).size() << endl; 
//
//		cout << a.substr(0, 3) << endl;     //从下标0的字开始截取3个字符
//	}
//
//	//string对象和数字间的转换
//	{
//		//to_string()函数：将数字转为字符串
//		cout << "---------------------------" << endl;
//		double a = 1234.5678;
//		string s = std::to_string(a);
//		cout << s << endl;
//
//		//stoi()：将字符串转为整数
//		int b = stoi(s);
//		cout << b << endl;
//
//		//stod()：将字符串转为浮点数
//		double c = std::stod(s);
//		printf("%lf\n", c);  //注意cout默认输出两位小数，所以在输出浮点数时最好使用printf()
//
//		//atoi()：将字面字符串转为整数
//		const char* ss = "2345678";
//		b = atoi(ss);
//		cout << b << endl;
//		//atof()：将字面字符串转为浮点数
//		c = atof("1234.5678");
//		printf("%f\n", c);
//	}
//
//
//	// operator +
//	{
//		cout << "---------------------------" << endl;
//		string firstlevel("com");
//		string secondlevel("cplusplus");
//		string scheme("http://");
//		string hostname;
//		string url;
//
//		hostname = "www." + secondlevel + '.' + firstlevel;
//		url = scheme + hostname;
//
//		std::cout << "网址：" + url + '\n';
//	}
//	// 比较运算符：逐个按ASCII码比较
//	{
//		cout << "---------------------------" << endl;
//		string s1 = "abcd";
//		string s2 = "abcde";
//		cout << (s1 == "a") << endl;
//
//		cout << (s1 > s2) << endl;
//		cout << (s1 >= "abcd") << endl;
//		
//		cout << (s1 < s2) << endl;
//		cout << (s1 <= s2) << endl;
//
//	}
//
//	// 按行输入 : getline(cin, str)
//	{
//		cout << "---------------------------" << endl;
//		string str;
//		getline(cin, str, '.'); //按行输入，指定以.结束。
//		cout << str << endl;
//	}
//
//	// 练习1：实现字符串替换函数：
//	{
//		// 法一：倒着找到后先删除后插入
//		string s1("hello world lin");
//		for (int i = s1.size(); i >= 0; i--)
//		{
//			if (s1[i] == ' ')
//			{
//				s1.erase(i, 1);
//				s1.insert(i, "%20");
//			}
//		}
//		// 法二：开一个新字符串
//		string s2;
//		for (int i = 0; i < s1.size(); i++)
//		{
//			if (s1[i] == ' ')
//				s2 += "20%";
//			else
//				s2 += s1[i];
//		}
//		cout << s1 << endl;
//		cout << s2 << endl;
//	}
//
//	// 练习2：获取文件后缀
//	{
//		// 用find找子串，用substr获取子串。
//		string file_path = "test.cpp.zip.tar";
//		size_t index = file_path.find(".");
//		size_t index1 = file_path.rfind("."); // 从结尾开始找
//		string suffix = file_path.substr(index);
//		string suffix1 = file_path.substr(index1);
//		cout << "使用find获取文件所有后缀：" << suffix << endl;
//		cout << "使用rfind获取文件真后缀：" << suffix1 << endl;
//	}
//
//	// C++中涉及到char*的操作以'\0'为结尾，涉及string的操作以size的长度算结尾。
//	{
//		cout << "---------------------------" << endl;
//		string s3 = "asdfg ";
//		s3 += '\0';
//		s3 += "hjkl";
//		cout << s3 << endl;
//		cout << s3.c_str() << endl;
//
//		string s4 = s3;
//		cout << s4 << endl;
//	}
//	return 0;
//}