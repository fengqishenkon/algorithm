#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include"SeqList.h"
//�ṹ���ʼ��
void SLinit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLPushBack(SL* ps, SLDataType x)
{
	//���жϿռ��Ƿ��㹻
	//����
	if (ps->size == ps->capacity)
	{
		int newCapacity = (ps->capacity == 0 ? 4 : 2 * ps->capacity);
		//�����ڴ�
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));

		if (tmp == NULL)
		{
			printf("realloc fail !");
			exit(1);
		}
		else
		{
			ps->arr = tmp;
			ps->capacity = newCapacity;
		}
	}
	//�ռ��㹻�����
	ps->arr[ps->size++] = x;
	//ps->size=x;
	//ps->arr=ps->size;
}