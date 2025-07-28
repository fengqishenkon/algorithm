
//  https://leetcode.cn/problems/remove-duplicates-from-sorted-array/


//˫ָ�뷨
int removeDuplicates(int* nums, int numsSize)
{
    int dst = 0;
    int src = 1;
    while (src < numsSize)
    {
        if (nums[src] != nums[dst] && ++dst != src)
        {
            nums[dst] = nums[src];
        }
        src++;
    }
    return dst + 1;

}