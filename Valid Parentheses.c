
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//����ջ�Ľṹ
typedef char STDataType;
typedef struct stack
{
	STDataType* arr;
	int top;//ָ��ջ����λ��
	int capacity;//ջ������
}ST;

//��ʼ��
void StackInit(ST* ps)
{
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}
//����
void StackDestroy(ST* ps)
{
	if (ps->arr)
		free(ps->arr);
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}
//��ջ---ջ��
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		//����
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* tmp = (STDataType*)realloc(ps->arr, newCapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
	ps->arr[ps->top++] = x;
}
//ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
//��ջ����ջ��
void StackPop(ST* ps)
{
	assert(!StackEmpty(ps));
	--ps->top;
}
//ȡջ��Ԫ��
STDataType StackTop(ST* ps)
{
	assert(!StackEmpty(ps));
	return ps->arr[ps->top - 1];
}
//��ȡջ����ЧԪ�ظ���
int StackSize(ST* ps)
{
	return ps->top;
}
//-----------------------------ջ�Ĵ���-----------------------------------

bool isValid(char* s)
{
	ST st;
	StackInit(&st);
	char* pi = s;
	while (*pi != '\0')
	{
		//��������ջ
		if (*pi == '(' || *pi == '[' || *pi == '{')
		{
			StackPush(&st, *pi);
		}
		else//������ȡջ����*pi�Ƚ�
		{
			//�ж�ջΪ��
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}
			STDataType value = StackTop(&st);
			if ((value == '(' && *pi != ')')
				|| (value == '[' && *pi != ']')
				|| (value == '{' && *pi != '}'))
			{
				StackDestroy(&st);
				return false;
			}
			StackPop(&st);
		}
		pi++;
	}
	//�ж�ջջ�Ƿ�Ϊ��
	bool ret = StackEmpty(&st) ? true : false;
	StackDestroy(&st);
	return ret;

}