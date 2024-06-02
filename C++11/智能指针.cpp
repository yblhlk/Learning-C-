/** 1.为什么需要RAII？
 *内存泄漏是C++饱受诟病的一点，忘记delete导致的内存泄漏，异常安全问题导致的内存泄漏……
 * 内存泄漏无处不在，防不胜防，有没有办法能自动释放内存空间？
 */

/** 2.RAII是什么？
 * 对于这个问题，有大佬提出了RAII技术
 * RAII（Resource Acquisition Is Initialization）是一种利用对象生命周期来控制程序资源（如内存、文件句柄、网络连接、互斥量等等）的技术
 * 它的原理很简单，即：在构造函数中申请资源，在析构函数中释放资源。
 * 像这样将资源的获取和释放与对象的生命周期绑定，实现了资源的自动管理，避免了内存泄露等问题。

 * 总结：RAII是C++中一种重要的编程范式，它通过将资源的获取和释放与对象的生命周期绑定，
 * 实现了资源的自动管理，避免了内存泄露等问题。
 */

/** 3.什么是智能指针？
 *  智能指针就是基于RAII编程范式而编写的一系列类模板，用来帮助我们管理对象，且让我们能像指向对象的指针一样使用智能指针。
 *  它提供了自动内存管理（自动释放所指向的对象），
 *  且在类中重载了-> 和 * 运算符，让我们能像指针一样使用该类模板，故叫智能指针。
 
 * 智能指针主要解决了两个问题：
 * a. 自动释放内存：当智能指针对象生命周期结束时（例如离开作用域），它会自动删除所指向的对象。这通过析构函数中的delete操作符实现。
 * b. 防止野指针：野指针是指已经被释放的内存的指针。智能指针通过确保在析构时删除所指向的对象，并在之后将指针设置为nullptr（或类似无效值），从而防止野指针的出现。
 */

#include<iostream>
#include<memory>
using namespace std;

//0. 简单实现一个智能指针类模板
// a. 类模板，有一个模板成员变量。
// b. 在构造函数和析构函数中申请和释放资源。
// c. 重载-> 和 * 

// a. 类模板，有一个模板成员变量。
template<typename T>
class SmartPtr
{
public:
	// b. 在构造函数和析构函数中申请和释放资源。
	SmartPtr(T* object = nullptr)
		:_object(object)
	{}

	~SmartPtr()
	{
		if(_object != nullptr) //delete前要记得判断是不是空指针
			delete _object;
	}

	T& operator *() //解引用
	{
		return *_object; 
	}
	// c. 重载-> 和 * 
	T* operator ->() //访问成员
	{
		return _object;
	}

	T** operator &() //取地址
	{
		return &_object; 
	}

	template<typename E> // 返回指针地址
	friend std::ostream& operator << (std::ostream& os, SmartPtr<E>& ptr);
private:
	T* _object;
};

template<typename E>
std::ostream& operator << (std::ostream& os, SmartPtr<E>& ptr)
{
	os << ptr._object;
	return os;
}

