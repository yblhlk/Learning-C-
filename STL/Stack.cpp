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
//	// stack<T>�಻�Ǳ�׼����������һ������������(����ײ���һ����׼����)��stack�ĵײ���deque����
//	// stack û���˵���������Ϊ��������֧�� stack �����ԣ�����ȳ���
//	
//	// ���캯��
//	{
//		cout << "======================���캯��=======================" << endl;
//		// ֻ�ܹ���յ�stack���󣬻�ʹ�ñ�׼��������deque��vector\list��������
//		// ����յ�stack����
//		stack<int> a;
//		cout << a.size() << endl;
//		//auto it = a.rbegin(); //û�е�������
//
//		// ʹ��deque������stack
//		deque<int> da{ 1,2,3,4 };
//		stack<int> b(da);
//		cout << b.size() << endl;
//
//		// ʹ��vector������stack������Ҫ�����ײ���������
//		vector<int> va{ 1,2,3,4,5 };
//		stack<int, vector<int>> c(va); //�ڶ���ģ������ǵ����ײ���������Ϊvector
//		cout << c.size() << endl;
//	}
//
//	// ��������
//	{
//		//empty()	���stack�Ƿ�Ϊ��
//		//size()	����stack��Ԫ�صĸ���
//		//top()	    ����ջ��Ԫ�ص�����
//		//push()	��Ԫ��valѹ��stack��
//		//pop()  	��stack��β����Ԫ�ص���
//		// swap()   c++11
//
//		cout << "======================��������=======================" << endl;
//		stack<int> a;
//		cout << "size ��" << a.size() << endl;
//		cout << "empty ��" << a.empty() << endl;
//		//cout << "top ��" << a.top() << endl; //���ص������ã�֧���޸ģ�Ϊ��ʱ��Խ��
//
//		a.push(1);
//		cout << "a.push(1);" << endl;
//		cout << "size ��" << a.size() << endl;
//		cout << "empty ��" << a.empty() << endl;
//		cout << "top ��" << a.top() << endl; //���ص������ã�֧���޸�
//		++a.top(); //���ص������ã�֧���޸�
//		cout << "++a.top(); "<< endl; 
//		cout << "top ��" << a.top() << endl; //���ص������ã�֧���޸�
//
//		a.push(3);
//		cout << "a.push(3);" << endl;
//		cout << "size ��" << a.size() << endl;
//		cout << "empty ��" << a.empty() << endl;
//		cout << "top ��" << a.top() << endl; //���ص������ã�֧���޸�
//		++a.top(); //���ص������ã�֧���޸�
//		cout << "++a.top(); " << endl;
//		cout << "top ��" << a.top() << endl; //���ص������ã�֧���޸�
//
//		a.pop();
//		cout << "a.pop();" << endl;
//		cout << "size ��" << a.size() << endl;
//		cout << "empty ��" << a.empty() << endl;
//		cout << "top ��" << a.top() << endl; //���ص������ã�֧���޸�
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