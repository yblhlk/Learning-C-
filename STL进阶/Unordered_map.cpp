#include<iostream>
#include<unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;
using std::string;

// map : ����key ���� + ȥ��
// multimap : ����key ���򣬲�ȥ��
// unordered_map : ����key ȥ�أ�������

// unordered_mapû�з��������
// unordered_map ʹ��{}����ʱ�������ظ���key��������

int main()
{
	// 1. ���캯��
	{
		cout << "============================1. ���캯��============================" << endl;
		unordered_map<std::string, double> a;
		unordered_map<std::string, double> b(a);
		unordered_map<string, double> c(b.begin(), b.end());

		unordered_map<string, double> d = { {"tomato", 3.25}, {"potato", 0.73}, {"tomato", 4.12} };	
		cout << d.size() << endl; //unordered_map ��ȥ�أ���������
		for (auto element : d) cout << element.first << " : " << element.second << " \n"; 
		unordered_map<string, double> e = { {"banana", 2.14}, {"apple", 5.12} , {"banana", 3.25} };
		cout << e.size() << endl; //unordered_map ��ȥ��(/����ʱ������ͬ��keyֱ������)����������
		for (auto element : e) cout << element.first << " : " << element.second << " \n";
	
		//operator =
		a = d;
	}

	// 2. ����
	{
		// operator []
		// .at() //����û�е�key���ᴴ��
		// Iterator
		cout << "============================2. ����============================" << endl;
		typedef unordered_map<string, int> umapsi;
		umapsi a{ {"tomato", 3.25}, {"potato", 0.82}, {"carrot", 2.53}, {"cabbage", 1.21} };

		cout << "a[\"carrot\"] = " << a["carrot"] << endl;
		cout << "a.at(\"cabbage\") = " << a.at("cabbage") << endl;
		
		cout << "(*a.begin()).first = " << (*a.begin()).first << endl;
		cout << "(*a.begin()).second = " << (*a.begin()).second << endl;
		cout << "(*--a.end()).first = " << (*--a.end()).first << endl;
		cout << "(*--a.end()).second = " << (*--a.end()).second << endl;
		//unorderedϵ��û�з����������
		//cout << "(*--a.rend()).second = " << (*--a.rend()).second << endl; 
	}

	// 3. ���� (�ײ��ǹ�ϣ��������ģ���ָ������ʽ���������)
	{
		// ������
		// ��Χfor
		cout << "===============================3. ����=============================" << endl;
		typedef unordered_map<string, double> umapsd;
		umapsd a{ {"1cabbage", 0.91},{"2carrot", 2.53 }, {"3cabbage", 0.91},{"4potato", 1.42}, {"5tomato", 2.13}};
		//a["3cabbage"] = 20.9;
		cout << "-------------ʹ�õ���������------------" << endl;
		umapsd::iterator it = a.begin();
		unordered_map<string, double>::iterator it1 = a.begin();
		auto it2 = a.begin();
		while (it != a.end())
		{
			cout << (*it).first << " : " << (*it).second << " \n";
			++it;
		}
		cout << "------------------��Χfor----------------" << endl;
		for (auto e : a)
			cout << e.first << " : " << e.second << endl;
	}

	// 4. capacity operate
	{
		//.size()
		//.empty()
		//.clear()
		//.swap()
		cout << "===============================4. capacity operate=============================" << endl;
		unordered_map<string, double> a{ {"cabbage", 0.91}, {"carrot", 2.15},{"potato", 1.52},{"tomato", 2.51} };
		cout << "umapsd a :" << endl; for (auto e : a) { cout << "    " << e.first << " : " << e.second << endl; }
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;
		cout << ">>> a.clear();" << endl; a.clear();
		cout << "umapsd a :" << endl; for (auto e : a) { cout << "    " << e.first << " : " << e.second << endl; }
		cout << "a.size() : " << a.size() << endl;
		cout << "a.empty() : " << a.empty() << endl;

		cout << ">>> umapsd b { {\"cabbage\", 0.91}, {\"carrot\", 2.15},{\"potato\", 1.52},{\"tomato\", 2.51} };" << endl;
		unordered_map<string, double> b{ {"cabbage", 0.91}, { "carrot", 2.15 }, { "potato", 1.52 }, { "tomato", 2.51 } };;
		cout << "umapsd a :" << endl; for (auto e : a) { cout << "    " << e.first << " : " << e.second << endl; }
		cout << "a.size() : " << a.size() << endl;
		cout << "umapsd b :" << endl; for (auto e : b) { cout << "    " << e.first << " : " << e.second << endl; }
		cout << "b.size() : " << b.size() << endl;
		cout << ">>>a.swap(b);" << endl; a.swap(b);
		cout << "umapsd a :" << endl; for (auto e : a) { cout << "    " << e.first << " : " << e.second << endl; }
		cout << "a.size() : " << a.size() << endl;
		cout << "umapsd b :" << endl; for (auto e : b) { cout << "    " << e.first << " : " << e.second << endl; }
		cout << "b.size() : " << b.size() << endl;
	}

	// 5. modify operate
	{
		//.insert()
		//.erase()
		cout << "=========================5. modify operate=========================" << endl;
		unordered_map<string, double> a;
		a["carrot"] = 2.52;
		
		//insert(pair) -> insert(make_pair) -> insert({})
		std::pair<string, double> pa{ "baby_cabbage" , 1.62};
		a.insert(pa);
		a.insert(std::make_pair("cabbage", 0.91));
		a.insert({ "cucumber", 2.50 });
		a.insert({ "eggplant",3.15 });

		// insert(Iterator)
		unordered_map<string, double> b{ {"squash", 1.48}, {"summer_squash", 4.21}, {"radish", 0.92} };
		a.insert(*(++b.begin())); //������ʹ����Ϊ�������

		cout << "umapsd a :" << endl; for (auto e : a) { cout << "    " << e.first << " : " << e.second << endl; }
		cout << "a.size() : " << a.size() << endl;

		cout << ">>>a.erase(\"summer_squash\") : " << a.erase("summer_squash") << endl; //ɾ�����ɹ��򷵻�0 
		cout << ">>>a.erase(\"radish\") : " << a.erase("radish") << endl;
		cout << "umapsd a :" << endl; for (auto e : a) { cout << "    " << e.first << " : " << e.second << endl; }
		cout << "a.size() : " << a.size() << endl;

	}

	// 6. .find()
	{
		cout << "===========================.find()===========================" << endl;
		unordered_map < string, double> a;
		a.insert({ "baby_cabbage", 2.93 });
		a.insert({ "cabbage", 0.95 });
		a.insert({ "carrot", 2.51 });
		a.insert({ "cucumber", 3.21 });
		a.insert({ "eggplant", 3.29 });
		a.insert({ "potato", 1.26 });
		a.insert({ "radish", 1.52 });
		a.insert({ "summer_squash", 4.21 });
		a.insert({ "tomato", 2.84 });

		cout << ">>> a.find(\"radish\");" << endl;
		auto it = a.find("radish");
		if (it != a.end())
			cout << (*it).first << " : " << (*it).second << endl;
		else
			cout << "not found" << endl;

		cout << ">>> a.find(\"squash\");" << endl;
		auto it1 = a.find("squash");
		if (it1 != a.end())
			cout << (*it1).first << " : " << (*it1).second << endl;
		else
			cout << "not found" << endl;
	}
	return 0;
}