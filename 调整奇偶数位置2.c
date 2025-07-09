#define _CRT_SECURE_NO_WARNINGS

//***！！调整奇数偶数顺序
// 
//***直接在本数组中的方法（双指针法）

#include<stdio.h>
int main()
{
	int arr[] = { 20,19,11,1,2,3,4,5,6,7,8,9,10,22,31,43 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		//找偶数
		while ((left < right)&&((arr[left] % 2) != 0))
		{
			left++;
		}
		//找奇数
		while ((left < right)&&((arr[right] % 2) == 0))
		{
			right--;
		}
		if (left < right)
		{
			int swap = 0;
			swap = arr[left];
			arr[left] = arr[right];
			arr[right] = swap;
		}
	}
	int i = 0;
	for(i=0;i<sz;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
