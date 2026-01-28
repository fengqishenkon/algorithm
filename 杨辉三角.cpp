#define _CRT_SECURE_NO_WARNINGS 


//Ñî»ÔÈý½Ç
//https://leetcode.cn/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vv;
        vv.resize(numRows, vector<int>());
        for (size_t i = 0; i < numRows; ++i)
        {
            vv[i].resize(i + 1, 1);
        }
        for (size_t i = 2; i < vv.size(); ++i)
        {
            for (size_t j = 1; j < vv[i].size() - 1; ++j)
            {
                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
            }
        }
        return vv;

    }
};


