#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

// 32λ�汾��
#define SWAP_ODD_EVEN(x) ((((unsigned)(x) & 0xAAAAAAAAu) >> 1) | (((unsigned)(x) & 0x55555555u) << 1))

// ��ӡ�����ƺ���
void print_binary(unsigned num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); // ÿ4λ�ո�
    }
    printf("\n");
}

int main() {
    unsigned test_num = 0x12345678; // ��������

    printf("ԭʼֵ: 0x%08X\n", test_num);
    printf("������: ");
    print_binary(test_num);

    unsigned result = SWAP_ODD_EVEN(test_num);

    printf("\n������: 0x%08X\n", result);
    printf("������: ");
    print_binary(result);

    return 0;
}
