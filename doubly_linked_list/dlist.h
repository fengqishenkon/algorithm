#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//双向链表的结构
typedef int LTDatatype;
typedef struct ListNode
{
	LTDatatype data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

//双向链表的打印
void LTPrint(LTNode* phead);

//创建新结点
LTNode* LTBuyNode(LTDatatype x);

//双向链表的初始化 自己带油桶，买油法
//void LTInit(LTNode** pphead);


//双向链表的初始化 直接买油法
LTNode* LTInit();

//尾插
void LTPushBack(LTNode* phead, LTDatatype x);

//头插
void LTPushFront(LTNode* phead, LTDatatype x);