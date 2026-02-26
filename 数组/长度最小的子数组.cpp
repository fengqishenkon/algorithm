#define _CRT_SECURE_NO_WARNINGS 

//https://leetcode.cn/problems/minimum-size-subarray-sum/

//暴力解法
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



//滑动窗口法

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int result = INT32_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= target) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};