#define _CRT_SECURE_NO_WARNINGS 
//***冒泡排序的实现
#include<stdio.h>
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	for (int c = 0; c < 10; c++)//打印出原本的数组
	{
		printf("%d ", arr[c]);
	}
	printf("\n");

	int sz = sizeof(arr) / sizeof(arr[0]);//确定数组的大小
	int i = 0;
	int j = 0;
	for (j = 0; j < sz - 1; j++)//总共需要的趟数
	{
		for (i = 0; i < sz - 1 - j; i++)//随着趟数的增加，每次比较的次数。
		{
			if (arr[i] > arr[i + 1])
			{
				int tem = 0;
				tem = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tem;
			}
		}
	}

	for (int c = 0; c < 10; c++)//打印出原本的数组
	{
		printf("%d ", arr[c]);
	}
	printf("\n");
	return 0;
}