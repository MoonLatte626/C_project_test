#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = -16;
	int b = a >> 1;
	printf("%d\n", b);
	int c = a << 1;
	printf("%d\n", c);

	int x = -1;
	int y = x >> 1;
	printf("%d\n", y);

	int q = -5;
	int p = q << 1;
	printf("%d\n", p);

	return 0;
}