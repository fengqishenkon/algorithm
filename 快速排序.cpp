#define _CRT_SECURE_NO_WARNINGS 
#include<string>
#include<iostream>
#include<cstdlib>  //rand()、srand() 函数需要的头文件
#include<ctime>   //time() 函数需要的头文件
using namespace std;


//快速排序的实现

//简述基本思路：是在一个数组当中找到一个基准值，通常是第一个或随机值或者三数取中，然后遍历数组把比基准值小的放在左边，比基准值大的放在右边，再校准基准值的位置
//然后再对左边数组和右边数组进行一样的递归操作，直到子数组的元素为一个或者零个，完成排序。


//最优时间复杂度：O(nlog n)
//最差时间复杂度：O(n^2)
//平均时间复杂度,每种分区的概率是一样的：O(nlog n)

//对arr进行排序



//随机选取基准值法
//void quick_sort(int arr[], int start, int end)
//{
//	if (start >= end) return ;
//
//	int random_idx = start + rand() % (end - start + 1);
//	swap(arr[start], arr[random_idx]);
//	int p = arr[start];
//	int lt = start;
//	int rt = end;
//	while (lt < rt)
//	{
//		//以左边为基准值的时候，先移右指针，再移左指针
// 
//		//右指针找比p小的
//		while (arr[rt] >= p && lt<rt) rt--;
//		//左指针找比p大的数值
//		while (arr[lt] <= p && lt < rt) lt++;
//		//两个值进行互换
//		if (lt < rt)
//		{
//			swap(arr[lt], arr[rt]);
//
//		}
//	}
//
//	//把基准值移动到适合的位置
//	swap(arr[start], arr[rt]);
//
//
//	//递归
//	quick_sort(arr, start, rt - 1);
//	quick_sort(arr, rt+1,end);
//}
//
//int a[110];
//int n = 0;
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//
//	quick_sort(a,0,n-1);
//
//	for (int i = 0; i < n; i++)
//	{
//		cout<<a[i]<<endl;
//	}
//
//	return 0;
//}
//
//

//最优解
//三数取中法，通常是工程中常用的方法

int find_median_idx(int arr[], int start, int mid, int end) 
{
	// 比较三个数，返回中位数的索引
	if ((arr[start] < arr[mid] && arr[mid] < arr[end]) || (arr[end] < arr[mid] && arr[mid] < arr[start])) {
		return mid; // mid是中位数
	}
	else if ((arr[mid] < arr[start] && arr[start] < arr[end]) || (arr[end] < arr[start] && arr[start] < arr[mid])) {
		return start; // start是中位数
	}
	else {
		return end; // end是中位数
	}
}


void quick_sort(int arr[], int start, int end)
{
	if (start >= end) return;
	int mid = start + (end - start) / 2; // 计算中点（避免溢出）
	int median_idx = find_median_idx(arr, start, mid, end); // 找中位数索引
	swap(arr[start], arr[median_idx]); // 将中位数交换到start位置（作为基准）
	//int random_idx = start + rand() % (end - start + 1);
	//swap(arr[start], arr[random_idx]);
	int p = arr[start];
	int lt = start;
	int rt = end;
	while (lt < rt)
	{
		//以左边为基准值的时候，先移右指针，再移左指针

		//右指针找比p小的
		while (arr[rt] >= p && lt < rt) rt--;
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
	quick_sort(arr, rt + 1, end);
}

int a[110];
int n = 0;

int main()
{
	cin >> n;

	// 核心逻辑不变：cin会自动读取空格分隔的数，无需逐个回车
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	quick_sort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}


