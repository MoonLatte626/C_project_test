#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//ָ��
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

	printf("%d\n", sizeof(int*));//4  ��Ϊ��32λƽ̨��X86��
	printf("%d\n", sizeof(char*));//4 
	printf("%d\n", sizeof(long*));//4

	return 0;
}