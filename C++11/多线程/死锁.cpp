//#include<iostream>
//#include<mutex>
//#include<thread>
//
//using namespace std;
//std::mutex mtx; // 创建一个全局的互斥量对象：
//std::recursive_mutex rmtx;
//
//int main()
//{
//	// 1.1 下面展示一个简单的死锁：主线程上锁后，子线程尝试上同一把锁。
//	{
//		//mtx.lock();
//		//thread a([] {mtx.lock(); cout << "能到达那个地方吗？" << endl;  mtx.unlock(); });
//		//a.join(); // 一定要等待，不然是主线程和子线程同时运行。
//		//mtx.unlock();
//	}
//
//	// 1.2 死锁情况二：连续上同一把锁
//	{
//		mtx.lock();
//		mtx.lock();
//		cout << "能到达那个地方吗？" << endl;  
//		mtx.unlock();
//		mtx.unlock();
//	}
//	// 以上两种情况是最简单的死锁情况，本质都是连续上同一把锁，再概括一下就是：在锁的临界区内又使用了这把锁。
//	
//	// 2. 在解锁前return。
//	{
//		rmtx.lock();
//		return 0;
//		rmtx.unlock();
//	}
//  // 以就是导致死锁的第二种情况，在解锁之前通过retun\抛异常结束当前线程。那么它可能无法正确地释放锁，从而导致其他等待这个锁的线程永远无法获取到锁，进而形成死锁。
//	return 0;
//}