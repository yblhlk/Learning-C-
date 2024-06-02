/** 1.Ϊʲô��ҪRAII��
 *�ڴ�й©��C++����ڸ����һ�㣬����delete���µ��ڴ�й©���쳣��ȫ���⵼�µ��ڴ�й©����
 * �ڴ�й©�޴����ڣ�����ʤ������û�а취���Զ��ͷ��ڴ�ռ䣿
 */

/** 2.RAII��ʲô��
 * ����������⣬�д��������RAII����
 * RAII��Resource Acquisition Is Initialization����һ�����ö����������������Ƴ�����Դ�����ڴ桢�ļ�������������ӡ��������ȵȣ��ļ���
 * ����ԭ��ܼ򵥣������ڹ��캯����������Դ���������������ͷ���Դ��
 * ����������Դ�Ļ�ȡ���ͷ��������������ڰ󶨣�ʵ������Դ���Զ������������ڴ�й¶�����⡣

 * �ܽ᣺RAII��C++��һ����Ҫ�ı�̷�ʽ����ͨ������Դ�Ļ�ȡ���ͷ��������������ڰ󶨣�
 * ʵ������Դ���Զ������������ڴ�й¶�����⡣
 */

/** 3.ʲô������ָ�룿
 *  ����ָ����ǻ���RAII��̷�ʽ����д��һϵ����ģ�壬�����������ǹ������������������ָ������ָ��һ��ʹ������ָ�롣
 *  ���ṩ���Զ��ڴ�����Զ��ͷ���ָ��Ķ��󣩣�
 *  ��������������-> �� * �����������������ָ��һ��ʹ�ø���ģ�壬�ʽ�����ָ�롣
 
 * ����ָ����Ҫ������������⣺
 * a. �Զ��ͷ��ڴ棺������ָ������������ڽ���ʱ�������뿪�����򣩣������Զ�ɾ����ָ��Ķ�����ͨ�����������е�delete������ʵ�֡�
 * b. ��ֹҰָ�룺Ұָ����ָ�Ѿ����ͷŵ��ڴ��ָ�롣����ָ��ͨ��ȷ��������ʱɾ����ָ��Ķ��󣬲���֮��ָ������Ϊnullptr����������Чֵ�����Ӷ���ֹҰָ��ĳ��֡�
 */

#include<iostream>
#include<memory>
using namespace std;

//0. ��ʵ��һ������ָ����ģ��
// a. ��ģ�壬��һ��ģ���Ա������
// b. �ڹ��캯��������������������ͷ���Դ��
// c. ����-> �� * 

// a. ��ģ�壬��һ��ģ���Ա������
template<typename T>
class SmartPtr
{
public:
	// b. �ڹ��캯��������������������ͷ���Դ��
	SmartPtr(T* object = nullptr)
		:_object(object)
	{}

	~SmartPtr()
	{
		if(_object != nullptr) //deleteǰҪ�ǵ��ж��ǲ��ǿ�ָ��
			delete _object;
	}

	T& operator *() //������
	{
		return *_object; 
	}
	// c. ����-> �� * 
	T* operator ->() //���ʳ�Ա
	{
		return _object;
	}

	T** operator &() //ȡ��ַ
	{
		return &_object; 
	}

	template<typename E> // ����ָ���ַ
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
	// 0. �����һ������ָ��
	{
		cout << "============0. �����һ������ָ��=============" << endl;
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
		cout << pb << endl; //��C++�У�����ֱ�����һ�����󣨼�ʹ�� std::cout �����Ƶ�����������һ�����󣩣����Ǹö������������� operator<< ������֧�������������
		cout << &pb << endl;
		cout << pb->_age << endl;
		//-> ������Ĳ�����ֻ��һ�����Ǿ���ָ�� pb������ -> ��һ����Ŀ�������
	}
	
