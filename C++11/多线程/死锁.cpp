#include<iostream>
#include<mutex>
#include<thread>

using namespace std;
std::mutex mtx; // ����һ��ȫ�ֵĻ���������


int main()
{
	// 1. ����չʾһ���򵥵����������߳����������̳߳�����ͬһ������
	{
		//mtx.lock();
		//thread a([] {mtx.lock(); cout << "�ܵ����Ǹ��ط���" << endl;  mtx.unlock(); });
		//a.join(); // һ��Ҫ�ȴ�����Ȼ�����̺߳����߳�ͬʱ���С�
		//mtx.unlock();
	}

	// 2. �����������������ͬһ����
	{
		mtx.lock();
		mtx.lock();
		cout << "�ܵ����Ǹ��ط���" << endl;  
		mtx.unlock();
		mtx.unlock();
	}

	// ���������������򵥵�������������ʶ���������ͬһ�������ٸ���һ�¾��ǣ��������ٽ�������ʹ�����������
	return 0;
}