#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void test()
{
	static int i = 0;
	i++;
	printf("%d\n", i);
}

int main()
{
	int a = 0, b = 1;
	printf("%d\n", a & b);
	printf("%d\n", a | b);

	int q = 0;
	printf("%d\n", ~q);

	printf("--------------------------------------------------------------------");

	int w = 0;
	while (w < 10)
	{
		test();
		w++;
	}


	return 0;
}

