#define _CRT_SECURE_NO_WARNINGS 



//https://leetcode.cn/problems/remove-element/description/
// 
//暴力解法
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == val)
            {
                for (int j = i + 1; j < size; j++)
                {
                    nums[j - 1] = nums[j];
                }
                i--;
                size--;
            }
        }
        return size;
    }
};



//快慢指针法
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int fast = 0;
        int slow = 0;
        for (fast = 0; fast < nums.size(); fast++)//通过快指针来找到符合新数组的元素，放入新数组里面
        {
            if (nums[fast] != val)
            {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

