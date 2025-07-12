//***杨氏矩阵
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int find(int arr[3][3], int* px, int* py, int k)
{
	int x = *px - 1;
	int y = 0;
	while (x >= 0 && y <= 2)
	{
		if (k > arr[x][y])
		{
			y++;
		}
		else if (k < arr[x][y])
		{
			x--;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[3][3] = { 1,3,5,4,6,8,7,9,11};
	int x = 3;
	int y = 3;
	int k = 0;
	scanf("%d", &k);
	int ret = find(arr, &x, &y, k);
	if (ret == 1)
	{
		printf("找到了，下标是：%d %d", x, y);
	}
	if (ret == 0)
	{
		printf("没找到");
	}
	return 0;
}