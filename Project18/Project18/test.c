#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

int Mul(int a, int b)
{
	return a * b;
}

int Div(int a, int b)
{
	return a / b;
}

void menu()
{
	printf("**************************\n");
	printf("**   1.Add    2.Sub     **\n");
	printf("**   3.Mul    4.Div     **\n");
	printf("*****   0.退出  **********\n");
	printf("**************************\n");
}

int main()
{
	int a = 0, b = 0;
	int (*pr[])(int, int) = { 0, Add, Sub, Mul, Div };
	int input = 0;
	do
	{
		menu();
		printf("请选择: ");
		scanf("%d", &input);

		if (input >= 1 && input <= 4)
		{
			printf("请输入两个操作数：\n");
			scanf("%d%d", &a, &b);
			printf("%d\n", pr[input](a, b));
		}

		else if (input == 0)
		{
			printf("退出！\n");
		}

		else
		{
			printf("选择错误！\n");
		}

	} while (input);

	return 0;
}