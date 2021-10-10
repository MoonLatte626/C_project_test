#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char a = -128;
	printf("%u\n", a);

	int i = -20;
	unsigned int j = 10;
	printf("%d\n", i + j);

	for  ( ; j >= 0; j--)
	{
		printf("%u\n", j);
	}

	return 0;
}