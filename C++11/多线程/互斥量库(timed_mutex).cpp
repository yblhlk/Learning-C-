#include<iostream>
#include<mutex>
#include<thread>
#include <iomanip>  // put_time

using namespace std;
std::timed_mutex tmtx;

void testTmtx_tlf()
{
	bool flag = tmtx.try_lock_for(std::chrono::seconds(3));
	if (flag)
	{
		std::this_thread::sleep_for(std::chrono::seconds(5));
		tmtx.unlock();
	}
	else
	{
		cout << "�����߳����ڷ����ٽ������ȴ�5���δ�ȵ������˳���" << endl;
	}
}
void testTmtx_tlu()
{
	//1. ���ý�ֹʱ�䣺����ǰʱ��������
	// dieline �������� std::chrono::system_clock::time_point��ʱ����ࣩ��
	// ������Ϊ std::chrono::system_clock::now() ���ص���ʱ�����ĵ�ǰʱ���
	auto dieline = std::chrono::system_clock::now() + std::chrono::seconds(2);

	//2. ������ʱ������
	bool flag = tmtx.try_lock_until(dieline);
	if (flag)
	{
		std::this_thread::sleep_for(std::chrono::seconds(5));
		tmtx.unlock();
	}
	else
	{
	// ��ӡ std::chrono::system_clock::time_point��ʱ����ࣩ��
		//1. ʹ��
		//   a. ʹ�� std::chrono::system_clock::to_time_t() ������ʱ���ת��Ϊ std::time_t ����(ʱ������ͣ���
		//   b. Ȼ��ʹ�� C ��׼���е� std::ctime()���� �� ʱ�������� ת��Ϊ�ɶ����ַ�����ʽ����ʱ���תΪ�ַ�������
		std::time_t time_t_dieline = std::chrono::system_clock::to_time_t(dieline);
		cout << "�����߳����ڷ����ٽ������ѳ�����ֹʱ�䣺" << std::ctime(&time_t_dieline) << "�����˳���" << endl;
		//2. ʹ�� std::put_time ��ʽ������ӡ  //<iomanip> ���� put_time()
		//   a.����std::localtime()���� �� ʱ�������� ת��Ϊ ����ʱ�������std::tm��
		//   b.���� ����ʱ�������std::tm�� ���� <iomanip>���е�put_time()�������и�ʽ����ӡ��
		std::tm* local_time = std::localtime(&time_t_dieline);
		std::cout << "Current time: " << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << std::endl;
	}
}


int main()
{
	// 1. ����timed_mutex�����try_lock_for()����
	{
		std::thread a(testTmtx_tlf);
		std::thread b(testTmtx_tlf);
		a.join();
		b.join(); 
	}

	// 2. ����timed_mutex�����try_lock_until()����
	{
		std::thread a(testTmtx_tlu);
		std::thread b(testTmtx_tlu);
		a.join();
		b.join();
	}
	return 0;
}

// timed_mutex�ĺ�����
// lock()��unlock()��try_lock()
// try_lock_for(): ����һ��"ʱ���"����ʾ�����ʱ��֮���߳����û�л����������ס������ʱ���򷵻�false.
// try_lock_until() : ����һ��"ʱ���"����ʾ����ʱ���֮ǰ����
// ������������Ҫ���std�ռ��µ�chrono�����ռ�ʹ�ã�
// // ��ȡ��ǰʱ��㣺auto now = std::chrono::system_clock::now();
// // 5���ӣ�auto lock_duration = std::chrono::seconds(5); 
// // ���߳�˯��5�룺std::this_thread::sleep_for(std::chrono::seconds(3));
// ���Ժ� std::mutex ������ͬ��timed_mutex �� std::mutex ����������Ա������try_lock_for()��try_lock_until()

// (chrono)��ʱ���ʹ�ã�
// std::chrono::seconds(2) : ���������ӡ�
// std::this_thread::sleep_for(std::chrono::seconds(5)) : �õ�ǰ�߳�����5�롣��5����ɶ�²�����Ӳռ��ϵͳ��Դ��
// a. std::chrono::system_clock::now()���������ص���ʱ�����ĵ�ǰʱ���
// b. std::chrono::system_clock::time_point��ʱ����ࣩ��
// c. ʹ�� std::chrono::system_clock::to_time_t() ������ʱ���ת��Ϊ std::time_t ����(ʱ������ͣ�
// d. std::ctime()���� : �� ʱ�������� ת��Ϊ�ɶ����ַ�����ʽ����ʱ���תΪ�ַ�������
// e. std::localtime()���� : �� ʱ�������� ת��Ϊ ����ʱ�������std::tm��
// f. ���� ����ʱ�������std::tm�� ���� <iomanip>���е�put_time()�������и�ʽ����ӡ��