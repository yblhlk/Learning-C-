// 如何判断当前机器是大端还是小端？
#include<iostream>
using namespace std;

int main()
{
	// 法一：巧用指针 + 强转
	{
		int a = 0x0000000000000001; //a = 1的二进制表示。
	// 如果机器是大端，低地址保存高数位的字节，&a的第一个字节保存0x000即数字0
	// 如果机器是小端，低地址保存低数位的字节，&a的第一个字节保存0x001即数字1
	// 让指针p1指向整型变量a的第一个字节的地址
		char* p1 = (char*)&a;
		// 让指针p2指向整型变量a的第二个字节的地址
		char* p2 = (char*)&a + 1;
		cout << (int)*p1 << endl; //ASCII码为1的字符无法被打印出来，转为整型来打印
		cout << (int)*p2 << endl;
		// 通过判断a最低位地址中保存的数据来判断当前机器的大小端。
		if (*p1 == 1)
			cout << "当前机器是小端字节序。" << endl;
		else
			cout << "当前机器是大端字节序。" << endl;
	}

	// 法二：联合体union
	{
		cout << "=============巧用联合体判断大小端==============" << endl;
		// 联合体中未初始化的空间为随机值。
		union U
		{
			char c ;
			int i = 1; // 一个联合最多只能有一个字段初始值设定项
		};

		U u;
		if (u.c == u.i)
			cout << "当前机器是小端字节序。" << endl;
		else
			cout << "当前机器是大端字节序。" << endl;
		cout << u.c << endl;
		cout << u.i << endl;
	}

	return 0;
}