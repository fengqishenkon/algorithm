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

//β�巨
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





