
//��Ŀ����

//  https://leetcode.cn/search/?q=189
// ��ת����
//�����ⷨ ʱ�临�Ӷȣ�O(n^2)
void rotate(int* nums, int numsSize, int k)
{

	int i = 0;
	while (k--)
	{
		int end = nums[numsSize - 1];
		for (i = numsSize - 1; i > 0; i--)
		{
			nums[i] = nums[i - 1];
		}
		nums[0] = end;
	}
}