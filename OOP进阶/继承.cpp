//#include<iostream>
//using std::cin;
//using std::cout;
//using std::endl;
//
//// 1.是什么?
//	// 以前我们接触的复用都是函数复用，继承是类成员的复用(继承复用)
//// 2. 为什么？
//	// 学术类和老师类的例子。继承减少了代码冗余，实现类相同类成员的复用。
//// 3. 怎么做？
//	//要让一个子类进行继承父类，需要在子类的类的类名后加上冒号，并跟上继承方式和父类类名即可，比如上面的子类 Student
//
//namespace E7 {
//	class S; // 声明S让F的友元函数能找到S
//	class F
//	{
//		friend void print(const F& f, const S& s);
//	private:
//		int _fa = 1;
//	};
//
//	class S : public F
//	{
//		friend void print(const F& f, const S& s);
//	private:
//		int _sa = 2;
//	};
//
//	void print(const F& f, const S& s)
//	{
//		cout << "在基类和派生类中分别声明友元来访问两个类中的私有成员:" << endl;
//		cout << f._fa << endl;
//		cout << s._sa << endl; //基类的友元不会被派生类继承，需要在派生类中重新定义一个友元。
//	}
//}
//
//namespace E8
//{
//	class F
//	{
//	public:
//		static int _a;
//		F()
//		{
//			_a++;
//		}
//	};
//	int E8::F::_a = 0; //非const静态成员只能在类外初始化。
//	class S : public F
//	{};
//
//	class G : public S
//	{};
//	
//
//	void test()
//	{
//		// 如果基类定义了一个static静态成员，则整个继承体系共用这一个静态成员
//		E8::F f;
//		E8::S s;
//		E8::G g;
//		E8::F f2;
//
//		cout << ">>> E8::F f;" << endl;
//		cout << ">>> E8::S s;" << endl;
//		cout << ">>> E8::G g;" << endl;
//		cout << ">>> E8::F f2;" << endl;
//		cout << "F::_a : " << E8::F::_a << endl;
//		cout << "S::_a : " << E8::S::_a << endl;
//		cout << "G::_a : " << E8::G::_a << endl;
//
//		E8::F::_a = 0;
//		cout << ">>> E8::F::_a = 0;" << endl;
//		cout << "F::_a : " << E8::F::_a << endl;
//		cout << "S::_a : " << E8::S::_a << endl;
//		cout << "G::_a : " << E8::G::_a << endl;
//	}
//}
//
//
//int main()
//{
//	// 2.为什么需要继承？(学生类和老师类的例子)
//	{
//		cout << "---------------------------2.为什么需要继承？(学术类和老师类的例子----------------------------------" << endl;
//		class Person
//		{
//		public:
//			Person(std::string name = "?", size_t age = 18, unsigned long long idcard = 1)
//				:_name("not name")
//				, _age(18)
//				, _idcard(0)
//			{
//				_name = name;
//				_age = age;
//				_idcard = idcard;
//			}
//			void to_string()
//			{
//				cout << "Person { name : " << _name << ", age : " << _age << ", idcard : " << _idcard << " }" << endl;
//			}
//		protected:
//			std::string _name;
//			size_t _age;
//			unsigned long long _idcard;
//
//		};
//
//		class Student : public Person
//		{
//		public:
//			Student(std::string name = "?", size_t age = 18, unsigned long long idcard = 0)
//				//继承下来的属性不能用初始化列表初始化，因为它们已经存在。
//				//在 C++ 中，子类（派生类）的构造器可以通过初始化列表来调用父类（基类）的构造器。
//				//初始化列表在构造器的函数体执行之前执行，它用于初始化成员变量，包括从基类继承的成员变量。
//				: Person(name, age, idcard)
//			{
//				//C++ 子类对象在创建时调用父类构造器，来初始化其继承来的父类成员，然后调用子类构造器初始化对象
//				//所以C++要在初始化列表中调用父类构造器。
//
//			}
//		};
//		class Teacher : public Person
//		{
//		public:
//			Teacher(std::string name = "?", size_t age = 18, unsigned long long idcard = 0)
//				: Person(name, age, idcard)
//			{ };
//		};
//
//		Teacher t("zhang", 40, 3607221985);
//		Student s("wang", 18, 3607222001);
//		t.to_string();
//		s.to_string();
//	}
//	
//	// 3. C++ 子类对象在创建时会先调用父类构造器，然后调用子类构造器
//	{
//		cout << "\n----------------------3. C++ 子类对象在创建时会先调用父类构造器，然后调用子类构造器----------------------" << endl;
//		class A
//		{
//		public:
//			A()
//			{
//				cout << "基类的构造函数被调用." << endl;
//			}
//		};
//		class B : public A
//		{
//		public:
//			B()
//			{
//				cout << "派生类的构造函数被调用." << endl;
//			}
//			// C++中没有静态代码块和实例代码块的用法
//			/*static {
//				cout << "创建B类的对象" << endl;
//			}*/
//		};
//		
//		B b;
//	}
//
//	//4. 三种继承方式
//	{
//		cout << "\n---------------------------4. 三种继承方式-----------------------------" << endl;
//		class F
//		{
//		public:
//			int a = 999;
//		private:
//			int b = 0;
//		};
//
//		class S1 : public F
//		{
//		public:
//			S1() 
//			{
//				cout << "public继承：" << a << endl;
//				// cout << b << endl;
//				cout << "基类 private 成员在派生类中无论以什么方式继承都是不可见的。" << endl;
//				cout << "父类的private成员会被继承，但无法在子类访问（不可见），通过编译器的提示可看到" << endl;
//			}
//		};
//
//		class S2 :protected F
//		{
//		public:
//			S2()
//			{
//				cout << "protected继承：" << a << endl;
//				//cout << b << endl;
//				cout << "父类的非private成员被子类protected继承，变成了protected成员。" << endl;
//			}
//		};
//
//		cout << "使用关键字class时默认的继承方式是private，使用struct时默认的继承方式是public。" << endl << endl;
//		class S3 : F
//		{
//		public:
//			S3()
//			{
//				cout << "private继承：" << a << endl;
//				//cout << b << endl;
//				cout << "父类的非private成员被子类private继承，变成了private成员。" << endl;
//			}
//		};
//
//		S1 s1;
//		S2 s2;
//		S3 s3;
//	}
//
//	// 5. 子类和父类中的同名成员
//	{
//		cout << "\n--------------------------------5. 子类和父类中的同名成员-----------------------------------" << endl;
//		class Father
//		{
//		public:
//			int a = 0;
//		};
//		class Son : public Father
//		{
//		public:
//			int a = 1;
//		};
//
//		Son s;
//		cout << "访问子类中的成员a, s.a" << s.a << endl;
//		cout << "访问子类从父类继承来的成员a, s.Father::a" << s.Father::a << endl;
//	}
//
//	// 6.派生类中的默认成员函数
//	{
//		cout << "\n================================6.派生类中的默认成员函数===============================" << endl;
//		class F
//		{
//		public:
//			F(int a)
//				:_a(0)
//			{
//				_a = a;
//				cout << "派生类的构造函数必须调用基类的构造函数初始化基类的那一部分成员。" << endl;
//			}
//			F(const F& a)
//			{
//				cout << "派生类的拷贝构造函数必须调用基类的构造函数完成基类成员的初始化" << endl;
//				cout << "所以在实现派生类的拷贝构造函数时，必须在初始化列表中调用父类的构造函数" << endl;
//			}
//			const F& operator = (const F& f)
//			{
//				cout << "派生类的 operator=可以在函数体中调用基类的 Father::operator=" << endl;
//				cout << "所以在实现派生类的 operator=时，可以在函数体中调用基类的 operator=来给基类的成员赋值" << endl;
//				return *this;
//			}
//			~F()
//			{
//				cout << "基类的析构函数被调用" << endl;
//			}
//		private:
//			int _a;
//		};
//
//		class S : public F
//		{
//		public:
//			S(int a = 2)
//				:F(a)
//			{}
//
//			S(const S& s)
//				:F(s)
//			{
//				
//			}
//			~S()
//			{
//				cout << "派生类的析构函数被调用" << endl;
//				//在执行完派生类析构函数中的所有语句后，会默认调用基类的析构函数。
//				//派生类析构函数完成后会自动调用基类的析构函数，所以不需要我们显式调用
//			}
//
//			const S& operator = (const S& s)
//			{
//				F::operator=(s); ////调用基类的operator=完成基类成员的赋值
//				return *this;
//			}
//		};
//		cout << "》》》》》》》》》》用构造函数创建子类对象：" << endl;
//		S s;
//		cout << "》》》》》》》》》》用拷贝构造函数创建子类对象：" << endl;
//		S s2 = s;
//		cout << "》》》》》》》》》》用子类的赋值运算符重载：" << endl;
//		s2 = s;
//		cout << "》》》》》》》》》》析构函数被系统调用：" << endl;
//		cout << "派生类析构函数完成后会自动调用基类的析构函数，所以不需要我们显式调用：" << endl;
//	}
//
//	// 7.基类的友元不会被派生类继承
//	{
//		cout << "\n------------------------------7.基类的友元不会被派生类继承-----------------------------" << endl;
//		E7::print(E7::F(), E7::S()); //创建匿名对象
//	}
//
//	// 8.继承中的静态成员变量
//	{
//		cout << "\n------------------------------8.继承中的静态成员变量-----------------------------" << endl;
//		E8::test();
//		cout << "从上面可以看出如果基类定义了一个static静态成员，则整个继承体系共用这一个静态成员。" << endl;
//	}
//	return 0;
//}