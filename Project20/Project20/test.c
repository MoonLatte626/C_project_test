#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a[4] = { 1,2,3,4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x\n%x\n", ptr1[-1], *ptr2);

	int b[3][2] = { (0,1),(2,3),(3,4) };
	int* p;
	p = b[0];
	printf("%d\n", p[0]);

	return 0;
}