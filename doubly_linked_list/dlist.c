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


//�����½��
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

//˫������ĳ�ʼ��   �Լ�����Ͱ,���ͷ�
//void LTInit(LTNode** pphead)
//{
//     assert(pphead);
//     *pphead = LTBuyNode(-1);
//}

//˫������ĳ�ʼ��  ֱ�����ͷ�
LTNode* LTInit()
{
    LTNode* phead = LTBuyNode(-1);
    return phead;
}

//β��
void LTPushBack(LTNode* phead, LTDatatype x)
{
    assert(phead);
    LTNode* newnode = LTBuyNode(x);
    //pheadͷ���  phead->prev β���  newnode�µ�β���
    newnode->next = phead;
    newnode->prev = phead->prev;

    phead->prev->next = newnode;

    phead->prev = newnode;
}

//ͷ��
void LTPushFront(LTNode* phead, LTDatatype x)
{
    assert(phead);
    LTNode* newnode = LTBuyNode(x);
    newnode->next = phead->next;
    newnode->prev = phead;

    phead->next->prev = newnode;
    phead->next = newnode;
}