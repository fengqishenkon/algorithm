#define _CRT_SECURE_NO_WARNINGS 

//Implement Stack using Queues

//https://leetcode.cn/problems/implement-stack-using-queues/description/


typedef int QDataType;
//���н��ṹ
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

//���нṹ
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	int size;
}Queue;

//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//��ӡ�����β
void QueuePush(Queue* pq, QDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	//����Ϊ��
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;

	}
	else//���в�Ϊ��
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}


//�����п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//���ӡ�����ͷ
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	//ֻ��һ����㣬phead��ptail����Ϊ��
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;

}

//������ЧԪ�ظ���
int QueueSize(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->size;
}

//ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->phead->data;
}

//ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->ptail->data;
}


//���ٶ���
void QueueDestroy(Queue* pq)
{
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//--------------------���е�ʵ��--------------------------------

//test.c�ļ�����
//MyStack* obj=myStackCreate();
//myStackPush(obj,1);

//����MyStack�ṹ
typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


//��ʼ��
MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

//ѹ��x��ջ��
void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

//����Ϊ�յĶ����е�size-1������ѹ�뵽�ն�����
//����Ϊ�յĶ����е����һ�����ݷ���,�����Ƴ����һ������
int myStackPop(MyStack* obj) {
	Queue* emp = &obj->q1;
	Queue* noemp = &obj->q2;
	if (QueueEmpty(&obj->q2))
	{
		emp = &obj->q2;
		noemp = &obj->q1;
	}

	while (QueueSize(noemp) > 1)
	{
		QueuePush(emp, QueueFront(noemp));
		QueuePop(noemp);
	}
	int top = QueueFront(noemp);
	QueuePop(noemp);
	return  top;
}

//����ջ��Ԫ��
int myStackTop(MyStack* obj)
{
	//�ҵ���Ϊ�յĶ����еĶ�β����

	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}

}

//�ж�ջ�Ƿ�Ϊ��
bool myStackEmpty(MyStack* obj) {
	if (QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//test.c�ļ�����
//MyStack* obj=myStackCreate();
//myStackPush(obj,1);
//myStackFree(obj);

//����
void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
	obj = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/