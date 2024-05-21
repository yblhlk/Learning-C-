#include<iostream>
#include<cstdio>
#include<cstdarg> //va_list 类型被定义在头文件 stdarg.h 中。(std arg)
using namespace std;
// C语言中的可变参数：
//  va_list //参数列表指针 
//  va_start(参数列表指针，最后一个有变量名的形参) //将va_list类型指针va指向第一个不定参数
//  va_arg(参数列表指针，类型)  //va_arg获取当前不定参数的类型和值，并将指针移动到下一个参数
//  va_end(参数列表指针) //va_end来清理现场,将指针ap置为空指针，防止野指针误用


// 函数add() 计算可选参数之和
// 参数：第一个强制参数指定了可选参数的数量，可选参数为double类型
// 返回值：和值，double类型
double add(int n, ...)
{
    int i = 0;
    double sum = 0.0;
    va_list argptr;
    va_start(argptr, n);               // 初始化argptr
    for (i = 0; i < n; ++i)            // 对每个可选参数，读取类型为double的参数，
        sum += va_arg(argptr, double); // 然后累加到sum中
    va_end(argptr);

    return sum;
}

//C语言中的可变参数用起来非常麻烦，于是C++11引入了可变参数模板来代替可变参数。
// 可变参数模板，更灵活，也更强大。
// C++11的新特性可变参数模板能够创建可以接受可变参数的函数模板和类模板

// 下面就是一个基本可变参数的函数模板
template<class ...Args>
void func(Args... a){}
//Args, args是一个模板参数包，a 是一个函数形参参数包
//我们无法直接获取参数包 a 中的每个参数的，只能通过展开参数包的方式来获取参数包中的每个参数

//语法不支持使用 args[i] 这样方式获取可变参数，所以我们无法直接获取参数包中的每个参数
//template<class ...args>
//void funca(args... a) 
//{
//    for (int i = 0; i < sizeof...(a); i++) //sizeof... (a) 获取参数包中的参数个数
//    {
//        cout << a[i] << " "; //打印参数包中的每个参数
//    }
//    cout << endl;
//}
// 无法通过编译。

// 参数包的三种展开方式：递归展开参数包、使用使用 逗号表达式+列表初始化 展开参数包、直接使用初始化列表 展开参数包
// 1. 递归展开参数包(重载一个无参或普通模板函数，用来终止递归)
// a. 递归调用函数（传入参数包） b. 重载一个终止递归的函数
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
//当然，也还可以重载以个无参的函数，这时重载的函数就不用加模板了
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
// 当然玩花一点，重载一个多个参数的模板函数来当递归终止函数也行
template <class T1, class T2, class T3>
void funcc(T1 a, T2 b, T3 c)
{
    cout << a << b << c << ", 花活版递归终止模板函数被调用。" << endl;

}
template <class T, class ...Args>
void funcc(T value, Args... arg)
{
    cout << value << "，还剩" << sizeof...( arg) << "个参数。" << endl;
    funcc(arg...);
}

// 2. 使用 逗号表达式+列表初始化 展开参数包
//逗号表达式展开参数包的方式，不需要通过递归终止函数，是直接在 展开函数体（expand函数体）中展开的
// a. 写一个处理参数的模板函数 b.在可变参数模板中写一个数组。c.使用列表初始化 + 逗号表达式初始化数组
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
    cout << "没有参数" << endl;
}

//3.直接用列表初始化
//实际上我们也可以不用逗号表达式，因为这里的问题就是初始化整型数组时必须用整数，那我们可以将处理函数的返回值设置为整型，然后用这个返回值去初始化整型数组也是可以的
// a. 在可变模板函数中写一个数组 b. 写一个返回值类型和数组类型系统的模板函数 c.用列表初始化来初始化函数
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
    cout << "没有参数" << endl;
}

int main()
{
    cout << "================1.递归展开参数包===============" << endl;
    funca(1, 2, 4, 5);
    funcb(3, 4, 5, 6, 7);
    funcc(4, 5, 6, 7, 8, 9);
    cout << "================2. 使用 逗号表达式+列表初始化 展开参数包===============" << endl;
    funcd(1, 2, 3, 4, 5, 6, 7, 8, 9);
    funcd(); //报错：不能分配常量大小为 0 的数组（要想支持无参，必须重载一个无参的同名函数）
    cout << "================3.直接用列表初始化===============" << endl;
    funce(); //报错：不能分配常量大小为 0 的数组（要想支持无参，必须重载一个无参的同名函数）
    funce(0, 1, 2, 3, 4, 5);
    return 0;
}