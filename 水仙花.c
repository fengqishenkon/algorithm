
//*** ˮ�ɻ���

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// �ж�һ�����Ƿ�Ϊˮ�ɻ���
bool is_narcissistic(int num) {
    if (num == 0) {
        return true; // 0 ��ˮ�ɻ���
    }

    // �������ֵ�λ�� n
    int n = (int)log10(num) + 1;
    int temp = num;
    int sum = 0;

    // �ֽ����ֲ������λ���ֵ� n �η�֮��
    while (temp != 0) {
        int digit = temp % 10;
        // ʹ�� pow �������� n �η�
        sum += pow(digit, n);
        temp /= 10;
    }

    return sum == num;
}