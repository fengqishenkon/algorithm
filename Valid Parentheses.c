
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//定义栈的结构
typedef char STDataType;
typedef struct stack
{
	STDataType* arr;
	int top;//指向栈顶的位置
	int capacity;//栈的容量
}ST;

//初始化
void StackInit(ST* ps)
{
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}
//销毁
void StackDestroy(ST* ps)
{
	if (ps->arr)
		free(ps->arr);
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}
//入栈---栈顶
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		//增容
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
//栈是否为空
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
//出栈——栈顶
void StackPop(ST* ps)
{
	assert(!StackEmpty(ps));
	--ps->top;
}
//取栈顶元素
STDataType StackTop(ST* ps)
{
	assert(!StackEmpty(ps));
	return ps->arr[ps->top - 1];
}
//获取栈中有效元素个数
int StackSize(ST* ps)
{
	return ps->top;
}
//-----------------------------栈的创建-----------------------------------

bool isValid(char* s)
{
	ST st;
	StackInit(&st);
	char* pi = s;
	while (*pi != '\0')
	{
		//左括号入栈
		if (*pi == '(' || *pi == '[' || *pi == '{')
		{
			StackPush(&st, *pi);
		}
		else//右括号取栈顶跟*pi比较
		{
			//判断栈为空
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
	//判断栈栈是否为空
	bool ret = StackEmpty(&st) ? true : false;
	StackDestroy(&st);
	return ret;

}