#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//定义链表的结构---结点的结构
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;


//链表的打印
void SLTPrint(SLTNode* phead);


//创建一个新的节点
SLTbuyNode(SLTDataType x);

//尾插

void SLTPushBack(SLTNode** pphead, SLTDataType x);

//头插法
void SLTPushFront(SLTNode** pphead, SLTDataType x);


//尾删法
void SLTPopBack(SLTNode** pphead);

//头删法
void SLTPopPhead(SLTNode** pphead);