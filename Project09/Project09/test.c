#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 3;
	int b = 5;
	printf("%d\n", a & b);//1
	printf("%d\n", a | b);//7
	printf("%d\n", a ^ b);//6

	return 0;
}