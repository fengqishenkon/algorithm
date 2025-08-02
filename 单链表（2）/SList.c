#define _CRT_SECURE_NO_WARNINGS 
#include"SList.h"

//打印
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur!=NULL)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//创建一个新的节点
SLTbuyNode(SLTDataType x) 
{
	SLTNode* newnode =(SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//尾插法  时间复杂度 O(n)
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = SLTbuyNode(x); 
	//链表为空
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}


//头插法  时间复杂度 O(1)
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTbuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//尾删法  时间复杂度 O(n)
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	
	//只有一个结点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//找尾
	{
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
		
	}
}
 
//头删法 时间复杂度 O(1)
void SLTPopPhead(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}







