#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int a = 10;
	int b = 20;

	printf("%p\n", &Add);
	printf("%d\n", Add(a, b));

	int(*pa)(int, int) = Add;
	printf("%d\n", pa(2, 3));//函数名本身就是一个地址
	printf("%d\n", (*pa)(2, 3));
	printf("%d\n", (**pa)(2, 3));
	printf("%d\n", (***pa)(2, 3));

	return 0;
}