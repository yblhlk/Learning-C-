#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/** <algorithm>下的sort如何对保存“自定义类型 ”的vector, list, deque, 进行排序呢？
	1. 在类中重载 " < "运算符(只有operator < 才会被sort识别。)
	2. 用于比较两个类的仿函数
	3. 返回值为bool类型的函数
*/


// 1. 在类中重载 " < "运算符(只有operator < 才会被sort识别。)
class Score
{
private:
	int _math;
	int _chinese;
	int _english;
public:
	Score(int m, int c, int e)
		: _math(0), _chinese(0), _english(0)
	{
		_math = m;
		_chinese = c;
		_english = e;
	}
	// 1. 在类中重载 " < "运算符(只有operator < 才会被sort识别。
	bool operator< (const Score& s) const // 是不是const this 都行
	{
		if (this->_math == s._math)
		{
			if (this->_chinese == s._chinese)
				return this->_english > s._english;
			else
				return this->_chinese > s._chinese;
		}
		else
			return this->_math > s._math;
	}

	int getMath()const { return _math; } //const对象无法调用非const成员函数
	//void setMath(int m) const { _math = m; } //const修饰的成员函数中无法修改成员变量
	void setMath(int m) { _math = m; }
	int getChinese()const { return _chinese; }
	void setChinese(int c) { _chinese = c; }
	int getEnglish()const { return _english; }
	void setEnglish(int e) { _english = e; }
};

// 2. 用于比较两个类的仿函数
struct CompareDescending
{
	bool operator() (const Score& s1,const Score& s2)
	{
		if (s1.getMath() == s2.getMath()) //const对象无法调用非const成员函数
		{
			if (s1.getChinese() == s2.getChinese())
				return s1.getEnglish() > s2.getEnglish();
			else
				return s1.getChinese() > s2.getChinese();
		}
		else
			return s1.getMath() > s2.getMath();
	}
};

struct CompareAscending
{
	bool operator() (const Score& s1, const Score& s2)
	{
		if (s1.getMath() == s2.getMath()) //const对象无法调用非const成员函数
		{
			if (s1.getChinese() == s2.getChinese())
				return s1.getEnglish() < s2.getEnglish();
			else
				return s1.getChinese() < s2.getChinese();
		}
		else
			return s1.getMath() < s2.getMath();
	}
};

// 3. 返回值为bool类型的函数
bool compareAscending(const Score& s1, const Score& s2)
{
	if (s1.getMath() == s2.getMath()) //const对象无法调用非const成员函数
	{
		if (s1.getChinese() == s2.getChinese())
			return s1.getEnglish() < s2.getEnglish();
		else
			return s1.getChinese() < s2.getChinese();
	}
	else
		return s1.getMath() < s2.getMath();
}
bool compareDescending(const Score& s1, const Score& s2)
{
	if (s1.getMath() == s2.getMath()) //const对象无法调用非const成员函数
	{
		if (s1.getChinese() == s2.getChinese())
			return s1.getEnglish() > s2.getEnglish();
		else
			return s1.getChinese() > s2.getChinese();
	}
	else
		return s1.getMath() > s2.getMath();
}

int main()
{
	//1. 在类中重载 " < "运算符(只有operator < 才会被sort识别。)
	{
		cout << "============================1.在类中重载 \" < \"运算符(只有operator < 才会被sort识别。)=============================" << endl;
		vector<Score> sv{ {1, 2, 3}, {1, 3, 2}, {2, 3, 1}, {2, 4, 1},{19, 12, 13} };
		for (auto e : sv)
		{
			cout << "math : " << e.getMath() << ", chinese : " << e.getChinese() << ", english : " << e.getEnglish() << endl;
		}
		cout << ">>>sort(sv.begin(), sv.end());" << endl;
		sort(sv.begin(), sv.end());
		for (auto e : sv)
		{
			cout << "math : " << e.getMath() << ", chinese : " << e.getChinese() << ", english : " << e.getEnglish() << endl;
		}
	}

	//2. 用于比较两个类的仿函数
	{
		cout << "============================2. 用于比较两个类的仿函数=============================" << endl;
		vector<Score> sv{ {1, 2, 4}, {1, 2, 3}, {1, 3, 2}, {2, 3, 1}, {2, 4, 1},{19, 12, 13} };
		for (auto e : sv)
		{
			cout << "math : " << e.getMath() << ", chinese : " << e.getChinese() << ", english : " << e.getEnglish() << endl;
		}
		cout << ">>>sort(sv.begin(), sv.end(), CompareDescending());" << endl;
		sort(sv.begin(), sv.end(), CompareDescending());
		for (auto e : sv)
		{
			cout << "math : " << e.getMath() << ", chinese : " << e.getChinese() << ", english : " << e.getEnglish() << endl;
		}
		cout << ">>>sort(sv.begin(), sv.end(), CompareAscending());" << endl;
		sort(sv.begin(), sv.end(), CompareAscending());
		for (auto e : sv)
		{
			cout << "math : " << e.getMath() << ", chinese : " << e.getChinese() << ", english : " << e.getEnglish() << endl;
		}
	}

	//3. 返回值为bool类型的函数
	{
		cout << "============================3. 返回值为bool类型的函数=============================" << endl;
		vector<Score> sv{ {100, 199, 100}, {1, 2, 3}, {1, 3, 2}, {2, 3, 1}, {2, 4, 1},{19, 12, 13} };
		for (auto e : sv)
		{
			cout << "math : " << e.getMath() << ", chinese : " << e.getChinese() << ", english : " << e.getEnglish() << endl;
		}
		cout << ">>>sort(sv.begin(), sv.end(), compareDescending);" << endl;
		sort(sv.begin(), sv.end(), compareDescending);
		for (auto e : sv)
		{
			cout << "math : " << e.getMath() << ", chinese : " << e.getChinese() << ", english : " << e.getEnglish() << endl;
		}
		cout << ">>>sort(sv.begin(), sv.end(), compareAscending);" << endl;
		sort(sv.begin(), sv.end(), compareAscending);
		for (auto e : sv)
		{
			cout << "math : " << e.getMath() << ", chinese : " << e.getChinese() << ", english : " << e.getEnglish() << endl;
		}
	}
	return 0;
}