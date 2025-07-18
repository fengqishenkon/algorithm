#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

// 32位版本宏
#define SWAP_ODD_EVEN(x) ((((unsigned)(x) & 0xAAAAAAAAu) >> 1) | (((unsigned)(x) & 0x55555555u) << 1))

// 打印二进制函数
void print_binary(unsigned num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); // 每4位空格
    }
    printf("\n");
}

int main() {
    unsigned test_num = 0x12345678; // 测试数据

    printf("原始值: 0x%08X\n", test_num);
    printf("二进制: ");
    print_binary(test_num);

    unsigned result = SWAP_ODD_EVEN(test_num);

    printf("\n交换后: 0x%08X\n", result);
    printf("二进制: ");
    print_binary(result);

    return 0;
}
