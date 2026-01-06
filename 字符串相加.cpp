#define _CRT_SECURE_NO_WARNINGS 

//topic  https://leetcode.cn/problems/add-strings/description/
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
//你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int end1 = num1.size() - 1;
//        int end2 = num2.size() - 1; 
//        int val;
//        int carry = 0;//进位
//        int endless;    
//        string str; 
//        while (end1 >= 0 || end2 >= 0)
//        {
//            int x1 = end1 >= 0 ? num1[end1--] - '0' : 0;
//            int x2 = end2 >= 0 ? num2[end2--] - '0' : 0;
//            val = x1 + x2 + carry;
//            carry = val / 10;
//            endless = val % 10;
//            str += ('0' + endless);
//        }
//        if (carry == 1)
//        {
//            str += '1';
//        }
//        reverse(str.begin(), str.end());
//        return str;
//    }
//};

