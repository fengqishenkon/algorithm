#define _CRT_SECURE_NO_WARNINGS 

//“∆∂Ø¡„

//https://leetcode.cn/problems/move-zeroes/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int cur = 0, dest = -1; cur < nums.size(); cur++)
        {
            if (nums[cur] != 0)
            {
                swap(nums[++dest], nums[cur]);
            }
        }
    }
};