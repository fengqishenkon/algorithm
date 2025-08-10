#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//双向链表的结构
typedef int LTDatatype;
typedef struct ListNode
{
	LTDatatype data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

//当结点需要改变时，传二级指针。
//当结点不需要改变时，传一级指针。

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

//双链表判空
bool LTEmpty(LTNode* phead);

//尾删
void LTPopBack(LTNode* phead);

//头删
void LTPopFront(LTNode* phead);

//找结点
LTNode* LTFind(LTNode* phead, LTDatatype x);


//在pos位置之后插⼊数据
void LTInsert(LTNode* pos, LTDatatype x);

//在pos位置之前插⼊数据
void LTBefore(LTNode* pos, LTDatatype x);

//删除pos位置的结点
void LTErase(LTNode* pos);

//销毁双向链表
void LTDesTroy(LTNode* phead);