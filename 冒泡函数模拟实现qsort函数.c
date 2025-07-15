#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stu
{
	char name[20];
	int age;
};

void print_arr(struct Stu arr[], size_t sz)
{
	int i = 0;

	for (i = 0; i < sz; i++)
	{
		printf("%s %d ", arr[i].name, arr[i].age);
		//printf("%d ", arr[i].age);
	}
	printf("\n");
}

void print_int(int arr[], size_t sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}

int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void swap(char* buf1, char* buf2, size_t size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, size_t num, size_t size, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < num - 1; i++)//总共需要的趟数
	{
		for (j = 0; j < num - 1 - i; j++)//随着趟数的增加，每次比较的次数。
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)
			{
				swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
}

void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	//排列为升序
	int sz = sizeof(arr) / sizeof(arr[0]);
	print_int(arr, sz);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print_int(arr, sz);
}

void test2()
{
	struct Stu arr[] = { {"zhangsan",40},{"lisi",30},{"wangwu",15} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, sz);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_by_age);
	print_arr(arr, sz);
}

void test3()
{
	struct Stu arr[] = { {"zhangsan",40},{"lisi",30},{"wangwu",15} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, sz);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_by_name);
	print_arr(arr, sz);
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}
