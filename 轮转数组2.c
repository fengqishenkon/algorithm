
//��Ŀ����
//  https://leetcode.cn/search/?q=189
// ��ת����
//ʱ�临�Ӷ� O(n),�ռ临�Ӷ�O(n)
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