#include<iostream>
using std::cin;
using std::cout;
using std::endl;

//�º����� STL ���������֮һ
//�º�����ʵ�־������������� () ��������ʹ�ø���Ķ�����Ա��������������á�
// ��Щ����ͽ����º�����Functors����������Function Objects��


// �����淶�������ô��շ壬����������������С�շ壬ȫ�ֱ���������ȫ��д��
class FunctorGreaterCompare
{
public: 
	bool operator() (int a, int b)
	{
		return a > b;
	}
};

//�º���֧�ַ���
template<class T>
class FunctorLessCompare
{
public:
	bool operator()(T a, T b)
	{
		return a < b;
	}
};

//��ϰдһ���㷨�º�����ʵ��pow��sqrt
template<typename Iterator>
class FunctorAlgorithmPow
{
public: // class Ĭ��Ϊ˽��
	Iterator operator() (Iterator x)
	{
		return x * x;
	}
};

template<typename T4>
class FunctorAlgorithmSqrt
{
public:
	double operator() (T4 x)
	{
		double r = -10000000, l = 10000000, mid;
		while (l - r >= 1e-4)
		{
			mid = (r + l) / 2;
			if (mid * mid < x)
				r = mid;
			else if (mid * mid > x)
				l = mid;
			else
				return mid;
			
		}
		return l;
	}
};


int main()
{
	FunctorGreaterCompare fgc;
	cout << fgc(1, 2) << endl;

	FunctorLessCompare<int> iflc;
	cout << iflc(1, 2) << endl;
	
	FunctorLessCompare<double> dflc1;
	cout << dflc1(11, 2) << endl;

	FunctorAlgorithmPow<double> fap;
	cout << fap(2.0) << endl;

	FunctorAlgorithmSqrt<double> fas;
	cout << fas(4) << endl;
	return 0;
}