#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//˫������Ľṹ
typedef int LTDatatype;
typedef struct ListNode
{
	LTDatatype data;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

//˫������Ĵ�ӡ
void LTPrint(LTNode* phead);

//�����½��
LTNode* LTBuyNode(LTDatatype x);

//˫������ĳ�ʼ�� �Լ�����Ͱ�����ͷ�
//void LTInit(LTNode** pphead);


//˫������ĳ�ʼ�� ֱ�����ͷ�
LTNode* LTInit();

//β��
void LTPushBack(LTNode* phead, LTDatatype x);

//ͷ��
void LTPushFront(LTNode* phead, LTDatatype x);