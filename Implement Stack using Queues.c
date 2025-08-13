#define _CRT_SECURE_NO_WARNINGS 

//Implement Stack using Queues

//https://leetcode.cn/problems/implement-stack-using-queues/description/


typedef int QDataType;
//队列结点结构
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

//队列结构
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//入队——队尾
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
	//队列为空
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;

	}
	else//队列不为空
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}


//队列判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//出队——队头
void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	//只有一个结点，phead和ptail都置为空
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

//队列有效元素个数
int QueueSize(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->size;
}

//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->phead->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->ptail->data;
}


//销毁队列
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

//--------------------队列的实现--------------------------------

//test.c文件里面
//MyStack* obj=myStackCreate();
//myStackPush(obj,1);

//定义MyStack结构
typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


//初始化
MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

//压入x至栈顶
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

//将不为空的队列中的size-1个数据压入到空队列中
//将不为空的队列中的最后一个数据返回,并且移除最后一个数据
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

//返回栈顶元素
int myStackTop(MyStack* obj)
{
	//找到不为空的队列中的队尾数据

	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}

}

//判断栈是否为空
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

//test.c文件里面
//MyStack* obj=myStackCreate();
//myStackPush(obj,1);
//myStackFree(obj);

//销毁
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