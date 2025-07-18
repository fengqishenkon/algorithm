#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define Y(n) (sizeof(n))
int main()
{
	struct Stu
	{
		int name[20];
		int age;
	}stu;

	int a = Y(stu.name);
	printf("%d\n", a);
	return 0;
}