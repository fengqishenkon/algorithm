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

//尾插法
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





