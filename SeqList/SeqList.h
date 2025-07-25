#define _CRT_SECURE_NO_WARNINGS 
//定义动态顺序表的结构
typedef int SLDataType;
struct SeqList
{
	SLDataType* arr;//指针
	int size;//元素个数
	int capacity;//总容量
};
typedef struct SeqList SL;

//函数声明
void SLinit(SL* ps);

void SLPushBack(SL* ps, SLDataType x);