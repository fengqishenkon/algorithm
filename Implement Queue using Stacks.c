#define _CRT_SECURE_NO_WARNINGS 

//Implement Queue using Stacks

//https://leetcode.cn/problems/implement-queue-using-stacks/description/


//定义栈的结构
typedef int STDataType;
typedef struct stack
{
    STDataType* arr;
    int top;//指向栈顶的位置
    int capacity;//栈的容量
}ST;

//初始化栈
void StackInit(ST* ps)
{
    ps->arr = NULL;
    ps->capacity = ps->top = 0;
}


//入栈---栈顶
void StackPush(ST* ps, STDataType x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        //增容
        int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
        STDataType* tmp = (STDataType*)realloc(ps->arr, newCapacity * sizeof(STDataType));//realloc函数开辟一个空间，要是ps后面空闲的空间足够，
                                                                                  //返回的地址tmp就是ps的地址，要是ps后面的空闲空间不
                                                                                 //够就返回一个新地址，并且把原有的数据拷贝到新地址上
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

//判断栈是否为空
bool StackEmpty(ST* ps)
{
    return ps->top == 0;
}

//出栈——栈顶
void StackPop(ST* ps)
{
    assert(!StackEmpty(ps));
    ps->top--;
}

//取栈顶元素
STDataType StackTop(ST* ps)
{
    assert(!StackEmpty(ps));
    return ps->arr[ps->top - 1];
}

//获取栈中有效元素个数
int StackSize(ST* ps)
{
    return ps->top;
}

//销毁
void StackDestroy(ST* ps)
{
    if (ps->arr)
    {
        free(ps->arr);
    }
    ps->arr = NULL;
    ps->capacity = ps->top = 0;
}

//--------------栈的创建------------------

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

//检查popST是否为空
//1、不为空直接出栈顶
//；2、为空，把pushST的数据全部导到popST里面，再出栈顶  
int myQueuePop(MyQueue* obj) {
    if (StackEmpty(&obj->popST))
    {
        //导数据
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
        //导数据
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