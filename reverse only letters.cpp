
//topic: reverse only letters
//https://leetcode.cn/problems/reverse-only-letters/description/

//Problem Explanation: mainly the application of functions of the string class

class Solution {
public:

    bool isletter(char ch)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            return true;
        }

        if (ch >= 'a' && ch <= 'z')
        {
            return true;
        }

        return false;
    }
    string reverseOnlyLetters(string s)
    {
        if (s.empty())
            return s;

        size_t begin = 0, end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !isletter(s[begin]))
                ++begin;

            while (begin < end && !isletter(s[end]))
                --end;

            swap(s[begin], s[end]);
            ++begin;
            --end;
        }
        return s;
    }
};

