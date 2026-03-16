#define _CRT_SECURE_NO_WARNINGS 


//https://leetcode.cn/problems/reverse-string/description/
//·´×ª×Ö·û´®


class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};