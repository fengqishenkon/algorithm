#define _CRT_SECURE_NO_WARNINGS 
////定义动态顺序表的结构
typedef int SLDataType;
 struct SeqList
{
	SLDataType* arr;//指针
	int size;//元素个数
	int capacity;//总容量
};
 typedef struct SeqList SL;

 //函数声明

 void SLprinf(SL* ps);

 //初始化
 void SLinit(SL* ps);

//销毁
 void SLDestroy(SL* ps);

 //检查空间是否足够
 void SLCheckCapacity(SL* ps);
 
 //尾插法
 void SLPushBack(SL* ps, SLDataType x);

 //头插法
 void SLPushFront(SL* ps, SLDataType x);


 //尾删法
 void SLPopBack(SL* ps);

 //头删法
 void SLPopFront(SL* ps);

 //在任意位置之前插入
 void SLInsertFront(SL* ps, int pos,SLDataType x);

 //在任意位置之后插入
 void SLInsertBack(SL* ps, int pos, SLDataType x);

 //删除pos位置的数据
 void SLErase(SL* ps, int pos);

 //查找
int SLFind(SL* ps, SLDataType x);
