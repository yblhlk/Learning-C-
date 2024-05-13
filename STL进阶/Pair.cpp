#include<iostream>
#include<string>
#include<utility>  // std::pair, std::make_pair
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::pair;



int main()
{
	// 1.���캯��
	{
		cout << "===============================1.���캯��==========================" << endl;
		pair<string, double> a;    // default constructor
		pair<string, double> b(a); // copy constructor
		pair<string, double> c("tomato", 2.15); 

		cout << a.first << " : " << a.second << "��\n";
		a.first = "potato";
		a.second = 1.23;
		cout << a.first << " : " << a.second << "��\n";
	}

	//2.��ʼ��
	{
		// ʹ��typedef��������ֱ�ӳ�ʼ��
		typedef pair<string, double> psd;
		psd a("tomato", 2.15);

		// ʹ��std::make_pair()
		psd b;
		b = std::make_pair("potato", 1.14);
	}

	//3.����
	{
		cout << "===========================3.����========================" << endl;
		//pair��һ���� struct �������ģ�壬����Ȩ��Ϊpublic������ֱ�ӷ��������ԣ�
		//a. ʹ��first���Ա��������second���Ա�����ֵ��
		pair<int, double> a(1, 1.2);
		cout << ">>>pair<int, double> a(1, 1.2);" << endl;
		cout << "a.first: " << a.first << ", a.second: " << a.second << endl;

		//b. ʹ��std::get<0>()����ȡ�����std::get<1>����ȡ��ֵ
		std::get<0>(a) = 2;
		std::get<1>(a) = 2.3;
		cout << ">>> std::get<0>(a) = 2;\n";
		cout << ">>> std::get<1>(a) = 2.3;\n";
		cout << "std::get<0>(a): " << std::get<0>(a) << ", std::get<1>(a): " << std::get<1>(a) << endl;
		cout << "a.first: " << a.first << ", a.second: " << a.second << endl;
	}

	//4.��vectorһ��ʹ�ã��γɼ�ֵ�����顣
	{
		cout << "===========================4.��vectorһ��ʹ�ã��γɼ�ֵ�����顣========================" << endl;
		typedef pair<string, double> psd;
		std::vector<psd> a;
		a.push_back(std::make_pair("potato", 1.14));
		a.push_back(std::make_pair("tomato", 2.24));

		for (int i = 0; i < a.size(); i++)
		{
			cout << a[i].first << " : " << a[i].second << ";" << endl;
		}
	}

	return 0;
}