#define _CRT_SECURE_NO_WARNINGS 
#include<string>
#include<iostream>
using namespace std;


//快速排序的实现

//简述基本思路：是在一个数组当中找到一个基准值，通常是第一个或随机值或者三数取中，然后遍历数组把比基准值小的放在左边，比基准值大的放在右边，再校准基准值的位置
//然后再对左边数组和右边数组进行一样的递归操作，直到子数组的元素为一个或者零个，完成排序。

//对arr进行排序
void quick_sort(int arr[], int start, int end)
{
	if (start >= end) return ;
	int p = arr[start];
	int lt = start;
	int rt = end;
	while (lt < rt)
	{
		//右指针找比p小的
		while (arr[rt] >= p && lt<rt) rt--;
		//左指针找比p大的数值
		while (arr[lt] <= p && lt < rt) lt++;
		//两个值进行互换
		if (lt < rt)
		{
			swap(arr[lt], arr[rt]);

		}
	}

	//把基准值移动到适合的位置
	swap(arr[start], arr[rt]);


	//递归
	quick_sort(arr, start, rt - 1);
	quick_sort(arr, rt+1,end);
}

int a[110];
int n = 0;

int main()
{	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	quick_sort(a,0,n-1);

	for (int i = 0; i < n; i++)
	{
		cout<<a[i]<<endl;
	}

	return 0;
}

