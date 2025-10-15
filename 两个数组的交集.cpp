

//两个数组的交集
//https://www.nowcoder.com/practice/56ea71d1f4e94de2aaec10e985874cce?tpId=196&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=


//解决办法：用hash表将一个数组里面所有的值，放入hash里面，然后对比另外一个数组里面的值，
//相同的值放入ret里面，并且把hash里面对应的数值删除，避免重复。
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