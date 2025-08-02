#define _CRT_SECURE_NO_WARNINGS 
#include"SList.h"

//��ӡ
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

//����һ���µĽڵ�
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

//β�巨  ʱ�临�Ӷ� O(n)
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = SLTbuyNode(x); 
	//����Ϊ��
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//��β
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}


//ͷ�巨  ʱ�临�Ӷ� O(1)
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTbuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//βɾ��  ʱ�临�Ӷ� O(n)
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	
	//ֻ��һ�����
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//��β
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
 
//ͷɾ�� ʱ�临�Ӷ� O(1)
void SLTPopPhead(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}







