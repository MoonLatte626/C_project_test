#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//指针
int main()
{
	int a = 0;
	printf("%p\n", &a);

	int* pa = &a;
	printf("%p\n", pa);

	char b = 'c';
	char* pc = &b;
	printf("%p\n", pc);

	*pa = 10;
	printf("%d\n", a);

	printf("%d\n", sizeof(int*));//4  因为是32位平台（X86）
	printf("%d\n", sizeof(char*));//4 
	printf("%d\n", sizeof(long*));//4

	return 0;
}