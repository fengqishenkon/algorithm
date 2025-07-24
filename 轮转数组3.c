//��Ŀ����
//  https://leetcode.cn/search/?q=189
// ��ת����


//reverse����
//ʱ�临�Ӷ� O(n),�ռ临�Ӷ�O(1)

//���裺
//1������תǰnumsSize - k������
//2������ת��k������
//3�����������ת


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