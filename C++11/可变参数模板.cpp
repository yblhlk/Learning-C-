#include<iostream>
#include<cstdio>
#include<cstdarg> //va_list ���ͱ�������ͷ�ļ� stdarg.h �С�(std arg)
using namespace std;
// C�����еĿɱ������
//  va_list //�����б�ָ�� 
//  va_start(�����б�ָ�룬���һ���б��������β�) //��va_list����ָ��vaָ���һ����������
//  va_arg(�����б�ָ�룬����)  //va_arg��ȡ��ǰ�������������ͺ�ֵ������ָ���ƶ�����һ������
//  va_end(�����б�ָ��) //va_end�������ֳ�,��ָ��ap��Ϊ��ָ�룬��ֹҰָ������


// ����add() �����ѡ����֮��
// ��������һ��ǿ�Ʋ���ָ���˿�ѡ��������������ѡ����Ϊdouble����
// ����ֵ����ֵ��double����
double add(int n, ...)
{
    int i = 0;
    double sum = 0.0;
    va_list argptr;
    va_start(argptr, n);               // ��ʼ��argptr
    for (i = 0; i < n; ++i)            // ��ÿ����ѡ��������ȡ����Ϊdouble�Ĳ�����
        sum += va_arg(argptr, double); // Ȼ���ۼӵ�sum��
    va_end(argptr);

    return sum;
}

//C�����еĿɱ�����������ǳ��鷳������C++11�����˿ɱ����ģ��������ɱ������
// �ɱ����ģ�壬����Ҳ��ǿ��
// C++11�������Կɱ����ģ���ܹ��������Խ��ܿɱ�����ĺ���ģ�����ģ��

// �������һ�������ɱ�����ĺ���ģ��
template<class ...Args>
void func(Args... a){}
//Args, args��һ��ģ���������a ��һ�������ββ�����
//�����޷�ֱ�ӻ�ȡ������ a �е�ÿ�������ģ�ֻ��ͨ��չ���������ķ�ʽ����ȡ�������е�ÿ������

//�﷨��֧��ʹ�� args[i] ������ʽ��ȡ�ɱ���������������޷�ֱ�ӻ�ȡ�������е�ÿ������
//template<class ...args>
//void funca(args... a) 
//{
//    for (int i = 0; i < sizeof...(a); i++) //sizeof... (a) ��ȡ�������еĲ�������
//    {
//        cout << a[i] << " "; //��ӡ�������е�ÿ������
//    }
//    cout << endl;
//}
// �޷�ͨ�����롣

// ������������չ����ʽ���ݹ�չ����������ʹ��ʹ�� ���ű��ʽ+�б��ʼ�� չ����������ֱ��ʹ�ó�ʼ���б� չ��������
// 1. �ݹ�չ��������(����һ���޲λ���ͨģ�庯����������ֹ�ݹ�)
// a. �ݹ���ú���������������� b. ����һ����ֹ�ݹ�ĺ���
template <class T> 
void funca(T arg)
{
    cout << arg << endl;
}
template <class T, class ...Args>
void funca(T value,Args... arg)
{
    cout << value << ' ';
    funca(arg...);
}
//��Ȼ��Ҳ�����������Ը��޲εĺ�������ʱ���صĺ����Ͳ��ü�ģ����
void funcb()
{
    cout << endl;
}
template <class T, class ...Args>
void funcb(T value, Args... arg)
{
    cout << value << ' ';
    funcb(arg...);
}
// ��Ȼ�滨һ�㣬����һ�����������ģ�庯�������ݹ���ֹ����Ҳ��
template <class T1, class T2, class T3>
void funcc(T1 a, T2 b, T3 c)
{
    cout << a << b << c << ", �����ݹ���ֹģ�庯�������á�" << endl;

}
template <class T, class ...Args>
void funcc(T value, Args... arg)
{
    cout << value << "����ʣ" << sizeof...( arg) << "��������" << endl;
    funcc(arg...);
}

// 2. ʹ�� ���ű��ʽ+�б��ʼ�� չ��������
//���ű��ʽչ���������ķ�ʽ������Ҫͨ���ݹ���ֹ��������ֱ���� չ�������壨expand�����壩��չ����
// a. дһ�����������ģ�庯�� b.�ڿɱ����ģ����дһ�����顣c.ʹ���б��ʼ�� + ���ű��ʽ��ʼ������
template<class T>
void printarg(T value)
{
    cout << value << ' ';
}
template<class... Args>
void funcd(Args... arg)
{
    int arr[] = { (printarg(arg),0)... };
    cout << endl;
}
void funcd()
{
    cout << "û�в���" << endl;
}

//3.ֱ�����б��ʼ��
//ʵ��������Ҳ���Բ��ö��ű��ʽ����Ϊ�����������ǳ�ʼ����������ʱ�����������������ǿ��Խ��������ķ���ֵ����Ϊ���ͣ�Ȼ�����������ֵȥ��ʼ����������Ҳ�ǿ��Ե�
// a. �ڿɱ�ģ�庯����дһ������ b. дһ������ֵ���ͺ���������ϵͳ��ģ�庯�� c.���б��ʼ������ʼ������
template<class T>
char printargc(T arg)
{
    cout << arg << " ";
    return 1;
}
template<class... Args>
void funce(Args... arg)
{
    char arr[] = {printargc(arg)...};
    cout << endl;
}
void funce()
{
    cout << "û�в���" << endl;
}

int main()
{
    cout << "================1.�ݹ�չ��������===============" << endl;
    funca(1, 2, 4, 5);
    funcb(3, 4, 5, 6, 7);
    funcc(4, 5, 6, 7, 8, 9);
    cout << "================2. ʹ�� ���ű��ʽ+�б��ʼ�� չ��������===============" << endl;
    funcd(1, 2, 3, 4, 5, 6, 7, 8, 9);
    funcd(); //�������ܷ��䳣����СΪ 0 �����飨Ҫ��֧���޲Σ���������һ���޲ε�ͬ��������
    cout << "================3.ֱ�����б��ʼ��===============" << endl;
    funce(); //�������ܷ��䳣����СΪ 0 �����飨Ҫ��֧���޲Σ���������һ���޲ε�ͬ��������
    funce(0, 1, 2, 3, 4, 5);
    return 0;
}