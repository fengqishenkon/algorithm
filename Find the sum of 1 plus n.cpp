#define _CRT_SECURE_NO_WARNINGS 


//https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

//用static修饰变成静态成员变量，使得生命周期被延长。
class sum
{
public:
    sum()
    {
        _ret += _i;
        ++_i;
    }
    static int Getreturn()
    {
        return _ret;
    }
private:
    static int _i;
    static int _ret;

};
int sum::_i = 1;
int sum::_ret = 0;

class Solution {
public:
    int Sum_Solution(int n)
    {
        sum arr[n];//分配足够容纳n个Sum对象的内存空间，对数组中的每个元素（从arr[0]到arr[n-1]）依次调用Sum类的构造函数，
                   //每次调用构造函数都会执行：_ret += _i ;  ++_i; 
      
        return sum::Getreturn();
    }
};