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

// ʹ��try_lock():
std::mutex mtx2;
static int num = 0;
void print1to10000(std::string str)
{
	for (; num <= 10000; )
	{
		bool flag = mtx2.try_lock();
		if (flag)
		{
			//mtx2.lock();
			num++;
			std::cout << "flag : " << flag <<  str << num << std::endl;
			mtx2.unlock();
		}
		else
		{
			std::cout << "flag : " << flag << str << "���ٽ�����Դ���ڱ������̷߳���" << std::endl;
		}
	}
}

// 3.�����̶߳���Ϳ���ͬʱ�����ٽ�����Դ��
int main()
{
	// a. ����lock() �� unlock()
	std::thread th1(print_block, 500, '*');
	std::thread th2(print_block, 500, '$');
	th1.join();
	th2.join();

	//std::thread t1(add1AddPrintSnum, "t1 : ");
	//std::thread t2(add1AddPrintSnum, "t2 : ");
	//t1.join();
	//t2.join();

	// b. ����try_lock()
	// ����ٽ�����Դ���ڱ����ʣ���try_lock()����false���������������̣߳�����ٽ�����Դ���˷����򷵻�ture��������
	// try_lock()��������һ������ֵ������ɹ������˻��������򷵻�true�����򷵻�false������������������ǰ�̣߳������ͨ��������Щ��ϣ����Ϊ�ȴ�����������ò����õĳ�����
	std::thread t3(print1to10000, ", t3 : ");
	std::thread t4(print1to10000, ",  t4 : ");
	std::thread t5(print1to10000, ",   t5 : ");
	std::thread t6(print1to10000, ",    t6 : ");
	std::cout << "try_lock���������̡߳�" << std::endl;

	t3.join();
	t4.join();
	t5.join();
	t6.join();
	return 0;
}

//ʹ��mutex�����ܽ᣺
//1. ����һ��ȫ�ֵ�mutex����(����������// std::mutex mtx;
//2. �ڷ����̺߳������ٽ�����Դʱ��ʹ��mutex�����lock()�������м�����unlock()�������н�����
//3. ���threads����Ϳ�������ķ����ٽ�����Դ�ˡ�


//a.lock()���ú�������������������mutex����
        // ������lock()ʱ�������������ǰδ�������߳���������ǰ�߳̽��ɹ�������������ִ�к������롣
		// Ȼ��������������Ѿ��������߳���������ô����lock()���߳̽���������ֱ����������ÿ��ã����������߳̽�������
//b.try_lock()���ú��� ���� ������������mutex����
        // ��������ɹ������������Ѿ�����һ���߳����������򲻻�������ǰ�̣߳�������������false��
        // �����������ǰδ�������߳���������ǰ�߳̽��ɹ�������������ִ�к������롣