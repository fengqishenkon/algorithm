#define _CRT_SECURE_NO_WARNINGS 

//topic:First_Unique_Character_in_a_String
//https://leetcode.cn/problems/first-unique-character-in-a-string/description/

//Problem Explanation:
//1¡¢By using the limited 26 letters, attempt to find the mapping of each character in the string to the 26 corresponding numbers.
//2¡¢Using the mapped number 1, locate the corresponding character in the string.
//3¡¢If no result is found, return 1.
class Solution {
public:
    int firstUniqChar(string s)
    {
        int count[26] = { 0 };
        for (auto e : s)
        {
            count[e - 'a']++;
        }
        for (size_t i = 0; i < s.size(); i++)
        {

            if (count[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};