#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a[10] = { 0 };
	int* p = a;
	int* q = &a;
	printf("%p\n", q);
	printf("%p\n", p);

	int x = 0;
	int* w = &x;
	printf("%p\n", w);

	return 0;
}