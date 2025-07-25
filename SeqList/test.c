#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include"SeqList.h"
void test1()
{
	SL sl;
	SLinit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);

}
int main()
{
	test1();

	return 0;
}
