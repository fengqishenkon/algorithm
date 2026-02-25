#define _CRT_SECURE_NO_WARNINGS 

//https://leetcode.cn/problems/minimum-size-subarray-sum/

//±©Á¦½â·¨
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int result = INT32_MAX;
        int sublength = 0;
        int sum = 0;
        // int sublength1=0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum >= target)
                {
                    sublength = j - i + 1;
                    result = result < sublength ? result : sublength;
                    break;

                }
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};