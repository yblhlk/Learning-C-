//#include<iostream>
//using std::cin;
//using std::cout;
//using std::endl;
//
//// 1.��ʲô?
//	// ��ǰ���ǽӴ��ĸ��ö��Ǻ������ã��̳������Ա�ĸ���(�̳и���)
//// 2. Ϊʲô��
//	// ѧ�������ʦ������ӡ��̳м����˴������࣬ʵ������ͬ���Ա�ĸ��á�
//// 3. ��ô����
//	//Ҫ��һ��������м̳и��࣬��Ҫ�������������������ð�ţ������ϼ̳з�ʽ�͸����������ɣ�������������� Student
//
//namespace E7 {
//	class S; // ����S��F����Ԫ�������ҵ�S
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
//		cout << "�ڻ�����������зֱ�������Ԫ�������������е�˽�г�Ա:" << endl;
//		cout << f._fa << endl;
//		cout << s._sa << endl; //�������Ԫ���ᱻ������̳У���Ҫ�������������¶���һ����Ԫ��
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
//	int E8::F::_a = 0; //��const��̬��Աֻ���������ʼ����
//	class S : public F
//	{};
//
//	class G : public S
//	{};
//	
//
//	void test()
//	{
//		// ������ඨ����һ��static��̬��Ա���������̳���ϵ������һ����̬��Ա
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
//	// 2.Ϊʲô��Ҫ�̳У�(ѧ�������ʦ�������)
//	{
//		cout << "---------------------------2.Ϊʲô��Ҫ�̳У�(ѧ�������ʦ�������----------------------------------" << endl;
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
//				//�̳����������Բ����ó�ʼ���б��ʼ������Ϊ�����Ѿ����ڡ�
//				//�� C++ �У����ࣨ�����ࣩ�Ĺ���������ͨ����ʼ���б������ø��ࣨ���ࣩ�Ĺ�������
//				//��ʼ���б��ڹ������ĺ�����ִ��֮ǰִ�У������ڳ�ʼ����Ա�����������ӻ���̳еĳ�Ա������
//				: Person(name, age, idcard)
//			{
//				//C++ ��������ڴ���ʱ���ø��๹����������ʼ����̳����ĸ����Ա��Ȼ��������๹������ʼ������
//				//����C++Ҫ�ڳ�ʼ���б��е��ø��๹������
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
//	// 3. C++ ��������ڴ���ʱ���ȵ��ø��๹������Ȼ��������๹����
//	{
//		cout << "\n----------------------3. C++ ��������ڴ���ʱ���ȵ��ø��๹������Ȼ��������๹����----------------------" << endl;
//		class A
//		{
//		public:
//			A()
//			{
//				cout << "����Ĺ��캯��������." << endl;
//			}
//		};
//		class B : public A
//		{
//		public:
//			B()
//			{
//				cout << "������Ĺ��캯��������." << endl;
//			}
//			// C++��û�о�̬������ʵ���������÷�
//			/*static {
//				cout << "����B��Ķ���" << endl;
//			}*/
//		};
//		
//		B b;
//	}
//
//	//4. ���ּ̳з�ʽ
//	{
//		cout << "\n---------------------------4. ���ּ̳з�ʽ-----------------------------" << endl;
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
//				cout << "public�̳У�" << a << endl;
//				// cout << b << endl;
//				cout << "���� private ��Ա����������������ʲô��ʽ�̳ж��ǲ��ɼ��ġ�" << endl;
//				cout << "�����private��Ա�ᱻ�̳У����޷���������ʣ����ɼ�����ͨ������������ʾ�ɿ���" << endl;
//			}
//		};
//
//		class S2 :protected F
//		{
//		public:
//			S2()
//			{
//				cout << "protected�̳У�" << a << endl;
//				//cout << b << endl;
//				cout << "����ķ�private��Ա������protected�̳У������protected��Ա��" << endl;
//			}
//		};
//
//		cout << "ʹ�ùؼ���classʱĬ�ϵļ̳з�ʽ��private��ʹ��structʱĬ�ϵļ̳з�ʽ��public��" << endl << endl;
//		class S3 : F
//		{
//		public:
//			S3()
//			{
//				cout << "private�̳У�" << a << endl;
//				//cout << b << endl;
//				cout << "����ķ�private��Ա������private�̳У������private��Ա��" << endl;
//			}
//		};
//
//		S1 s1;
//		S2 s2;
//		S3 s3;
//	}
//
//	// 5. ����͸����е�ͬ����Ա
//	{
//		cout << "\n--------------------------------5. ����͸����е�ͬ����Ա-----------------------------------" << endl;
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
//		cout << "���������еĳ�Աa, s.a" << s.a << endl;
//		cout << "��������Ӹ���̳����ĳ�Աa, s.Father::a" << s.Father::a << endl;
//	}
//
//	// 6.�������е�Ĭ�ϳ�Ա����
//	{
//		cout << "\n================================6.�������е�Ĭ�ϳ�Ա����===============================" << endl;
//		class F
//		{
//		public:
//			F(int a)
//				:_a(0)
//			{
//				_a = a;
//				cout << "������Ĺ��캯��������û���Ĺ��캯����ʼ���������һ���ֳ�Ա��" << endl;
//			}
//			F(const F& a)
//			{
//				cout << "������Ŀ������캯��������û���Ĺ��캯����ɻ����Ա�ĳ�ʼ��" << endl;
//				cout << "������ʵ��������Ŀ������캯��ʱ�������ڳ�ʼ���б��е��ø���Ĺ��캯��" << endl;
//			}
//			const F& operator = (const F& f)
//			{
//				cout << "������� operator=�����ں������е��û���� Father::operator=" << endl;
//				cout << "������ʵ��������� operator=ʱ�������ں������е��û���� operator=��������ĳ�Ա��ֵ" << endl;
//				return *this;
//			}
//			~F()
//			{
//				cout << "�������������������" << endl;
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
//				cout << "���������������������" << endl;
//				//��ִ�������������������е��������󣬻�Ĭ�ϵ��û��������������
//				//����������������ɺ���Զ����û�����������������Բ���Ҫ������ʽ����
//			}
//
//			const S& operator = (const S& s)
//			{
//				F::operator=(s); ////���û����operator=��ɻ����Ա�ĸ�ֵ
//				return *this;
//			}
//		};
//		cout << "���������������������ù��캯�������������" << endl;
//		S s;
//		cout << "���������������������ÿ������캯�������������" << endl;
//		S s2 = s;
//		cout << "��������������������������ĸ�ֵ��������أ�" << endl;
//		s2 = s;
//		cout << "������������������������������ϵͳ���ã�" << endl;
//		cout << "����������������ɺ���Զ����û�����������������Բ���Ҫ������ʽ���ã�" << endl;
//	}
//
//	// 7.�������Ԫ���ᱻ������̳�
//	{
//		cout << "\n------------------------------7.�������Ԫ���ᱻ������̳�-----------------------------" << endl;
//		E7::print(E7::F(), E7::S()); //������������
//	}
//
//	// 8.�̳��еľ�̬��Ա����
//	{
//		cout << "\n------------------------------8.�̳��еľ�̬��Ա����-----------------------------" << endl;
//		E8::test();
//		cout << "��������Կ���������ඨ����һ��static��̬��Ա���������̳���ϵ������һ����̬��Ա��" << endl;
//	}
//	return 0;
//}