#include<iostream>
#include<mutex>
#include<thread>

using namespace std;
std::mutex mtx; // 创建一个全局的互斥量对象：


int main()
{
	// 1. 下面展示一个简单的死锁：主线程上锁后，子线程尝试上同一把锁。
	{
		//mtx.lock();
		//thread a([] {mtx.lock(); cout << "能到达那个地方吗？" << endl;  mtx.unlock(); });
		//a.join(); // 一定要等待，不然是主线程和子线程同时运行。
		//mtx.unlock();
	}

	// 2. 死锁情况二：连续上同一把锁
	{
		mtx.lock();
		mtx.lock();
		cout << "能到达那个地方吗？" << endl;  
		mtx.unlock();
		mtx.unlock();
	}

	// 以上两种情况是最简单的死锁情况，本质都是连续上同一把锁，再概括一下就是：在锁的临界区内又使用了这把锁。
	return 0;
}