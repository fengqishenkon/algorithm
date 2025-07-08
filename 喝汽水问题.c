//*** ºÈÆûË®ÎÊÌâ

#include<stdio.h>
int main()
{
	int a = 20;
	int c = 0;
	int b = a;
	int sum = 20;
	while (a != 0)
	{
		sum += a / 2;
		c += a % 2;
		a = a / 2;
	}
	if (c != 0)
	{
		sum += c / 2;
	}
	printf("%d", sum);
	return 0;
}