	/** ����ļ���ƣ�������������⣬�磺
	 * Ĭ�Ͽ�������͸�ֵ�����������ǳ�����ᵼ��˫����������ע������ָ�룬ֻ��ǳ������
	 * �����̲߳���ȫ�����⡣
	 * 
	 * ����C++��<memory>����Ҳ�ṩ������ָ�룬��������������ṩ�˲�ͬ���������ָ�롣
	 * a. auto_ptr (C++98) : ͨ������Ȩת�Ƶķ�ʽ�������ָ��Ŀ������⣬
	 *    ��һ������Ĺ���Ȩת�ƺ�Ҳ����ζ�ţ��ö��������ö�ԭ���������Դ���з����ˣ�
	 *    ����ɶ������գ�����ʹ��ԭ���Ķ��󣬳���ͻ�ֱ�ӱ�����
	 * 
	 * b. unique_ptr (C++11) : ͨ���������ķ�ʽ�������ָ��Ŀ������⣬
	 *    Ҳ���Ǽ򵥴ֱ��Ľ�ֹ����������Ҳ�ܱ�֤��Դ���ᱻ����ͷ�
	 * 
	 * c. shared_ptr (C++11) : ͨ�����ü����ķ�ʽ�������ָ��Ŀ������⣬
	 *    Ҳ����˵shared_ptr֧�ֿ�����
	 * d. weak_ptr (C++11) : weak_ptr��������������Դ���ͷŵģ�weak_ptr �Ƕ� shared_ptr�Ĳ��䡣
	 */
	
	// 1.auto_ptr (C++98) <memory>
	{
		cout << "================1.auto_ptr===============" << endl;
		// get() : ����auto_ptr ָ��Ķ����ָ�루����У����������ָ���κζ����򷵻��㡣
		// operator *():���ض� auto_ptr ָ��Ķ�������á�
		// operator ->() : ����auto_ptr ָ��Ķ���ĳ�Ա��
		// release() : ��auto_ptr�ڲ�ָ������Ϊ��ָ�루���ʾ����ָ���κζ���
		//             ������auto_ptrָ������ָ�룬�ö����������������ٵġ�
		// reset() : ���� auto_ptr��ָ��Ķ�������У�,����һ���¶���ֵ��auto_ptr������У�
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

		//auto_ptr��ͨ���ƽ�Ȩ��������������⡣
		//ʵ�֣�����ָ��ָ���ԭ�ռ�����󣬽���ָ��ָ��Ŀռ丳����ָ�룬��ָ��ָ��nullptr;
		std::auto_ptr<int> aptr1(aptr);
		cout << ">>> auto_ptr<int> aptr1(aptr);" << endl;
		cout << "aptr.get() : " << aptr.get() << endl;
		cout << "aptr1.get() : " << aptr1.get() << " -> " << *aptr1.get() << endl;
		//*aptr.get() << endl;//��������������
		// ����ʹ��auto_ptr��ʱ��Ҫע���ָ���Ѿ��ǿ�ָ�룬��Ȼ�ᵼ�³��������
		// �������˾��Ϊauto_ptr��ƵĲ����ã��ҽ�ֹʹ��auto_ptr
	}

	// 2. unique_ptr (C++11) <memory>
	{
		cout << "================2. unique_ptr===============" << endl;
		// .get() : ����auto_ptr ָ��Ķ����ָ�루����У����������ָ���κζ����򷵻��㡣
		// operator *():���ض� auto_ptr ָ��Ķ�������á�
		// operator ->() : ����auto_ptr ָ��Ķ���ĳ�Ա��
		// .release() : ��auto_ptr�ڲ�ָ������Ϊ��ָ�루���ʾ����ָ���κζ���
		//             ������auto_ptrָ������ָ�룬�ö����������������ٵġ�
		// .reset() : ���� auto_ptr��ָ��Ķ�������У�,����һ���¶���ֵ��auto_ptr������У�
		
		// .swap() && swap() : ����
		// operator bool() : �пգ�if()

		// operator[] : ������ʡ�
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

		//operator[] : ������һ�����ʡ�
		//ԭ�� �� ָ��ӷ�
		std::unique_ptr<int[]> uptr2(new int[] {11, 12, 13, 14, 15});
		cout << ">>>unique_ptr<int[]> uptr2(new int[] {11,12,13,14,15});" << endl;
		cout << "uptr2.get() : " << uptr2.get() << " -> " << *uptr2.get() << endl;
		for(int i = 0; i < 5; ++i)
			cout << "uptr2[" << i << "] = " << uptr2[i] << endl;

		// unique_ptr ͨ����ֹ�����������������������
		//std::unique_ptr<int> uptr1(uptr); //����
	}

