#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a[10];
	printf("%p\n", &a);
	printf("%p\n", &a + 1);
	printf("%p\n", a);
	printf("%p\n", a + 1);

	int b = 0;
	int* p = &b;
	int** pa = &p;
	printf("%p\n", p);
	printf("%p\n", *pa);
	printf("%d\n", **pa);
	printf("%d\n", b);
	
	return 0;
}