#define _CRT_SECURE_NO_WARNINGS 

//大体思路：
// ！因为有两个不一样的数字，要把未知问题转化成已知问题，
// ！要把两个单身狗问题转化成已知的一个单身狗问题来求解，就需要把两个数字分开求
// 1、因为所有的数字^后得到的是5和6的异或，结果为3  011 
// 2、011 为1的有两位说明这两个不一样的数字，里面有两位结果不同，要依据这两位结果不同的位来分组 
// 3、我们选取其中第一位来分组，那么绝对可以分开5和6


#include<stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int r = 0;
	int pos = 0;

	//1、全部异或，找到异或后的结果r

	for (i = 0; i < sz; i++)
	{
		r ^= arr[i];
	}
	//2、找到分组位数pos
	for (i = 0; i < 32; i++)
	{
		if (((r >> i) & 1) == 1)
		{
			pos = i;
		}
	}
	//3、按照pos这一位来分组
	int s1 = 0;
	int s2 = 0;
	for (i = 0; i < sz; i++)
	{
		if ((arr[i] >> pos) & 1 == 1)
		{
			s1 ^= arr[i];
		}
		else
		{
			s2 ^= arr[i];
		}
	}
	printf("s1=%d s2=%d", s1, s2);
}
