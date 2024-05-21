#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/** <algorithm>�µ�sort��ζԱ��桰�Զ������� ����vector, list, deque, ���������أ�
	1. ���������� " < "�����(ֻ��operator < �Żᱻsortʶ��)
	2. ���ڱȽ�������ķº���
	3. ����ֵΪbool���͵ĺ���
*/


// 1. ���������� " < "�����(ֻ��operator < �Żᱻsortʶ��)
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
	// 1. ���������� " < "�����(ֻ��operator < �Żᱻsortʶ��
	bool operator< (const Score& s) const // �ǲ���const this ����
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

	int getMath()const { return _math; } //const�����޷����÷�const��Ա����
	//void setMath(int m) const { _math = m; } //const���εĳ�Ա�������޷��޸ĳ�Ա����
	void setMath(int m) { _math = m; }
	int getChinese()const { return _chinese; }
	void setChinese(int c) { _chinese = c; }
	int getEnglish()const { return _english; }
	void setEnglish(int e) { _english = e; }
};

// 2. ���ڱȽ�������ķº���
struct CompareDescending
{
	bool operator() (const Score& s1,const Score& s2)
	{
		if (s1.getMath() == s2.getMath()) //const�����޷����÷�const��Ա����
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
		if (s1.getMath() == s2.getMath()) //const�����޷����÷�const��Ա����
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

// 3. ����ֵΪbool���͵ĺ���
bool compareAscending(const Score& s1, const Score& s2)
{
	if (s1.getMath() == s2.getMath()) //const�����޷����÷�const��Ա����
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
	if (s1.getMath() == s2.getMath()) //const�����޷����÷�const��Ա����
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
	//1. ���������� " < "�����(ֻ��operator < �Żᱻsortʶ��)
	{
		cout << "============================1.���������� \" < \"�����(ֻ��operator < �Żᱻsortʶ��)=============================" << endl;
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

	//2. ���ڱȽ�������ķº���
	{
		cout << "============================2. ���ڱȽ�������ķº���=============================" << endl;
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

	//3. ����ֵΪbool���͵ĺ���
	{
		cout << "============================3. ����ֵΪbool���͵ĺ���=============================" << endl;
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