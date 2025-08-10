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

//只有一个头结点的情况下，双链表为空
bool LTEmpty(LTNode* phead)
{
    assert(phead);
    return phead->next == phead;
}
//尾删
void LTPopBack(LTNode* phead)
{
    assert(!LTEmpty(phead));
    LTNode* del = phead->prev;
    //phead del->prev del
    del->prev->next = phead;
    phead->prev = del->prev;
    free(del);
    del = NULL;
}

//头删
void LTPopFront(LTNode* phead)
{
    assert(!LTEmpty(phead));
    LTNode* del = phead->next;
    //phead del del->next
    phead->next = del->next;
    del->next->prev = phead;
    free(del);
    del = NULL;
}



//找结点
LTNode* LTFind(LTNode* phead, LTDatatype x)
{
    LTNode* pcur = phead->next;
    while (pcur!=phead)
    {
        if (pcur->data == x)
        {
            return pcur;
        }
        pcur = pcur->next;
    }
    return NULL;
}

//在pos位置之后插⼊数据
void LTInsert(LTNode* pos, LTDatatype x)
{
    assert(pos);
    LTNode* newnode = LTBuyNode(x);
    newnode->next = pos->next;
    pos->next->prev = newnode;
    pos->next = newnode;
    newnode->prev = pos;
}

//在pos位置之前插⼊数据
void LTBefore(LTNode* pos, LTDatatype x)
{
    assert(pos);
    LTNode* newnode = LTBuyNode(x);
    newnode->next=pos;
    newnode->prev = pos->prev;
    pos->prev->next = newnode;
    pos->prev = newnode;
}


//删除pos位置的结点
void LTErase(LTNode* pos)
{
    assert(pos);
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    free(pos);
    pos = NULL;
}

//销毁双向链表
void LTDesTroy(LTNode* phead)
{
    assert(phead);
    LTNode* pcur = phead->next;
    while (pcur != phead)
    {
        LTNode* next = pcur->next;
        free(pcur);
        pcur = next;
        next = next->next;
    }
    free(phead);
    phead = NULL;
}