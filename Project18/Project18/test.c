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
	printf("*****   0.�˳�  **********\n");
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
		printf("��ѡ��: ");
		scanf("%d", &input);

		if (input >= 1 && input <= 4)
		{
			printf("������������������\n");
			scanf("%d%d", &a, &b);
			printf("%d\n", pr[input](a, b));
		}

		else if (input == 0)
		{
			printf("�˳���\n");
		}

		else
		{
			printf("ѡ�����\n");
		}

	} while (input);

	return 0;
}