int main()
{
	// 0. 简单设计一个智能指针
	{
		cout << "============0. 简单设计一个智能指针=============" << endl;
		struct Student
		{
			Student(int age = 18)
				:_age(age)
			{}

			int _age;
		};

		SmartPtr<int> pa(new int(1));
		cout << *pa << endl;
		cout << &pa << endl;
		cout << pa << endl << endl;

		SmartPtr<Student> pb(new Student(19));
		cout << (*pb)._age << endl;
		cout << pb << endl; //在C++中，不能直接输出一个对象（即使用 std::cout 或类似的输出流来输出一个对象），除非该对象类型重载了 operator<< 函数以支持流插入操作。
		cout << &pb << endl;
		cout << pb->_age << endl;
		//-> 运算符的操作数只有一个，那就是指针 pb，所以 -> 是一个单目运算符。
	}
	
	/** 上面的简单设计，还存在许多问题，如：
	 * 默认拷贝构造和赋值运算符重载是浅拷贝会导致双重析构。（注意这是指针，只能浅拷贝）
	 * 还有线程不安全的问题。
	 * 
	 * 所以C++的<memory>库中也提供了智能指针，且针对以上问题提供了不同种类的智能指针。
	 * a. auto_ptr (C++98) : 通过管理权转移的方式解决智能指针的拷贝问题，
	 *    对一个对象的管理权转移后也就意味着，该对象不能再用对原来管理的资源进行访问了，
	 *    会造成对象悬空，继续使用原来的对象，程序就会直接崩溃。
	 * 
	 * b. unique_ptr (C++11) : 通过防拷贝的方式解决智能指针的拷贝问题，
	 *    也就是简单粗暴的禁止拷贝，这样也能保证资源不会被多次释放
	 * 
	 * c. shared_ptr (C++11) : 通过引用计数的方式解决智能指针的拷贝问题，
	 *    也就是说shared_ptr支持拷贝。
	 * d. weak_ptr (C++11) : weak_ptr不是用来管理资源的释放的，weak_ptr 是对 shared_ptr的补充。
	 */
	
	// 1.auto_ptr (C++98) <memory>
	{
		cout << "================1.auto_ptr===============" << endl;
		// get() : 返回auto_ptr 指向的对象的指针（如果有），如果它不指向任何对象，则返回零。
		// operator *():返回对 auto_ptr 指向的对象的引用。
		// operator ->() : 返回auto_ptr 指向的对象的成员。
		// release() : 将auto_ptr内部指针设置为空指针（这表示它不指向任何对象）
		//             并返回auto_ptr指向对象的指针，该对象不再是它负责销毁的。
		// reset() : 销毁 auto_ptr所指向的对象（如果有）,并把一个新对象赋值给auto_ptr（如果有）
		std::auto_ptr<int> aptr(new int(44));
		cout <<"aptr.get() : " <<  aptr.get() << " -> " << *aptr.get() << endl;
		cout << "*aptr : " << *aptr << endl;
		
		int* pa = aptr.release();
		cout << ">>> int* pa = aptr.release();" << endl;
		cout << "aptr.get() : " << aptr.get() << endl;
		cout << "pa : " << pa << endl;
		
		aptr.reset(new int(4));
		cout << ">>> aptr.reset(new int(4));" << endl;
		cout << "aptr.get() : " << aptr.get() << " -> " << *aptr.get() << endl;
		cout << "*aptr : " << *aptr << endl;

		//auto_ptr，通过移交权限来解决拷贝问题。
		//实现：将新指针指向的原空间清除后，将旧指针指向的空间赋给新指针，旧指针指向nullptr;
		std::auto_ptr<int> aptr1(aptr);
		cout << ">>> auto_ptr<int> aptr1(aptr);" << endl;
		cout << "aptr.get() : " << aptr.get() << endl;
		cout << "aptr1.get() : " << aptr1.get() << " -> " << *aptr1.get() << endl;
		//*aptr.get() << endl;//不报错，但程序奔溃
		// 所以使用auto_ptr的时候要注意旧指针已经是空指针，不然会导致程序崩溃。
		// 大多数公司认为auto_ptr设计的并不好，且禁止使用auto_ptr
	}

	// 2. unique_ptr (C++11) <memory>
	{
		cout << "================2. unique_ptr===============" << endl;
		// .get() : 返回auto_ptr 指向的对象的指针（如果有），如果它不指向任何对象，则返回零。
		// operator *():返回对 auto_ptr 指向的对象的引用。
		// operator ->() : 返回auto_ptr 指向的对象的成员。
		// .release() : 将auto_ptr内部指针设置为空指针（这表示它不指向任何对象）
		//             并返回auto_ptr指向对象的指针，该对象不再是它负责销毁的。
		// .reset() : 销毁 auto_ptr所指向的对象（如果有）,并把一个新对象赋值给auto_ptr（如果有）
		
		// .swap() && swap() : 交换
		// operator bool() : 判空，if()

		// operator[] : 数组访问。
		std::unique_ptr<int> uptr(new int(1));
		cout << ">>>std::unique_ptr<int> uptr(new int(1));" << endl;
		cout << "uptr.get() : " << uptr.get() << endl;
		cout << "*uptr.get() :" << *uptr.get() << endl;

		int* a = uptr.release();
		cout << ">>>int* a = uptr.release();" << endl;
		cout << "uptr.get() : " <<  uptr.get() << endl;
		cout << "a : " << a << endl;
		if (uptr)
			cout << "uptr are not empty." << endl;
		else
			cout << "uptr are empty." << endl;

		uptr.reset(new int(4));
		cout << ">>>uptr.reset(new int(4));" << endl;
		cout << "uptr.get() : " << uptr.get() << endl;
		cout << "*uptr.get() : " << *uptr.get() << endl;
		if (uptr)
			cout << "uptr are not empty." << endl;
		else
			cout << "uptr are empty." << endl;

		//.swap() & swap()
		std::unique_ptr<int> uptr1(new int(2));
		cout << ">>> unique_ptr<int> uptr1(new int(2));" << endl;
		cout << "uptr.get() : " << uptr.get() << " -> " << *uptr.get() << endl;
		cout << "uptr1.get() : " << uptr1.get() << " -> " << *uptr1.get() << endl;
		uptr1.swap(uptr);
		cout << ">>> uptr1.swap(uptr);" << endl;
		cout << "uptr.get() : " << uptr.get() << " -> " << *uptr.get() << endl;
		cout << "uptr1.get() : " << uptr1.get() << " -> " << *uptr1.get() << endl;
		swap(uptr1, uptr);
		cout << ">>> swap(uptr1, uptr);" << endl;
		cout << "uptr.get() : " << uptr.get() << " -> " << *uptr.get() << endl;
		cout << "uptr1.get() : " << uptr1.get() << " -> " << *uptr1.get() << endl;

		//operator[] : 像数组一样访问。
		//原理 ： 指针加法
		std::unique_ptr<int[]> uptr2(new int[] {11, 12, 13, 14, 15});
		cout << ">>>unique_ptr<int[]> uptr2(new int[] {11,12,13,14,15});" << endl;
		cout << "uptr2.get() : " << uptr2.get() << " -> " << *uptr2.get() << endl;
		for(int i = 0; i < 5; ++i)
			cout << "uptr2[" << i << "] = " << uptr2[i] << endl;

		// unique_ptr 通过禁止拷贝构造来，解决拷贝问题
		//std::unique_ptr<int> uptr1(uptr); //报错
	}

	// 3. shared_ptr (C++11) <memory>
	{
		// .get() : 返回auto_ptr 指向的对象的指针（如果有），如果它不指向任何对象，则返回零。
		// operator *():返回对 auto_ptr 指向的对象的引用。
		// operator ->() : 返回auto_ptr 指向的对象的成员。
		// 没有.release() 。
		// .reset() : 销毁 auto_ptr所指向的对象（如果有）,并把一个新对象赋值给auto_ptr（如果有）

		// .swap & swap() : 交换
		// operator bool() : 判空，if()

		// use_const() : 返回当前智能指针的引用计数。
		// unique : 判断当前智能指针的引用计数是否为1。

		cout << "================3.shared_ptr===============" << endl;
		shared_ptr<int> sptr(new int(1));
		cout << ">>>shared_ptr<int> sptr(new int(1));" << endl;
		cout << "sptr.get() : " << sptr.get() << " -> " << *sptr.get() << endl;
		if (sptr)
			cout << "sptr are not empty." << endl;
		else
			cout << "sptr are empty." << endl;
		//没有release() //int* pa = sptr.release(); //报错

		sptr.reset();
		cout << ">>>sptr.reset();" << endl;
		cout << "sptr.get() : " << sptr.get() << endl;
		if (sptr)
			cout << "sptr are not empty." << endl;
		else
			cout << "sptr are empty." << endl;

		shared_ptr<int> sptr1(new int(4));
		cout << ">>>shared_ptr<int> sptr1(new int(4));" << endl;
		cout << "sptr.get() : " << sptr.get() << endl;
		cout << "sptr1.get() : " << sptr1.get() << " -> " << *sptr1.get() << endl;
		sptr1.swap(sptr);
		cout << ">>> sptr1.swap(sptr());" << endl;
		cout << "sptr.get() : " << sptr.get() << " -> " << *sptr.get() << endl;
		cout << "sptr1.get() : " << sptr1.get() << endl;
		swap(sptr1, sptr);
		cout << ">>> swap(sptr1, sptr);" << endl;
		cout << "sptr.get() : " << sptr.get() << endl;
		cout << "sptr1.get() : " << sptr1.get() << " -> " << *sptr1.get() << endl;

		//shared_ptr通过引用计数的方式解决智能指针的拷贝问题
		//也就是说shared_ptr支持拷贝构造
		shared_ptr<int> a(new int(1));
		shared_ptr<int> b(a);
		shared_ptr<int> c(b);
		shared_ptr<int> d(new int (4));
		cout << endl << "a.unique() : " << a.unique() << endl;
		cout << "a.use_count() : " << a.use_count() << endl;
		cout <<  "b.unique() : " << b.unique() << endl;
		cout << "b.use_count() : " << b.use_count() << endl;
		cout << "c.unique() : " << c.unique() << endl;
		cout << "c.use_count() : " << c.use_count() << endl;
		cout << endl << "d.unique() : " << d.unique() << endl;
		cout << "d.use_count() : " << d.use_count() << endl;
		a.reset(); //清除一个引用计数
		cout << ">>> a.reset();" << endl;
		cout << endl << "a.unique() : " << a.unique() << endl;
		cout << "a.use_count() : " << a.use_count() << endl;
		cout << "b.unique() : " << b.unique() << endl;
		cout << "b.use_count() : " << b.use_count() << endl;
		cout << "c.unique() : " << c.unique() << endl;
		cout << "c.use_count() : " << c.use_count() << endl;
	}
	// 4. weak_ptr (C++11) <memory>
	{
		// 没有.get()
		// 没有operator *()。
		// operator ->() : 返回auto_ptr 指向的对象的成员。
		// 没有.release() 。
		// .reset() : 只是包weak_ptr对象变为空

		// .swap & swap() : 交换
		// 没有operator bool()。

		// .use_const() : 返回当前智能指针的引用计数。

		// .expired() : 检查是否过期，即判断weak_ptr对象是否是空的
		// .lock() : 返回weak_ptr 指向的shared_ptr对象
		//           虽然能用shared_ptr来构造weak_ptr，但只能用.lock()来构造shared_ptr.

		cout << "================4.weak_ptr===============" << endl;
		//weak_ptr<int> wptr(new int(1)); 
		//报错，只能用shared_ptr和weak_ptr来创建weak_ptr.
		shared_ptr<int> sptr(new int(1));
		weak_ptr<int> wptr(sptr);
		weak_ptr<int> wptr1(wptr); 
		weak_ptr<int> wptr2 = wptr1;
		weak_ptr<int> wptr3(sptr);

		//报错，没有get() //cout << "wptr.get() : " << wptr.get() << endl;
		//报错，没有operator *()。//cout << *wptr << endl;

		//.use_const() : 计算的是shared_ptr的个数，不是weak_ptr的个数。
		cout << wptr.use_count() << endl; 
		cout << wptr1.use_count() << endl;
		cout << wptr2.use_count() << endl; //不计算weak_ptr的个数。
		cout << wptr3.use_count() << endl;
		cout << sptr.use_count() << endl; //shared_ptr的use_count()也不计算weak_ptr的个数
		cout << sptr.unique() << endl;
		
		// .swap() && swap : 交换指向

		// .expired() : 检查是否过期，即判断weak_ptr对象是否是空的
		cout << "//.expired() :检查是否过期。(0:未过期，1:过期。)" << endl;
		cout << "wptr.expired() : " << wptr.expired() << endl;
		sptr.reset();
		cout << ">>> sptr.reset(); " << endl;
		cout << "wptr.expired() : " <<wptr.expired() << endl;
		cout << "结论：改变shared_ptr置空后weak_ptr也置空。" << endl;
		sptr.reset(new int(4));
		cout << ">>> sptr.reset(4); " << endl;
		cout << "wptr.expired() : " << wptr.expired() << endl; //仍然过期，wptr要重新指向sptr
		cout << "现象：改变shared_ptr置空后再改变指向，weak_ptr仍置空。" << endl;
		cout << "结论：weak_ptr不会跟着shared_ptr改变指向。" << endl;
		
		// wptr.reset(sptr); //报错，无法用reset来改变weak_ptr的指向，只能用来置空。
		wptr.reset(); //weak_ptr的reset()只能用来置空
		wptr = sptr;  // 改变wptr的指向要用operator=
		cout << ">>>wptr = sptr;" << endl;
		cout << "wptr.expired() : " << wptr.expired() << endl;
		cout << "结论：改变wptr的指向要用operator=，不能用.reset()。" << endl;

		sptr.reset(new int(5)); //改变shared_ptr的指向后weak_ptr不会跟着改变指向。
		cout << ">>> sptr.reset(5); " << endl;
		cout << "wptr.expired() : " << wptr.expired() << endl;
		cout << "现象：改变shared_ptr的指向后weak_ptr置空。" << endl;
		cout << "结论：改变shared_ptr的指向后weak_ptr不会跟着改变指向，且weak_ptr置空。" << endl;
		

		// .lock() : 返回weak_ptr 指向的shared_ptr对象
		wptr = sptr;
		cout << "\nwptr = sptr;" << endl;
		cout << "sptr.use_count() : " << sptr.use_count() << endl;
		shared_ptr<int> sptr1 = wptr.lock();
		cout << ">>> shared_ptr<int> sptr1 = wptr.lock();" << endl;
		cout << "sptr.use_count() : " << sptr.use_count() << endl;
		cout << "结论：weak_ptr的lock方法返回一个shared_ptr对象，会增加引用计数。" << endl;
		sptr = wptr.lock();
		cout << ">>> sptr = wptr.lock();" << endl;
		cout << "sptr.use_count() : " << sptr.use_count() << endl;
		cout << "结论：weak_ptr的lock方法返回一个的shared_ptr对象和接收的shared_ptr指向相同，就不会增加引用计数。" << endl;
		sptr1 = wptr.lock();
		cout << ">>> sptr1 = wptr.lock();" << endl;
		cout << "sptr1.use_count() : " << sptr1.use_count() << endl;
		cout << "结论：如果weak_ptr.lock()返回的shared_ptr对象和接收的shared_ptr指向相同，就不会增加引用计数。" << endl;

		wptr.reset();
		cout << ">>> sptr1 = wptr.lock();" << endl;
		cout << "sptr.use_count() : " << sptr.use_count() << endl;
		cout << "sptr1.use_count() : " << sptr1.use_count() << endl;
		cout << "结论：weak_ptr置空不影响shared_ptr。" << endl;
		wptr.reset();
		cout << ">>> wptr.reser();" << endl;
		sptr = wptr.lock();
		cout << ">>> sptr1 = wptr.lock();" << endl;
		cout << "sptr.use_count() : " << sptr.use_count() << endl;
		cout << "sptr1.use_count() : " << sptr1.use_count() << endl;
		cout << "结论：将空的weak_ptr lock给shared_ptr,相当于把shared_ptr置空。" << endl;

	}
	/**
	  std::unique_ptr：这是一个独占所有权的智能指针，即同一时间只有一个unique_ptr可以指向一个给定对象。当unique_ptr被销毁时，它所指向的对象也会被销毁。
	  std::shared_ptr：这是一个共享所有权的智能指针，多个shared_ptr可以指向同一个对象。当最后一个拥有该对象的shared_ptr被销毁时，对象才会被销毁。
	  std::weak_ptr：这是为了配合std::shared_ptr而引入的一种智能指针，用来解决std::shared_ptr相互引用导致的循环引用问题。它不对对象的生命周期进行管理，只是简单地保存对一个std::shared_ptr的弱引用，这样不会增加对象的引用计数。
	*/
	return 0;
}