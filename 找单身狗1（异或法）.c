#define _CRT_SECURE_NO_WARNINGS 

//!!!�ҵ���1(��򷽷�)
/* 
  ^ ������� ��ͬΪ0������Ϊ1
  0^n=n

  ^���н���Ժͽ�����
  �磺3^5^3  �Ƕ����������Ƚ�  011^101 =110  110^011=101 --> 101Ϊ5
      ���൱�� 3^3^5 �����һ���� 3^3=0 0^5=5
	  ���Դ˴�����򷽷��ҵ�������һ���ĵ��� 1,2,3,4,5,1,2,3,4 �����Խ���Ϊ 1,1,2,2,3,3,4,4,5; ������� 0^0^0^0^5 Ϊ5
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
