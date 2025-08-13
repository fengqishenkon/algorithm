#define _CRT_SECURE_NO_WARNINGS 

//Implement Queue using Stacks

//https://leetcode.cn/problems/implement-queue-using-stacks/description/


//����ջ�Ľṹ
typedef int STDataType;
typedef struct stack
{
    STDataType* arr;
    int top;//ָ��ջ����λ��
    int capacity;//ջ������
}ST;

//��ʼ��ջ
void StackInit(ST* ps)
{
    ps->arr = NULL;
    ps->capacity = ps->top = 0;
}


//��ջ---ջ��
void StackPush(ST* ps, STDataType x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        //����
        int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
        STDataType* tmp = (STDataType*)realloc(ps->arr, newCapacity * sizeof(STDataType));//realloc��������һ���ռ䣬Ҫ��ps������еĿռ��㹻��
                                                                                  //���صĵ�ַtmp����ps�ĵ�ַ��Ҫ��ps����Ŀ��пռ䲻
                                                                                 //���ͷ���һ���µ�ַ�����Ұ�ԭ�е����ݿ������µ�ַ��
        if (tmp == NULL)
        {
            printf("realloc fail!");
            exit(1);
        }
        ps->arr = tmp;
        ps->capacity = newCapacity;
    }
    ps->arr[ps->top++] = x;
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
    return ps->top == 0;
}

//��ջ����ջ��
void StackPop(ST* ps)
{
    assert(!StackEmpty(ps));
    ps->top--;
}

//ȡջ��Ԫ��
STDataType StackTop(ST* ps)
{
    assert(!StackEmpty(ps));
    return ps->arr[ps->top - 1];
}

//��ȡջ����ЧԪ�ظ���
int StackSize(ST* ps)
{
    return ps->top;
}

//����
void StackDestroy(ST* ps)
{
    if (ps->arr)
    {
        free(ps->arr);
    }
    ps->arr = NULL;
    ps->capacity = ps->top = 0;
}

//--------------ջ�Ĵ���------------------

typedef struct {
    ST pushST;
    ST popST;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&pq->pushST);
    StackInit(&pq->popST);
    return pq;
}

void myQueuePush(MyQueue* obj, int x) {
    StackPush(&obj->pushST, x);
}

//���popST�Ƿ�Ϊ��
//1����Ϊ��ֱ�ӳ�ջ��
//��2��Ϊ�գ���pushST������ȫ������popST���棬�ٳ�ջ��  
int myQueuePop(MyQueue* obj) {
    if (StackEmpty(&obj->popST))
    {
        //������
        while (!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST, StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }

    }

    int top = StackTop(&obj->popST);
    StackPop(&obj->popST);
    return top;


}

int myQueuePeek(MyQueue* obj) {
    if (StackEmpty(&obj->popST))
    {
        //������
        while (!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST, StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }

    }
    int top = StackTop(&obj->popST);
    return top;
}

bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
    StackDestroy(&obj->pushST);
    StackDestroy(&obj->popST);
    free(obj);
    obj = NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/