#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include <assert.h>
#include"SeqList.h"
//�ṹ���ʼ��
void SLinit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SLCheckCapacity(SL* ps)
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
		
}

//��ӡ���
void SLprinf(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//β�巨
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}
	
//ͷ�巨
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

//������λ��֮ǰ����
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


//������λ��֮�����
void SLInsertBack(SL* ps, int pos, SLDataType x)
{
	//assert(ps);���Ʋ�������ֱ�Ӹ�NULL
	//assert(ps->size);˳�����Ϊ��
	assert(ps && ps->size);

	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos+1; i--)
	{
		ps->arr[i] = ps->arr[i - 1];

	}	
	ps->arr[pos+1] = x;
	ps->size++;

}


//βɾ��

void SLPopBack(SL* ps)
{
	assert(ps && ps->size);
	ps->size--;
}

//ͷɾ��
void SLPopFront(SL* ps)
{

	assert(ps && ps->size);
	for (int i = 0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i+1];
	}
	ps->size--;
}



//ɾ��posλ�õ�����
void SLErase(SL* ps, int pos)
{
	assert(ps && ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}



//����

int SLFind(SL* ps, SLDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			//�ҵ���
			return 1;
		}
	}
	//û�ҵ�
	return -1;
}


//����
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

