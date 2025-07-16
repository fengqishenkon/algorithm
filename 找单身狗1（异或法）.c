#define _CRT_SECURE_NO_WARNINGS 

//!!!找单身狗1(异或方法)
/* 
  ^ 两两相比 相同为0，相异为1
  0^n=n

  ^具有结合性和交换性
  如：3^5^3  是二进制数作比较  011^101 =110  110^011=101 --> 101为5
      就相当于 3^3^5 结果是一样的 3^3=0 0^5=5
	  所以此处用异或方法找单身狗，是一样的道理 1,2,3,4,5,1,2,3,4 都可以交换为 1,1,2,2,3,3,4,4,5; 最后结果是 0^0^0^0^5 为5
*/


#include<stdio.h>
int fing_single_dog(int* p, int num)
{
	int i = 0;
	int ret = 0;
	for (i = 0; i < num; i++)
	{
		ret ^= *(p + i);
	}
	return ret;
}
int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int a = fing_single_dog(arr, sz);
	printf("%d ", a);
	return 0;
}
