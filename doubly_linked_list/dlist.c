#define _CRT_SECURE_NO_WARNINGS 
#include"dlist.h"

void LTPrint(LTNode* phead)
{
    LTNode* pcur = phead->next;
    while (pcur != phead)
    {
        printf("%d  -> ", pcur->data);
        pcur = pcur->next;
    }
    printf("\n");
}


//创建新结点
LTNode* LTBuyNode(LTDatatype x)
{
    LTNode* newnode=(LTNode*)malloc(sizeof(LTNode));
    if (newnode == NULL)
    {
        printf("malloc fail!");
        exit(1);
    }
    newnode->data = x;
    newnode->next = newnode->prev = newnode;
    return newnode;
}

//双向链表的初始化   自己带油桶,买油法
//void LTInit(LTNode** pphead)
//{
//     assert(pphead);
//     *pphead = LTBuyNode(-1);
//}

//双向链表的初始化  直接买油法
LTNode* LTInit()
{
    LTNode* phead = LTBuyNode(-1);
    return phead;
}

//尾插
void LTPushBack(LTNode* phead, LTDatatype x)
{
    assert(phead);
    LTNode* newnode = LTBuyNode(x);
    //phead头结点  phead->prev 尾结点  newnode新的尾结点
    newnode->next = phead;
    newnode->prev = phead->prev;

    phead->prev->next = newnode;

    phead->prev = newnode;
}

//头插
void LTPushFront(LTNode* phead, LTDatatype x)
{
    assert(phead);
    LTNode* newnode = LTBuyNode(x);
    newnode->next = phead->next;
    newnode->prev = phead;

    phead->next->prev = newnode;
    phead->next = newnode;
}