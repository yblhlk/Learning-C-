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
//	// ������
//	{
//		cout << "===================������==================" << endl;
//		list<int> e; // ����һ��sizeΪ0��list����
//		cout << e.size() << endl;
//
//		list<int> a(10); //����һ��sizeΪ10��list����Ĭ�ϳ�ʼ��Ϊ0
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//
//		list<int> b(8, 1);//����һ��sizeΪ8��list����Ĭ�ϳ�ʼ��Ϊ1
//		cout << "����b:"; for (auto e : b) cout << e << "->"; cout << "null" << endl;
//		
//		list<int> c(b); //��������
//		cout << "����c:"; for (auto e : c) cout << e << "->"; cout << "null" << endl;
//
//		list<int> d(++b.begin(), --b.end()); //ʹ�õ��������й��죨ע��ǰ��++ �ͺ���++��
//		cout << "����d:"; for (auto e : d) cout << e << "->"; cout << "null" << endl;
//
//		//list�ĵ�����û�����ؼӼ������Բ��ܼ���һ�������ȥһ������ֻ��++ �� --, һ���ƶ�һ��λ��
//		list<int> f = { 1, 2, 3, 4, 5, 6 };
//		cout << *f.begin() << endl;
//		cout << *(++f.begin()) << endl; //ע��ǰ��++ �ͺ���++
//
//	}
//
//	// ʹ������������list����
//	{
//		cout << "===================ʹ������������list����==================" << endl;
//		int arr[] = { 1, 2, 3, 4, 5 };
//		int len = sizeof(arr) / sizeof(int);
//		list<int> a(arr, arr + len);  //ʹ�������ǰlenλ������list
//		cout << "����b:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//
//		// �����д�����Լ�Ϊ��
//		list<int> b = { 1, 2, 3, 4, 5, 6 };
//		cout << "����b:"; for (auto e : b) cout << e << "->"; cout << "null" << endl;
//		list<int> c{ 1, 2, 3, 4 };
//		cout << "����c:"; for (auto e : c) cout << e << "->"; cout << "null" << endl;
//	}
//
//	//operator =
//	{
//		cout << "=================== operator = ==================" << endl;
//		list<int> a{ 1,2,3,4 };
//		list<int> b;
//
//		b = a; //ΨһҪע����ǣ����ֹ���͸�ֵ
//		cout << "����b:"; for (auto e : b) cout << e << "->"; cout << "null" << endl;
//
//		// �����þ�̬������и�ֵ
//		b = { 0, 1, 2, 3, 4, 5 };
//		cout << "����b:"; for (auto e : b) cout << e << "->"; cout << "null" << endl;
//	}
//
//	//������
//	{
//		cout << "=================== ������ ==================" << endl;
//		// list�ĵ�����û�����ؼӼ�, ���Բ��� +n �� -n
//		// ֻ��++ �� --, һ���ƶ�һ��λ��(�ǳ��������������)
//		// ע��ǰ��++ �ͺ���++
//		list<int> a{ 1, 2, 3, 4, 5, 6 };
//		list<int> b(++a.begin(), --a.end()); //ʹ�õ��������й��죨ע��ǰ��++ �ͺ���++��
//		cout << "����b:"; for (auto e : b) cout << e << "->"; cout << "null" << endl;
//
//		list<int> f = { 1, 2, 3, 4, 5, 6 };
//		cout << *f.begin() << endl;
//		//cout << *(f.end()) << endl; 
//		//ע��end()��Զָ�����һ��Ԫ�ص���һ��λ�ã�ֱ�ӷ��ʻ�Խ��
//		cout << *(--f.end()) << endl;
//		cout << *(f.rbegin()) << endl;
//		cout << *(--f.rend()) << endl;
//		// ����������������������ȫ�෴�������ƶ�����
//		// ���Է��������++�������±�С�ķ����ߣ�--�������±��ķ�����
//	}
//
//	//����list����
//	{
//		cout << "=================== ����list���� ===================" << endl;
//		//list�����Ԫ��ֻ���õ����� �� front��back ������
//		//����list����ĵ�����ֻ��++��--
//		list<int> a{ 1,2,3,4,5,6 };
//		
//		// �����Բ���ʹ�� [ ] �� at() ������list������Ϊlist��֧�����ݷ���(��֧�����±����)
//		// cout << a[1] << endl;
//		//cout << a.at(1) << endl;
//
//		// ͨ������������
//		cout << *a.begin() << endl;
//		cout << *(++a.begin()) << endl; //���ʵڶ����ڵ�
//		cout << *(++ ++ a.begin()) << endl; //���ʵ������ڵ�
//
//		// ͨ��front��back������
//		// front �����ص�һ���ڵ���Ԫ�ص�����
//		// back ���������һ���ڵ���Ԫ�ص�����
//		cout << a.front() << endl;
//		a.front()++;
//		cout << a.front() << endl;
//
//		cout << a.back() << endl;
//		a.back()++;
//		cout << a.back() << endl;
//	}
//	
//	// ����list����
//	{
//		cout << "=================== ����list���� ==================" << endl;
//		//ֻ���õ�����������list����
//		list<int> a;
//		a = { 1,2,3,4,5,6,7 };
//		
//		//ʹ��list< >::iterator������list����
//		for (list<int>::iterator it = a.begin(); it != a.end(); ++it)
//		{
//			(*it)++; //++�����ȼ����� ������
//			cout << *it << "->";
//		}
//		cout << "null" << endl;
//
//		//ʹ�÷�Χfor������list����
//		// ����&�����޸�ԭ����
//		cout << "------------------��Χfor����&�����޸�ԭ����------------------" << endl;
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
//		// ��&�����޸�ԭ����
//		cout << "------------------ ��Χfor��&�����޸�ԭ���� ------------------" << endl;
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
//	//��������
//	{
//		cout << "=================== �������� ==================" << endl;
//		// size     : ������Ч�ڵ����
//		// max_size : ���ص�ǰ�ڴ��µ����ڵ����
//		// empty    : �п� ������size��
//		// clear    : ��� ����size��Ϊ0��
//		// resize   : ������Ч�ڵ�������������Ĭ��Ϊ0 ��
//
//		list<int> a{ 1,2,3,4,5,6 };
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		cout << "size:" << a.size() << endl;
//		cout << "empty:" << a.empty() << endl;
//
//		a.clear();
//		cout << "-------------------a.clear();-------------------" << endl;
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		cout << "size:" << a.size() << endl;
//		cout << "empty:" << a.empty() << endl;
//
//		a.resize(5); // ����������Ч�ڵ�������������Ĭ��Ϊ0
//		cout << "-------------------a.resize(10);-------------------" << endl;
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		cout << "size:" << a.size() << endl;
//
//		a.resize(10, 1);
//		cout << "-------------------a.resize(10, 1);-------------------" << endl;
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		cout << "size:" << a.size() << endl;
//	}
//
//	//�޸Ĳ���
//	{
//		//push front  ��list��Ԫ��ǰ����ֵΪval��Ԫ��
//		//pop_front   ɾ��list�е�һ��Ԫ��
//		//push back   ��listβ������ֵΪval��Ԫ��
//		//pop back    ɾ��list�����һ��Ԫ��
//		//insert      ��list positionλ���в���ֵΪval��Ԫ��
//		//erase       ɾ��list positionλ�õ�Ԫ��
//		//swap        ��������list�е�Ԫ��
//		//clear       ���list�е���ЧԪ��
//		cout << "=================== �޸Ĳ��� ==================" << endl;
//		list<int> a{ 1,2,3,4,5,6,7,8 };
//	//β��βɾ
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		a.push_back(9);
//		a.pop_back();	
//
//	//ͷ��ͷɾ
//		a.push_front(9);
//		a.pop_front();
//
//	//���� ��Ҫ��ϵ�������findʹ�ã�
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		cout << "----------------����--------------" << endl;
//		// �ڵ�������λ�ò���һ��Ԫ�أ�������ָ���Ԫ�ط��ڲ���Ԫ�صĺ���
//		a.insert(a.begin(), 0);
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		// <algorithm>�е�find���ص��ǲ��ҵ�Ԫ�صĵ��������Ҳ����ͷ���end()
//		auto it = find(a.begin(), a.end(), 4);
//		if (it == a.end())
//			cout << "û�и�Ԫ��!" << endl;
//		else
//		{
//			a.insert(it, 34);
//			cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		}
//
//		// �������������ֱ�Ӳ��뵽end()λ�ã����һ��Ԫ�ص���һ��λ�ã�
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		a.insert(find(a.begin(), a.end(), 0), -1);
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//
//	//ɾ�� ��Ҫ��ϵ�������findʹ�ã�
//		a.erase(a.begin());
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//
//		// find���ص��ǲ��ҵ�Ԫ�صĵ��������Ҳ����ͷ���end()
//		auto it1 = find(a.begin(), a.end(), 100);
//		if (it1 == a.end())
//			cout << "û�и�Ԫ��!" << endl;
//		else
//		{
//			a.erase(it1);
//			cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//		}
//		
//	//���� swap��ȫ��λ����������size
//		list<int> b{ 1,2,3,4,5,6,7,8 };
//		cout << "����b:"; for (auto e : b) cout << e << "->"; cout << "null, size:" << b.size() << endl;
//		a.swap(b);
//		cout << "a.swap(b);" << endl;
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//		cout << "����b:"; for (auto e : b) cout << e << "->"; cout << "null, size:" << b.size() << endl;
//	}
//
//	//��������
//	{
//		cout << "=================== �������� ==================" << endl;
//		//list������sort��reverse��unique����Ϊ�޷�ʹ��<algorithm>�еġ�
//		// std::list ����ȷʵ����ֱ��ʹ�� <algorithm> ͷ�ļ��е� std::sort() ��������������Ϊ std::sort() ��Ҫһ��������ʵ�����
//		
//		//find
//		list<int> a{ 1,2,3,4,5,6,7,8 };
//		list<int>::iterator it = find(a.begin(), a.end(), 5);
//		if (it == a.end())
//			cout << "û���ҵ���" << endl;
//		else
//		{
//			(*it)++;
//			cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null" << endl;
//		}
//
//		//sort
//		a.sort();
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//		
//		
//		// reverse() �����ˣ�����Ҳ��
//		a.reverse();
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//		reverse(a.begin(), a.end());
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//
//		// ������ȥ�أ�������
//		a.unique();
//		cout << "����a:"; for (auto e : a) cout << e << "->"; cout << "null, size:" << a.size() << endl;
//	}
//
//	//�Ƚ����������
//	{
//		cout << "=================== �Ƚ���������� ==================" << endl;
//
//		//  vector���������˱Ƚ������
//		//����������Ƚ�
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