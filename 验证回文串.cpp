#define _CRT_SECURE_NO_WARNINGS 

//title 
//https://leetcode.cn/problems/valid-palindrome/


//method 1、
class Solution {
public:
    bool isPalindrome(string s)
    {
        string cleaned;
        for (char c : s)
        {
            if (isalnum(c))//判断字符是否是字母或数字
            {
                cleaned += tolower(c);//将字符转换为小写
            }
        }
        string reversed = cleaned;
        reverse(reversed.begin(), reversed.end());
        return cleaned == reversed;
    }
};

//method 2、
class Solution {
public:
    bool IsLetterOrNumber(char ch)//判断字符串中的是否有除字母，数字之外的字符
    {
        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
    bool isPalindrome(string s)
    {
        for (auto& ch : s)
        {
            if (ch >= 'A' && ch <= 'Z')
                ch += 32;
        }
        int begin, end;
        begin = 0;
        end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !IsLetterOrNumber(s[begin]))
                ++begin;
            while (begin < end && !IsLetterOrNumber(s[end]))
                --end;
            if (s[begin] != s[end])
            {
                return false;
            }
            else
            {
                ++begin;
                --end;
            }
        }
        return true;

    }
};

