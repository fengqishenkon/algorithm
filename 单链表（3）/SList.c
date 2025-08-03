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
SLTNode* SLTbuyNode(SLTDataType x)
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

//尾插  
//时间复杂度 O(n)
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


//头插  
//时间复杂度 O(1)
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTbuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//尾删  
//时间复杂度 O(n)
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
 
//头删 
//时间复杂度 O(1)
void SLTPopPhead(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur!= NULL)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

//在指定位置之前插⼊数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && pos);
	
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = SLTbuyNode(x);
		SLTNode* prev = *pphead;
		//pos之前
		while ((prev->next) != pos)
		{
			prev = prev->next;
		}
		//prev p
		prev->next = newnode;
		newnode->next = pos;
	}
}

//在指定位置之后插⼊数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTbuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除pos结点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && pos);
	//pos就是头结点
	if (pos == *pphead)
	{
		SLTPopPhead(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos= NULL;
	}	
}

//删除pos之后的结点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del= NULL;
}

//销毁链表
void SListDestroy(SLTNode** pphead)
{
	SLTNode* pcur = *pphead;
	SLTNode* next =NULL;
	while (pcur)
	{
		next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}
