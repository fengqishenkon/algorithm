#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//��������Ľṹ---���Ľṹ
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;


//����Ĵ�ӡ
void SLTPrint(SLTNode* phead);


//����һ���µĽڵ�
SLTbuyNode(SLTDataType x);

//β��

void SLTPushBack(SLTNode** pphead, SLTDataType x);

//ͷ�巨
void SLTPushFront(SLTNode** pphead, SLTDataType x);


//βɾ��
void SLTPopBack(SLTNode** pphead);

//ͷɾ��
void SLTPopPhead(SLTNode** pphead);