#define _CRT_SECURE_NO_WARNINGS 
//***ð�������ʵ��
#include<stdio.h>
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	for (int c = 0; c < 10; c++)//��ӡ��ԭ��������
	{
		printf("%d ", arr[c]);
	}
	printf("\n");

	int sz = sizeof(arr) / sizeof(arr[0]);//ȷ������Ĵ�С
	int i = 0;
	int j = 0;
	for (j = 0; j < sz - 1; j++)//�ܹ���Ҫ������
	{
		for (i = 0; i < sz - 1 - j; i++)//�������������ӣ�ÿ�αȽϵĴ�����
		{
			if (arr[i] > arr[i + 1])
			{
				int tem = 0;
				tem = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tem;
			}
		}
	}

	for (int c = 0; c < 10; c++)//��ӡ��ԭ��������
	{
		printf("%d ", arr[c]);
	}
	printf("\n");
	return 0;
}