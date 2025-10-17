#define _CRT_SECURE_NO_WARNINGS 

//零移动
// https ://leetcode.cn/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int cur = 0, dest = -1; cur < nums.size(); cur++)//cur从0开始，dest从-1位置开始才能保证cur！=0时++dest位置和cur位置互换后正常
        {
            if (nums[cur] != 0)
            {
                swap(nums[++dest], nums[cur]);//非零元素和零元素互换
            }
        }
    }
}