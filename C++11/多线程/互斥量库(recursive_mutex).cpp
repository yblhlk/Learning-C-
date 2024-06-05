// recursive_mutex : 递归互斥量，用于递归函数的上锁。
// 其允许同一个线程对互斥量多次上锁，但要注意，上了多少层锁，就要有解多少次锁。

// 在死锁.cpp中我讨论了一种最简单的死锁情况：在上锁的临界区中使用同一把锁。
// 这个错误常常发生在递归函数中，但我们不可能说每一层递归就换一把新锁
// 在这种情况下我们就可以使用 recyrsive_mutex对象（递归互斥量）用于递归函数的上锁。

#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

std::mutex mtx; 
std::recursive_mutex rmtx;

void until100(int& num)
{
	// 递归终止条件
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
	// 但是倘若我们将recursive_mutex换成mutex就会导致死锁。
	a.join();
	return 0;
}