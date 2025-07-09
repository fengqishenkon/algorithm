#define _CRT_SECURE_NO_WARNINGS

//***！！调整奇数偶数顺序

//***另外创建数组方法
#include<stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[(sizeof(arr) / sizeof(arr[0]))] = { 0 };
	int i, j = 0;
	for (i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		if (arr[i] % 2 != 0)
		{
			arr2[j] = arr[i];
			j++;
		}

	}

	for (i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{

		if (arr[i] % 2 == 0)
		{
			arr2[j] = arr[i];
			j++;
		}
	}

	for (i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		arr[i] = arr2[i];
	}
	for (i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}