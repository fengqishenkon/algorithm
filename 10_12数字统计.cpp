#define _CRT_SECURE_NO_WARNINGS 

//BC153Êý×ÖÍ³¼Æ
#include<iostream>
using namespace std;
int main()
{
	int l, r;
	cin >> l >> r;
	int ret = 0;
	for (int i = l; i <= r; i++)
	{
		int tmp = i;
		while (tmp)
		{
			if (tmp % 10 == 2)ret++;
			tmp /= 10;
		}
	}
	return 0;
}