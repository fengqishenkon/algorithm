
//题目链接
//  https://leetcode.cn/search/?q=189
// 轮转数组
//时间复杂度 O(n),空间复杂度O(n)
void rotate(int* nums, int numsSize, int k)
{
	int arr[numsSize];
	int i = 0;
	for (i = 0; i < numsSize; i++)
	{
		arr[(i + k) % numsSize] = nums[i];
	}
	for (i = 0; i < numsSize; i++)
	{
		nums[i] = arr[i];
	}