#include<iostream>
#include<map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
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
		map<string, double> a;
		map<string, double> b(a); //��������
		map<string, double> c(b.begin(), b.end());
		map<string, double, comp> d(b.begin(), b.end()); // ����������������Ƚ��ࣺҪ������Ҫдһ���Ƚ��࣬��operator()

		map<string, double> e = { {"tomato", 2.15},{"potato", 0.3} }; //����ʱ����ֵ��ʹ��{{}}
		a = c; // operator =
	}

	// 2. ���� + ��������
	{
		cout << "=============================2. ����==========================" << endl;
		map<string, double> a = { {"tomato", 2.15},{"a", 0.1} };;
		// a. ʹ��operator []������&�������ݣ��о͸��ǣ�û�оͲ������ݣ�
		a["tomato"] = 2.14;        
		a["potato"] = 0.82;
		a["apple"] = 5.21;
		a["banana"] = 2.81;
		a["apple"] = 5.00; //key��ͬ�����ݻḲ��֮ǰ�����ݣ�map��setһ����ȥ��+����

		// b. ʹ��at���������� (����Ԫ�ص����ã���at��������������ݣ�����û�е����ݲ��ᴴ�����һᱨ����
		a["watermelon"] = 0.7;
		a.at("watermelon") = 1.23; 

		// c. ʹ��insert+pair ������һ����ֵ��
		std::pair<string, double> pa("peach", 4.21); 
		a.insert(pa); 
		////��ʹ��make_pair()����������һ����ֵ��
		a.insert(std::make_pair("pear", 3.14)); 
		//��ӡ
		cout << "map a :" << endl;
		for (auto e : a) cout << e.first << " : " << e.second << endl;

		cout << ">>>map<string, double, comp> b(a.begin(), a.end();" << endl;
		cout << "map b :" << endl;
		map<string, double, comp> b(a.begin(), a.end()); //�ȽϷ�ʽ��ͬ��map����ֱ�ӿ������죬�������õ����������졣
		for (auto e : b) cout << e.first << " : " << e.second << endl;

		cout << ">>>map<string, double> c(a);" << endl;
		cout << "map c :" << endl;
		map<string, double> c(a);
		for (auto e : c) cout << e.first << " : " << e.second << endl;
	}

	// 3. ������ iterator
	{
		cout << "=============================3. ������ iterator==========================" << endl;
		map<string, double> a;
		a["tomato"] = 2.14;
		a["potato"] = 0.82;
		a["apple"] = 5.21;
		a["banana"] = 2.81;
		a["apple"] = 5.00; //key��ͬ�����ݻḲ��֮ǰ�����ݣ�map��setһ����ȥ��+����

		cout << "map a :" << endl;
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
		map<string, double> a{ {"potato", 0.8}, {"tomato", 3.12} };
		a["pear"] = 2.5;
		//a.at("watermelon") = 0.9; //atֻ��������������
		a.insert(std::make_pair("peach", 5.2));
		a.insert(std::make_pair("watermelon", 0.8));

		//a. ʹ�õ���������
		map<string, double>::iterator it = a.begin();
		cout << "map a:" << endl;
		while (it != a.end())
		{
			cout << "      " << (*it).first << " : " << (*it).second << "." << endl;
			++it;
		}
		//b. ʹ�÷�Χfor����
		cout << "map a:" << endl;
		for(auto e : a)
			cout << "      " << e.first << " : " << e.second << "." << endl;
	}

	//5.capacity operate
	{
		cout << "============================5.capacity operate=========================" << endl;
		// size
		// empty : ����size���ж�
		// clear : ��size = 0
		typedef map<string, double> msd;
		msd a{ {"potato", 0.41}, {"tomato", 4.12} };
		a["apple"] = 1.2;
		a["banana"] = 2.43;
		a.insert(std::make_pair("peach", 5.21));

		cout << "msd a:" << endl;
		for (auto e : a) cout << "     " << e.first << "->" << e.second << endl;
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << ">>>a.clear();" << endl; a.clear();
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << "msd a:" << endl;
		for (auto e : a) cout << "     " << e.first << "->" << e.second << endl;
	}

	//6.modify operate
	{
		// insert
		// erase
		// swap
		cout << "==========================6.modify operate=======================" << endl;
		cout << "--------------------------------erase---------------------------" << endl;
		typedef map<string, double> msd;
		msd a = { {"potato", 0.42}, {"tomato", 3.21} };
		a["watermelon"] = 0.9;
		cout << "msd a : " << endl;
		for (auto e : a) cout << "      " << e.first << " : " << e.second << endl;
		cout << ">>>a.erase(\"watermelon\");" << endl; a.erase("watermelon");
		cout << "msd a : " << endl;
		for (auto e : a) cout << "      " << e.first << " : " << e.second << endl;

		cout << "--------------------------------swap---------------------------" << endl;
		msd b;
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