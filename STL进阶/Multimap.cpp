#include<iostream>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::map;      // ���� + ȥ��
using std::multimap; // ֻ���򣬲�ȥ��
using std::string;

class comp
{
public:
	bool operator()(const string& a, const string& b) const
	{
		return a > b;
	}
};

int main()
{
	// 1. ���캯��
	{
		multimap<string, double> a;
		multimap<string, double> b(a); //��������
		multimap<string, double> c(b.begin(), b.end());
		multimap<string, double, comp> d(b.begin(), b.end()); // ����������������Ƚ��ࣺҪ������Ҫдһ���Ƚ��࣬��operator()

		multimap<string, double> e = { {"tomato", 2.15},{"potato", 0.3} }; //����ʱ����ֵ��ʹ��{{}}
		a = c; // operator =
	}

	// 2. ���� + ��������
	{
		//multimap��û��  operator[] �� .at()����Ϊ multimap �� Key ���ܲ�Ψһ

		cout << "=============================2. ����==========================" << endl;
		multimap<string, double> a = { {"tomato", 2.15},{"a", 0.1} };
		

		// a. ʹ��insert+pair ������һ����ֵ��
		std::pair<string, double> pa("peach", 4.21);
		a.insert(pa);
		////��ʹ��make_pair()����������һ����ֵ��
		a.insert(std::make_pair("pear", 3.14));
		
		//��ӡ
		cout << "multimap a :" << endl;
		for (auto e : a) cout << e.first << " : " << e.second << endl;

		cout << ">>>map<string, double, comp> b(a.begin(), a.end();" << endl;
		cout << "multimap b :" << endl;
		multimap<string, double, comp> b(a.begin(), a.end()); //�ȽϷ�ʽ��ͬ��map����ֱ�ӿ������죬�������õ����������졣
		for (auto e : b) cout << e.first << " : " << e.second << endl;

		cout << ">>>map<string, double> c(a);" << endl;
		cout << "multimap c :" << endl;
		multimap<string, double> c(a);
		for (auto e : c) cout << e.first << " : " << e.second << endl;
	}

	// 3. ������ iterator
	{
		cout << "=============================3. ������ iterator==========================" << endl;
		multimap<string, double> a = { {"tomato", 2.15},{"potato", 0.43} };
		// a["tomato"] = 2.14;  // multimap��֧�� operator[] ��Ϊ�����ܻ��ظ�
		//��multimap��key��ͬ�����ݲ��Ḳ��֮ǰ�����ݣ���������һ����ֵ��
		a.insert(std::make_pair("tomato", 3.41));

		cout << "multimap a :" << endl;
		for (auto e : a) cout << "       " << e.first << " : " << e.second << endl;

		// map������+ȥ�أ�����begin()���ص��������ĵ�һ��Ԫ�صĵ�������
		cout << "a.begin() -> " << (*a.begin()).first << " : " << (*a.begin()).second << endl;
		cout << "--a.end() -> " << (*--a.end()).first << " : " << (*--a.end()).second << endl;
		cout << "a.rbegin() -> " << (*a.rbegin()).first << " : " << (*a.rbegin()).second << endl;
		cout << "--a.rend() -> " << (*--a.rend()).first << " : " << (*--a.rend()).second << endl;

	}

	// 4.����
	{
		cout << "============================4.����===========================" << endl;
		multimap<string, double> a{ {"potato", 0.8}, {"tomato", 3.12} };
		//a.at("watermelon") = 0.9; //atֻ��������������
		a.insert(std::make_pair("peach", 5.2));
		a.insert(std::make_pair("watermelon", 0.8));
		a.insert(std::make_pair("tomato", 4.12));
		a.insert(std::make_pair("potato", 1.21));

		//a. ʹ�õ���������
		multimap<string, double>::iterator it = a.begin();
		cout << "multimap a:" << endl;
		while (it != a.end())
		{
			cout << "      " << (*it).first << " : " << (*it).second << "." << endl;
			++it;
		}
		//b. ʹ�÷�Χfor����
		cout << "multimap a:" << endl;
		for (auto e : a)
			cout << "      " << e.first << " : " << e.second << "." << endl;
	}

	//5.capacity operate
	{
		cout << "============================5.capacity operate=========================" << endl;
		// size
		// empty : ����size���ж�
		// clear : ��size = 0
		typedef multimap<string, double> mmsd;
		mmsd a{ {"potato", 0.41}, {"tomato", 4.12} };
		a.insert(std::make_pair("apple", 4.26));
		a.insert(std::make_pair("banana", 2.59));
		a.insert(std::make_pair("peach", 5.21));
		a.insert(std::make_pair("apple", 6.26));

		cout << "mmsd a:" << endl;
		for (auto e : a) cout << "     " << e.first << "->" << e.second << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << ">>>a.clear();" << endl; a.clear();
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << "mmsd a:" << endl;
		for (auto e : a) cout << "     " << e.first << "->" << e.second << endl;
	}

	//6.modify operate
	{
		// insert
		// erase : ɾ�����м�ƥ��ļ�ֵ��
		// swap
		cout << "==========================6.modify operate=======================" << endl;
		cout << "--------------------------------erase---------------------------" << endl;
		typedef multimap<string, double> mmsd;
		mmsd a = { {"potato", 0.42}, {"tomato", 3.21} };
		a.insert(std::make_pair("watermelon", 0.63));
		a.insert(std::make_pair("watermelon", 0.83));
		cout << "mmsd a : " << endl;
		for (auto e : a) cout << "      " << e.first << " : " << e.second << endl;
		cout << ">>>a.erase(\"watermelon\");" << endl; a.erase("watermelon"); //ɾ�����м�ƥ��ļ�ֵ��
		cout << "mmsd a : " << endl;
		for (auto e : a) cout << "      " << e.first << " : " << e.second << endl;

		cout << "--------------------------------swap---------------------------" << endl;
		mmsd b;
		cout << "msd a.size() : " << a.size() << endl;
		for (auto e : a) cout << "      " << e.first << " : " << e.second << endl;
		cout << "msd b.size() : " << b.size() << endl;
		for (auto e : b) cout << "      " << e.first << " : " << e.second << endl;
		cout << ">>> b.swap(a);" << endl;  b.swap(a);
		cout << "msd a.size() : " << a.size() << endl;
		for (auto e : a) cout << "      " << e.first << " : " << e.second << endl;
		cout << "msd b.size() : " << b.size() << endl;
		for (auto e : b) cout << "      " << e.first << " : " << e.second << endl;
	}
	return 0;
}