	// 3. shared_ptr (C++11) <memory>
	{
		// .get() : ����auto_ptr ָ��Ķ����ָ�루����У����������ָ���κζ����򷵻��㡣
		// operator *():���ض� auto_ptr ָ��Ķ�������á�
		// operator ->() : ����auto_ptr ָ��Ķ���ĳ�Ա��
		// û��.release() ��
		// .reset() : ���� auto_ptr��ָ��Ķ�������У�,����һ���¶���ֵ��auto_ptr������У�

		// .swap & swap() : ����
		// operator bool() : �пգ�if()

		// use_const() : ���ص�ǰ����ָ������ü�����
		// unique : �жϵ�ǰ����ָ������ü����Ƿ�Ϊ1��

		cout << "================3.shared_ptr===============" << endl;
		shared_ptr<int> sptr(new int(1));
		cout << ">>>shared_ptr<int> sptr(new int(1));" << endl;
		cout << "sptr.get() : " << sptr.get() << " -> " << *sptr.get() << endl;
		if (sptr)
			cout << "sptr are not empty." << endl;
		else
			cout << "sptr are empty." << endl;
		//û��release() //int* pa = sptr.release(); //����

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

		//shared_ptrͨ�����ü����ķ�ʽ�������ָ��Ŀ�������
		//Ҳ����˵shared_ptr֧�ֿ�������
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
		a.reset(); //���һ�����ü���
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
		// û��.get()
		// û��operator *()��
		// operator ->() : ����auto_ptr ָ��Ķ���ĳ�Ա��
		// û��.release() ��
		// .reset() : ֻ�ǰ�weak_ptr�����Ϊ��

		// .swap & swap() : ����
		// û��operator bool()��

		// .use_const() : ���ص�ǰ����ָ������ü�����

		// .expired() : ����Ƿ���ڣ����ж�weak_ptr�����Ƿ��ǿյ�
		// .lock() : ����weak_ptr ָ���shared_ptr����
		//           ��Ȼ����shared_ptr������weak_ptr����ֻ����.lock()������shared_ptr.

		cout << "================4.weak_ptr===============" << endl;
		//weak_ptr<int> wptr(new int(1)); 
		//����ֻ����shared_ptr��weak_ptr������weak_ptr.
		shared_ptr<int> sptr(new int(1));
		weak_ptr<int> wptr(sptr);
		weak_ptr<int> wptr1(wptr); 
		weak_ptr<int> wptr2 = wptr1;
		weak_ptr<int> wptr3(sptr);

		//����û��get() //cout << "wptr.get() : " << wptr.get() << endl;
		//����û��operator *()��//cout << *wptr << endl;

		//.use_const() : �������shared_ptr�ĸ���������weak_ptr�ĸ�����
		cout << wptr.use_count() << endl; 
		cout << wptr1.use_count() << endl;
		cout << wptr2.use_count() << endl; //������weak_ptr�ĸ�����
		cout << wptr3.use_count() << endl;
		cout << sptr.use_count() << endl; //shared_ptr��use_count()Ҳ������weak_ptr�ĸ���
		cout << sptr.unique() << endl;
		
		// .swap() && swap : ����ָ��

		// .expired() : ����Ƿ���ڣ����ж�weak_ptr�����Ƿ��ǿյ�
		cout << "//.expired() :����Ƿ���ڡ�(0:δ���ڣ�1:���ڡ�)" << endl;
		cout << "wptr.expired() : " << wptr.expired() << endl;
		sptr.reset();
		cout << ">>> sptr.reset(); " << endl;
		cout << "wptr.expired() : " <<wptr.expired() << endl;
		cout << "���ۣ��ı�shared_ptr�ÿպ�weak_ptrҲ�ÿա�" << endl;
		sptr.reset(new int(4));
		cout << ">>> sptr.reset(4); " << endl;
		cout << "wptr.expired() : " << wptr.expired() << endl; //��Ȼ���ڣ�wptrҪ����ָ��sptr
		cout << "���󣺸ı�shared_ptr�ÿպ��ٸı�ָ��weak_ptr���ÿա�" << endl;
		cout << "���ۣ�weak_ptr�������shared_ptr�ı�ָ��" << endl;
		
		// wptr.reset(sptr); //�����޷���reset���ı�weak_ptr��ָ��ֻ�������ÿա�
		wptr.reset(); //weak_ptr��reset()ֻ�������ÿ�
		wptr = sptr;  // �ı�wptr��ָ��Ҫ��operator=
		cout << ">>>wptr = sptr;" << endl;
		cout << "wptr.expired() : " << wptr.expired() << endl;
		cout << "���ۣ��ı�wptr��ָ��Ҫ��operator=��������.reset()��" << endl;

		sptr.reset(new int(5)); //�ı�shared_ptr��ָ���weak_ptr������Ÿı�ָ��
		cout << ">>> sptr.reset(5); " << endl;
		cout << "wptr.expired() : " << wptr.expired() << endl;
		cout << "���󣺸ı�shared_ptr��ָ���weak_ptr�ÿա�" << endl;
		cout << "���ۣ��ı�shared_ptr��ָ���weak_ptr������Ÿı�ָ����weak_ptr�ÿա�" << endl;
		

		// .lock() : ����weak_ptr ָ���shared_ptr����
		wptr = sptr;
		cout << "\nwptr = sptr;" << endl;
		cout << "sptr.use_count() : " << sptr.use_count() << endl;
		shared_ptr<int> sptr1 = wptr.lock();
		cout << ">>> shared_ptr<int> sptr1 = wptr.lock();" << endl;
		cout << "sptr.use_count() : " << sptr.use_count() << endl;
		cout << "���ۣ�weak_ptr��lock��������һ��shared_ptr���󣬻��������ü�����" << endl;
		sptr = wptr.lock();
		cout << ">>> sptr = wptr.lock();" << endl;
		cout << "sptr.use_count() : " << sptr.use_count() << endl;
		cout << "���ۣ�weak_ptr��lock��������һ����shared_ptr����ͽ��յ�shared_ptrָ����ͬ���Ͳ����������ü�����" << endl;
		sptr1 = wptr.lock();
		cout << ">>> sptr1 = wptr.lock();" << endl;
		cout << "sptr1.use_count() : " << sptr1.use_count() << endl;
		cout << "���ۣ����weak_ptr.lock()���ص�shared_ptr����ͽ��յ�shared_ptrָ����ͬ���Ͳ����������ü�����" << endl;

		wptr.reset();
		cout << ">>> sptr1 = wptr.lock();" << endl;
		cout << "sptr.use_count() : " << sptr.use_count() << endl;
		cout << "sptr1.use_count() : " << sptr1.use_count() << endl;
		cout << "���ۣ�weak_ptr�ÿղ�Ӱ��shared_ptr��" << endl;
		wptr.reset();
		cout << ">>> wptr.reser();" << endl;
		sptr = wptr.lock();
		cout << ">>> sptr1 = wptr.lock();" << endl;
		cout << "sptr.use_count() : " << sptr.use_count() << endl;
		cout << "sptr1.use_count() : " << sptr1.use_count() << endl;
		cout << "���ۣ����յ�weak_ptr lock��shared_ptr,�൱�ڰ�shared_ptr�ÿա�" << endl;

	}
	/**
	  std::unique_ptr������һ����ռ����Ȩ������ָ�룬��ͬһʱ��ֻ��һ��unique_ptr����ָ��һ���������󡣵�unique_ptr������ʱ������ָ��Ķ���Ҳ�ᱻ���١�
	  std::shared_ptr������һ����������Ȩ������ָ�룬���shared_ptr����ָ��ͬһ�����󡣵����һ��ӵ�иö����shared_ptr������ʱ������Żᱻ���١�
	  std::weak_ptr������Ϊ�����std::shared_ptr�������һ������ָ�룬�������std::shared_ptr�໥���õ��µ�ѭ���������⡣�����Զ�����������ڽ��й���ֻ�Ǽ򵥵ر����һ��std::shared_ptr�������ã������������Ӷ�������ü�����
	*/
	return 0;
}