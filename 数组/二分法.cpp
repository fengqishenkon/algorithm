#define _CRT_SECURE_NO_WARNINGS 

//https://leetcode.cn/problems/binary-search/description/

//×ó±ÕÓÒ±Õ
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};




//×ó±ÕÓÒ¿ª


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > target)
            {
                right = mid;
            } 
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};

