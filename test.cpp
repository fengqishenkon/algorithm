#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;
void Func(int a = 10, int b = 20, int c = 30)
{
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
}
int main()
{
	Func();

	Func(1);
}