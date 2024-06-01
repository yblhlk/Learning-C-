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
 *  ����ָ����ǻ���RAII��̷�ʽ����д��һϵ����ģ�壬
 *  ���ṩ���Զ��ڴ�����Զ��ͷ���ָ��Ķ��󣩣�
 *  ��������������-> �� * �����������������ָ��һ��ʹ�ø���ģ�壬�ʽ�����ָ�롣
 
 * ����ָ����Ҫ������������⣺
 * a. �Զ��ͷ��ڴ棺������ָ������������ڽ���ʱ�������뿪�����򣩣������Զ�ɾ����ָ��Ķ�����ͨ�����������е�delete������ʵ�֡�
 * b. ��ֹҰָ�룺Ұָ����ָ�Ѿ����ͷŵ��ڴ��ָ�롣����ָ��ͨ��ȷ��������ʱɾ����ָ��Ķ��󣬲���֮��ָ������Ϊnullptr����������Чֵ�����Ӷ���ֹҰָ��ĳ��֡�
 */

#include<iostream>
#include<memory>
using namespace std;

//1. ��ʵ��һ������ָ����ģ��
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
	// 1. �����һ������ָ��
	{
		cout << "============1. �����һ������ָ��=============" << endl;
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
	
	// 2.auto_ptr (C++98) <memory>
	{
		cout << "================2.auto_ptr===============" << endl;
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

	// 3. unique_ptr (C++11) <memory>
	{

	}
	/**
	  std::unique_ptr������һ����ռ����Ȩ������ָ�룬��ͬһʱ��ֻ��һ��unique_ptr����ָ��һ���������󡣵�unique_ptr������ʱ������ָ��Ķ���Ҳ�ᱻ���١�
	  std::shared_ptr������һ����������Ȩ������ָ�룬���shared_ptr����ָ��ͬһ�����󡣵����һ��ӵ�иö����shared_ptr������ʱ������Żᱻ���١�
	  std::weak_ptr������Ϊ�����std::shared_ptr�������һ������ָ�룬�������std::shared_ptr�໥���õ��µ�ѭ���������⡣�����Զ�����������ڽ��й���ֻ�Ǽ򵥵ر����һ��std::shared_ptr�������ã������������Ӷ�������ü�����
	*/
	return 0;
}