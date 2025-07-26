#define _CRT_SECURE_NO_WARNINGS 
//
#include<stdio.h>
#include"SeqList.h"
void test1()
{
	SL sl;
	SLinit(&sl);
	SLPushBack(&sl,1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);

	SLprinf(&sl);
	/*SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);*/

	/*SLPopBack(&sl);
	SLprinf(&sl);

	SLPopBack(&sl);
	SLprinf(&sl);
	
	SLPopBack(&sl);
	SLprinf(&sl);
	
	SLPopBack(&sl);
	SLprinf(&sl);

	SLPopBack(&sl);
	SLprinf(&sl);

	SLPopBack(&sl);
	SLprinf(&sl);*/

	/*SLInsertFront(&sl,1,100);

	SLprinf(&sl);

	SLInsertBack(&sl, 2, 50);

	SLprinf(&sl);

	SLInsertBack(&sl, 3, 20);

	SLprinf(&sl);

	SLInsertBack(&sl, 1, 19);

	SLprinf(&sl);*/

	SLErase(&sl, 4);

	SLprinf(&sl);

	int find=SLFind(&sl, 2);
	if (find == 1)
	{
		printf("找到了！");
	}
	else
	{
		printf("没找到！");
	}
	SLDestroy(&sl);
}
int main()
{
	test1();

	return 0;
}


