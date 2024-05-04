#include<iostream>
#include<vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	// ������
	{
		cout << "------------------������-----------------" << endl;
		
		vector<int> a;    // �޲ι��죬�����޲ι���ͺ�������
		vector<int> b(3); // ����һ����СΪ3�ı���int��vector������Ĭ�ϳ�ʼ��Ϊ0
		for (auto e : b) cout << e << ' ';
		putchar(10);

		vector<char> c(4, 'a');  // ����һ����СΪ4�ı���char��vector������Ĭ�ϳ�ʼ��Ϊ'a'
		for (auto e : c) cout << e << ' ';
		putchar(10);

		vector<int> aa(4, 1); //����һ����СΪ4�ı���int��vector������Ĭ�ϳ�ʼ��Ϊ1
		for (auto e : aa) cout << e << ' ';
		putchar(10);

		vector<int> d(b); //��������
		for (auto e : d) cout << e << ' ';
		putchar(10);

		vector<int> e(b.begin(), b.end()-1); //ʹ�õ��������й���
		for (auto e : e) cout << e << ' ';
		putchar(10);

		
	}

	//ʹ�����еľ�̬����������vector
	{
		cout << "------------------ʹ�����еľ�̬����������vector-----------------" << endl;
		
		// ʹ�þ�̬����������
		int arr[] = { 1, 2, 3, 4 };
		int len = sizeof arr / sizeof(int);
		vector<int> a(arr, arr + len); // ����ҿ�������Ҫ arr + ���鳤��
		for (auto e : a) cout << e << ' ';
		putchar(10);

		//����д���ɼ�Ϊ
		vector<int> b = { 1, 2, 3, 4 };
		for (auto e : b) cout << e << ' ';
		putchar(10);

		vector<int> c { 1, 2, 3, 4 };
		for (auto e : c) cout << e << ' ';
		putchar(10);
		
	}

	//����=
	{
		cout << "------------------����=-----------------" << endl;
		vector<int> a(10, 2);
		vector<int> b;

		b = a; // ���ֹ���͸�ֵ��
		for (auto e : b) cout << e << ' ';
		putchar(10);

		b = { 1, 2 }; // ���԰�һ����̬���鸳ֵ��vector����
		for (auto e : b) cout << e << ' ';
		putchar(10);

		/*int c[] = { 1, 2 }; 
		b = c;*/ //������int[] ת vector
	}

	//��������vector<int>::iterator
	{
		cout << "------------------������-----------------" << endl;
		vector<int> a{ 1, 2, 3, 4, 5 };
		cout << "a���飺";
		for (auto e : a) cout << e << ' ';
		putchar(10);

		cout << "a.begin() -> " <<  * a.begin() << endl;
		//cout << *a.end() << endl; //ע��end()ָ��������һ��Ԫ�ص���һ��λ�ã�ֱ�ӷ��ʻ�Խ�硣
		cout << "a.end()-1 -> " << *(a.end() - 1) << endl;
		cout << "a.rbegin() -> " << *a.rbegin() << endl;
		//cout << *a.rend() << endl; //ע��rend()ָ����ǵ�һ��Ԫ�ص���һ��λ�ã�ֱ�ӷ��ʻ�Խ�硣
		cout << "a.rend()-1 -> " << *(a.rend() - 1) << endl;

		//      1  2  3  4  5   6
	  //  rend rend-1          rbegin
	  // ���Է��������+1�������±�С�ķ����ߣ�-1�������±��ķ����ߣ�������������෴
	}

	// ����vector���������
	{
		cout << "-----------����vector���������--------" << endl;
		vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		//����[]���������������������������vector���������
		//���ص����±�i��������,�������޸�ԭ�ַ�����
		for (int i = 0; i < a.size(); ++i)
		{
			a[i]++;
			cout << a[i] << ' ';
		}
		putchar(10);

		//at(),���ص�Ҳ���±�i��������,�������޸�ԭ�ַ�����
		for (int i = 0; i < a.size(); i++)
		{
			a.at(i)++;
			cout << a.at(i) << ' ';
		}
		putchar(10);

		// ������:vector<int>::iterator -> auto ���Ե�ָ����ʹ��
		for (vector<int>::iterator it = a.begin(); it != a.end(); ++it)
		{
			(*it)++;
			cout << *it << ' ';
		}
		putchar(10);

		// ��Χfor����&�޷��޸�ԭ����
		cout << "-----------��Χfor����&�޷��޸�ԭ����--------" << endl;
		for (auto e : a)
		{
			e++;
			cout << e << ' ';
		}
		putchar(10);
		for (auto e : a)
			cout << e << ' ';
		putchar(10);

		// ��Χfor��&�����޸�ԭ����
		cout << "-----------��Χfor��&�����޸�ԭ����--------" << endl;

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

	// ��������
	{
		cout << "------------------��������-----------------" << endl;
		//size	            ��ȡ���ݸ���
		//capacity	        ��ȡ������С
		//empty          	�ж��Ƿ�Ϊ��
		//clear          	���
		//resize���ص㣩	�ı�����size�Ĵ�С
		//reserve���ص㣩	�ı�����capacity�Ĵ�С

		vector<int> a(10, 1);
		cout << "a.size : " << a.size() << endl;
		cout << "a.capacity : " << a.capacity() << endl;
		
		cout << "------------------empty && clear-----------------" << a.empty() << endl;
		cout << "a.size :" << a.size() << endl;
		cout << "a.empty :" << a.empty() << endl;
		a.clear();
		cout << "a.clear();" << endl; //clear()ͨ����size�޸�Ϊ0�����vector����
		cout << "a.size :" << a.size() << endl;
		cout << "a.empty :" << a.empty() << endl; //emptyͨ��size==0���ж��Ƿ�Ϊ�գ�Ϊ�շ���true

		cout << "------------------resize-----------------" << endl;
		cout << "a���飺";
		for (auto e : a) cout << e << ' ';
		putchar(10);
		cout << "a.size :" << a.size() << endl;

		a.resize(1, 1); //�޸����ݸ���Ϊ1�����������1���
		cout << "a.resize(1, 1);" << endl;

		cout << "a���飺";
		for (auto e : a) cout << e << ' ';
		putchar(10);
		cout << "a.size :" << a.size() << endl;

		cout << "------------------reserve-----------------" << endl;
		cout << "a.capacity : " << a.capacity() << endl;
		a.reserve(2);
		cout << "a.reserve(2);" << endl; //������ֵС��������ǰ�� capacityʱ��ʲôҲ������������С��������
		cout << "a.capacity : " << a.capacity() << endl; 

		cout << "------------------vs�����ݻ���-----------------" << endl;
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

	// �޸Ĳ���
	{
		cout << "------------------�޸Ĳ���-----------------" << endl;
		vector<int> a{ 1, 2, 3, 4, 5 };
		vector<int> b{ 1, 2, 3, 4, 5 };
	//β��βɾ
		a.push_back(6);
		a.pop_back();
	//����
		cout << "------------------����-----------------" << endl;
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
		a.insert(a.begin(),0); //�ڵ�����������һ��0
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
		a.insert(a.begin(), 1, 1); //�ڵ�����������1��1
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
		a.insert(a.end(), b.begin(), b.end()-1); //�ڵ�����������b����[b.begin(), b.end())�ڵ�����
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);

	//ɾ��
		cout << "------------------ɾ��-----------------" << endl;
		a.erase(a.begin()); //ɾ������������һ���ַ�
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
		a.erase(a.end() - 4, a.end()); //ɾ������[a.end() - 4, a.end())�ڵ�����
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
	//�������������е�����(ȫ��λ����������size��capacity)
		cout << "------------------����-----------------" << endl;
		cout << "a���飺"; for (auto e : a) cout << e << ' '; cout << " size :" << a.size() << " capacity:" << a.capacity(); putchar(10);
		cout << "b���飺"; for (auto e : b) cout << e << ' '; cout << " size :" << b.size() << " capacity:" << b.capacity(); putchar(10);
		a.swap(b);
		cout << "a���飺"; for (auto e : a) cout << e << ' '; cout << " size :" << a.size() << " capacity:" << a.capacity(); putchar(10);
		cout << "b���飺"; for (auto e : b) cout << e << ' '; cout << " size :" << b.size() << " capacity:" << b.capacity(); putchar(10);
	}


	// find\sort\reverse\unique��������ͷ�ļ� <algorithm> ��
	// ����
	{
		cout << "------------------find<algorithm>-----------------" << endl;
		vector<int> a{ 1, 2, 3, 4, 5, 6, 1 };
		auto it = find(a.begin(), a.end(), 1); // ʹ�õ����������������
		*it = 0;
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);

		auto it1 = find(a.rbegin(), a.rend(), 1); //ʹ�÷�����������з������
		*it1 = 7;
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
	}
	
	// ����
	
	{
		cout << "------------------sort<algorithm>-----------------" << endl;
		vector<int> a{ 1, 2, 3, 4, 5, 6, 1 ,0};
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
		sort(a.begin(), a.end()); //Ĭ��������
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
		
		// bool cmp(int a, int b) { return a > b; } //Ϊ��ʱ��һ��������ǰ�档
		bool cmp(int a, int b); 
		sort(a.begin(), a.end(), cmp); //�Ž��򣬵ȼ��������д��
		sort(a.begin(), a.end(), [](int a, int b) { return a > b; });
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
	}

	// �༶���� �� ���ɼ�����
	{
		cout << "------------------�༶���� �� ���ɼ�����-----------------" << endl;
		class score {
		public:
			int c;
			int m;

			score(int c, int m) : c(c), m(m) {}

			// ���� < ���������������  
			bool operator<(const score& other) const {
				// ���c��ͬ����c�Ľ�������  
				if (this->c != other.c) {
					return this->c > other.c;
				}
				// ���c��ͬ����m�Ľ�������  
				return this->m > other.m;
			}
		};

		
		std::vector<score> scores = {
			{90, 85},
			{85, 90},
			{90, 80},
			{80, 95}
		};

		// ʹ��sort�������Զ���ıȽϺ�����������  
		std::sort(scores.begin(), scores.end());

		// ��������Ľ��  
		for (const auto& s : scores) {
			std::cout << "c: " << s.c << ", m: " << s.m << std::endl;
		}
		
	}
	
	// ��ת
	{
		cout << "------------------reverse<algorithm>-----------------" << endl;
		vector<int> a{ 1, 2, 3, 4, 5 };
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
		reverse(a.begin(), a.end());
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
	}
	// ȥ��
	{
		// unique�ǰ��������ڵ���ͬԪ����һ�����������ŵ�ĩβ��Ȼ�󷵻��޸ĺ��������ĩβ��һ������Ԫ�صĵ�����
		cout << "------------------sort+ unique = ȥ��<algorithm>-----------------" << endl;
		vector<int> a{ 5, 4, 1, 2, 1, 2, 3, 3, 4, 5, 1, 2, 3 };
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
		a.erase(unique(a.begin(), a.end()), a.end());
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);

		// ����Ҫ������������ȥ��
		sort(a.begin(), a.end());
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
		a.erase(unique(a.begin(), a.end()), a.end());
		cout << "a���飺"; for (auto e : a) cout << e << ' '; putchar(10);
	}
	
	//�Ƚ����������
	{
		cout << "-----------------�Ƚ����������-----------------" << endl;

		//vector���������˱Ƚ������
		//����������Ƚ�
		vector<int> a{ 1,2,3,4 };
		vector<int> b{ 1,2, 3, 4, 5 };

		cout << (a == b) << endl;
		cout << (a != b) << endl;
		cout << (a >= b) << endl;
		cout << (a > b) << endl;
		cout << (a <= b) << endl;
		cout << (a < b) << endl;
	}
	
	
	//��̬����vector?
	//vector��ĵײ���һ��֧�ֶ�̬����������(��new����̬�����ڴ�)�����vectorҲ����Ϊ�䳤���顣
	//���Եײ��Ѿ���������new����̬�����ˣ�û��Ҫ���һ�١�

	// ��άvector
	{
		// ��һ��
		//vector<vector<int>> data(N1, vector<int>(N2, value));
		//N1 Ϊ�У�N2 Ϊ�У�Ĭ��ֵΪ value
		vector<vector<int>> a(3, vector<int>(4, 0)); // ����һ��3��4�У�ֵ��Ϊ0�Ķ�άvector

		// ������
		// ��ֵ֪�������Ҳ����ֱ�Ӵ�����
		vector<vector<int>> arr = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };  
	}
	return 0;
}

bool cmp(int a, int b) { return a > b; }