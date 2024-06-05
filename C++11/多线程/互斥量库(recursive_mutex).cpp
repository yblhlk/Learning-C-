// recursive_mutex : �ݹ黥���������ڵݹ麯����������
// ������ͬһ���̶߳Ի����������������Ҫע�⣬���˶��ٲ�������Ҫ�н���ٴ�����

// ������.cpp����������һ����򵥵�������������������ٽ�����ʹ��ͬһ������
// ������󳣳������ڵݹ麯���У������ǲ�����˵ÿһ��ݹ�ͻ�һ������
// ��������������ǾͿ���ʹ�� recyrsive_mutex���󣨵ݹ黥���������ڵݹ麯����������

#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

std::mutex mtx; 
std::recursive_mutex rmtx;

void until100(int& num)
{
	// �ݹ���ֹ����
	if (num > 100)
		return;
	else
		cout << num << endl;

	rmtx.lock();
	num++;
	until100(num);
	rmtx.unlock();
}

int main()
{
	static int num = 0;
	std::thread a(until100, ref(num));
	// �����������ǽ�recursive_mutex����mutex�ͻᵼ��������
	a.join();
	return 0;
}