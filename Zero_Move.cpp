#define _CRT_SECURE_NO_WARNINGS 

//���ƶ�
// https ://leetcode.cn/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int cur = 0, dest = -1; cur < nums.size(); cur++)//cur��0��ʼ��dest��-1λ�ÿ�ʼ���ܱ�֤cur��=0ʱ++destλ�ú�curλ�û���������
        {
            if (nums[cur] != 0)
            {
                swap(nums[++dest], nums[cur]);//����Ԫ�غ���Ԫ�ػ���
            }
        }
    }
}