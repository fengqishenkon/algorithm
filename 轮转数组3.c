//题目链接
//  https://leetcode.cn/search/?q=189
// 轮转数组


//reverse方法
//时间复杂度 O(n),空间复杂度O(1)

//步骤：
//1、先逆转前numsSize - k个数字
//2、再逆转后k个数字
//3、最后整体逆转


void reverse(int* nums, int left, int right)
{

	while (left < right)
	{
		int temp = 0;
		temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		left++;
		right--;
	}
}

void rotate(int* nums, int numsSize, int k)
{
	k = k % numsSize;
	reverse(nums, 0, numsSize - k - 1);
	reverse(nums, numsSize - k, numsSize - 1);
	reverse(nums, 0, numsSize - 1);

}