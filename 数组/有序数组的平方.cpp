#define _CRT_SECURE_NO_WARNINGS 


//https://leetcode.cn/problems/squares-of-a-sorted-array/


//暴力法
class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
        }

        sort(nums.begin(), nums.end());
        return nums;

    }
};



//双指针法

class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int>result(nums.size(), 0);//一定要赋初始值
        int i = 0;
        int j = nums.size() - 1;
        int k = nums.size() - 1;
        while (i <= j)
        {
            if (nums[i] * nums[i] < nums[j] * nums[j])
            {
                result[k--] = nums[j] * nums[j];
                j--;
            }
            else
            {
                result[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return result;
    }
};
