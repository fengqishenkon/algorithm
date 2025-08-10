#define _CRT_SECURE_NO_WARNINGS 
#include"dlist.h"

void test01()
{
	LTNode* plist=LTInit();
	//LTPrint(plist);
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPrint(plist);

	/*LTPushFront(plist, 4);r
	LTPrint(plist);*/
	//LTPopBack(plist);
	//LTPrint(plist);

	//LTPopBack(plist);
	//LTPrint(plist);

	//LTPopBack(plist);
	//LTPrint(plist);

	//LTPopBack(plist);
	//LTPrint(plist);

	//LTPopBack(plist);
	//LTPrint(plist);

	//LTPopFront(plist);
	//LTPrint(plist);

	//LTPopFront(plist);
	//LTPrint(plist);

	//LTPopFront(plist);
	//LTPrint(plist);

	//LTPopFront(plist);
	//LTPrint(plist);

	//

	
	/*if (find==NULL)
	{
		printf("没找到");
	}
	else
	{
		printf("找到了");
	}*/

	LTNode* find = LTFind(plist, 4);
	/*LTInsert(find,50);
	LTPrint(plist);*/

	/*LTErase(find);
	LTPrint(plist);*/

	LTBefore(find, 30);
	LTPrint(plist);
	find = NULL;

	LTDesTroy(plist);
	plist = NULL;
}
int main()
{
	test01();
	return 0;
}