#include<stdio.h>
int main()
{
	int nums[] = { 2,7,5,11,14 ,6 };
	int target = 16;
	int i = 0;
	int j = 0;
	int sz = sizeof(nums) / sizeof(nums[0]);
	for (i = 0; i < sz; i++)
	{
		for (j = i + 1; j < sz; j++)
		{

			if ((nums[j] + nums[i]) == target)
			{
				printf("%d£¬%d\n", nums[i], nums[j]);
				break;
			}
		}
	}
	return 0;
}