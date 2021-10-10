#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 1000000//定义常量
#define ADD(X,Y) ((X)+(Y))//定义宏
#include <stdio.h>

int main()
{
	printf("%d\n", MAX);
	printf("%d\n", 4 * ADD(2, 3));
	return 0;
}