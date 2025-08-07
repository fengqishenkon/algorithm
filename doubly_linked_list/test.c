#define _CRT_SECURE_NO_WARNINGS 
#include"dlist.h"

void test01()
{
	LTNode* plist=LTInit();
	//LTPrint(plist);
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	//LTPrint(plist);

	LTPushFront(plist, 4);
	LTPrint(plist);

}
int main()
{
	test01();
	return 0;
}