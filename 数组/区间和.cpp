#define _CRT_SECURE_NO_WARNINGS 


//区间和
/*

题目描述
给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。
输入描述
第一行输入为整数数组 Array 的长度 n，接下来 n 行，每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间下标：a，b （b > = a），直至文件结束。
输出描述
输出每个指定区间内元素的总和。
输入示例
5
1
2
3
4
5
0 1
1 3
输出示例
3
9

*/

//前缀和  

//想象你要快速知道书架上第3到第5本书的总页数。
//如果提前在每本书后面贴一张纸条，记录“从第一本到这里的总页数”（这就是前缀和），
//那么计算时只需用第5本的纸条数字减去第2本的纸条数字，省去了一本本翻的时间！


#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n;
    vector<int> vec(n);
    vector<int>p(n);
    int i = 0;
    int presum = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &vec[i]);
        presum += vec[i];
        p[i] = presum;
    }

    while (scanf("%d%d", &a, &b) != EOF)
    {
        if (a == 0)
        {
            printf("%d", p[b]);
        }
        else
        {
            printf("%d", p[b] - p[a - 1]);
        }
        printf("\n");
    }

}
