#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include <assert.h>
#include"SeqList.h"
//结构体初始化
void SLinit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SLCheckCapacity(SL* ps)
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
		
}

//打印结果
void SLprinf(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//尾插法
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}
	
//头插法
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//在任意位置之前插入
void SLInsertFront(SL* ps, int pos,SLDataType x)
{
	assert(ps);
	assert(pos>=0 &&pos<=ps->size );

	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}


//在任意位置之后插入
void SLInsertBack(SL* ps, int pos, SLDataType x)
{
	//assert(ps);限制参数不能直接给NULL
	//assert(ps->size);顺序表不能为空
	assert(ps && ps->size);

	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos+1; i--)
	{
		ps->arr[i] = ps->arr[i - 1];

	}	
	ps->arr[pos+1] = x;
	ps->size++;

}


//尾删法

void SLPopBack(SL* ps)
{
	assert(ps && ps->size);
	ps->size--;
}

//头删法
void SLPopFront(SL* ps)
{

	assert(ps && ps->size);
	for (int i = 0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i+1];
	}
	ps->size--;
}



//删除pos位置的数据
void SLErase(SL* ps, int pos)
{
	assert(ps && ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}



//查找

int SLFind(SL* ps, SLDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			//找到了
			return 1;
		}
	}
	//没找到
	return -1;
}


//销毁
void SLDestroy(SL* ps)
{
	assert(ps);
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

