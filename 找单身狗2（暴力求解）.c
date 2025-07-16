#define _CRT_SECURE_NO_WARNINGS 

//！！！找单身狗2（暴力求解）

#include<stdio.h>
void find_single_dog(int arr[], int num)
{
	int* p = arr;
	int i = 0;
	int j = 0;
	for (i = 0; i < num; i++)
	{
		int s = 0;
		int a = arr[i];
		for (j = 0; j < num; j++)
		{
			if (arr[j] == a)
			{
				s++;
			}
		}
		if (s == 1)
		{
			printf("%d\n", a);
		}
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,1,2,3,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	find_single_dog(arr, sz);
	return 0;
}