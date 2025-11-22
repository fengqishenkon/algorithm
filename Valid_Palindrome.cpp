#define _CRT_SECURE_NO_WARNINGS 

//topic:Valid Palindrome
//https://leetcode.cn/problems/valid-palindrome/description/

//Problem Explanation :Using various functions of the string object, 
//1¡¢we can sequentially achieve the removal of non-alphanumeric characters, 
//2¡¢case conversion, and 
//3¡¢string reversal.

class Solution {
public:
    bool isPalindrome(string s)
    {
        string cleaned;
        for (char c : s)
        {
            if (isalnum(c))
            {
                cleaned += tolower(c);
            }
        }
        string reversed = cleaned;
        reverse(reversed.begin(), reversed.end());
        return cleaned == reversed;
    }
};