// ����������mutex Ҫ��� �̶߳���thread ��ʹ��
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

// 1.����һ��ȫ�ֵĻ���������mutex��ֻ��һ���޲ι��캯���������Ŀ������죬�ƶ����죬��ֵ�ȶ�û�У�
std::mutex mtx;  

// 2.���̺߳�����ʹ��mutex�����lock()��unlock()�������м����ͽ���
void print_block(int n, char c) {
	// critical section (�ؼ�����):
	mtx.lock();   // a. �ڷ����ٽ���Դǰ����
	for (int i = 0; i < n; ++i) { std::cout << c; }
	std::cout << '\n';
	mtx.unlock(); // b. �ڽ������ʺ����
}

std::mutex mtx1;
static int shared_num = 0;
void add1AddPrintSnum(std::string s)
{
	while(1)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1)); //���߳���ͣһ���ӡ�
		mtx1.lock();
		shared_num++;
		std::cout << s << "(++shared_num) ==" << shared_num << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << s << shared_num << std::endl;
		mtx1.unlock();
	}
}

// 3.�����̶߳���Ϳ���ͬʱ�����ٽ�����Դ��
int main()
{
	std::thread th1(print_block, 500, '*');
	std::thread th2(print_block, 500, '$');
	th1.join();
	th2.join();

	std::thread t1(add1AddPrintSnum, "t1 : ");
	std::thread t2(add1AddPrintSnum, "t2 : ");
	t1.join();
	t2.join();

	return 0;
}

//ʹ��mutex�����ܽ᣺
//1. ����һ��ȫ�ֵ�mutex����(����������// std::mutex mtx;
//2. �ڷ����̺߳������ٽ�����Դʱ��ʹ��mutex�����lock()�������м�����unlock()�������н�����
//3. ���threads����Ϳ�������ķ����ٽ�����Դ�ˡ