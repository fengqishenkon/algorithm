

//��������Ľ���
//https://www.nowcoder.com/practice/56ea71d1f4e94de2aaec10e985874cce?tpId=196&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=


//����취����hash��һ�������������е�ֵ������hash���棬Ȼ��Ա�����һ�����������ֵ��
//��ͬ��ֵ����ret���棬���Ұ�hash�����Ӧ����ֵɾ���������ظ���
class Solution
{

    bool hash[1001] = { 0 };
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ret;
        for (auto x : nums1)
        {
            hash[x] = true;
        }
        for (auto x : nums2)
        {
            if (hash[x])
            {
                ret.push_back(x);
                hash[x] = false;
            }
        }
        return ret;
    }

};