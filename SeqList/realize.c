#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include"SeqList.h"
//结构体初始化
void SLinit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLPushBack(SL* ps, SLDataType x)
{
	//判判断空间是否足够
	//不够
	if (ps->size == ps->capacity)
	{
		int newCapacity = (ps->capacity == 0 ? 4 : 2 * ps->capacity);
		//开辟内存
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
	//空间足够情况下
	ps->arr[ps->size++] = x;
	//ps->size=x;
	//ps->arr=ps->size;
}