
//*** 水仙花数

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// 判断一个数是否为水仙花数
bool is_narcissistic(int num) {
    if (num == 0) {
        return true; // 0 是水仙花数
    }

    // 计算数字的位数 n
    int n = (int)log10(num) + 1;
    int temp = num;
    int sum = 0;

    // 分解数字并计算各位数字的 n 次方之和
    while (temp != 0) {
        int digit = temp % 10;
        // 使用 pow 函数计算 n 次方
        sum += pow(digit, n);
        temp /= 10;
    }

    return sum == num;
}