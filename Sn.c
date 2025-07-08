//*** 求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，例如：2 + 22 + 222 + 2222 + 22222


#include<stdio.h>
int main()
{
	int i = 0;
	int a = 0;
	int b = 0;
	int sn = 0;
	scanf("%d", &a);
	b = a;
	for (i = 0; i < 4; i++)
	{

		sn += a * 10 + b;
		a = a * 10 + b;
	}
	sn += b;
	printf("%d", sn);
	return 0;
}
