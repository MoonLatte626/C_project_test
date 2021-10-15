#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXSIZE 100

char op[7] = { '+', '-', '*', '/', '(', ')', '#' };
char cmp[7][7] = {
	{ '>', '>', '<', '<', '<', '>', '>' },
	{ '>', '>', '<', '<', '<', '>', '>' },
	{ '>', '>', '>', '>', '<', '>', '>' },
	{ '>', '>', '>', '>', '<', '>', '>' },
	{ '<', '<', '<', '<', '<', '=', ' ' },
	{ '>', '>', '>', '>', ' ', '>', '>' },
	{ '<', '<', '<', '<', '<', ' ', '=' }
};

//定义运算符栈
typedef struct
{
	char elem[MAXSIZE];
	int top;
}SeqStackR;

//定义操作数栈
typedef struct
{
	int elem[MAXSIZE];
	int top;
}SeqStackD;

//初始化运算符栈
void InitStackR(SeqStackR* S)
{
	S->top = 0;
}

//初始化操作数栈
void InitStackD(SeqStackD* S)
{
	S->top = 0;
}

//运算符进栈
void PushR(SeqStackR* S, char e)
{
	if (S->top == MAXSIZE)
		printf("The operator stack is full!\n");
	else
	{
		S->elem[S->top] = e;
		S->top++;
	}
}

//操作数进栈
void PushD(SeqStackD* S, int e)
{
	if (S->top == MAXSIZE)
		printf("The operand stack is full!\n");
	else
	{
		S->elem[S->top] = e;
		S->top++;
	}
}

//运算符出栈
void PopR(SeqStackR* S, char* e)
{
	if (S->top == 0)
		printf("The operator stack is null!\n");
	else
	{
		S->top--;
		*e = S->elem[S->top];
	}
}

//操作数出栈
void PopD(SeqStackD* S, int* e)
{
	if (S->top == 0)
		printf("The operand stack is null!\n");
	else
	{
		S->top--;
		*e = S->elem[S->top];
	}
}

//运算符栈取栈顶元素
char GetTopR(SeqStackR* S)
{
	if (S->top == 0)
		printf("The operator stack is null!\n");
	else
		return (S->elem[S->top - 1]);
}

//操作数取栈顶元素
int GetTopD(SeqStackD* S)
{
	if (S->top == 0)
		printf("The operand stack is null!\n");
	else
		return (S->elem[S->top - 1]);
}

//输入字符是否属于运算符集合，如果是，返回它在数组中的位置；否则返回-1
int Isoperator(char ch)
{
	int i;
	for (i = 0; i < 7; i++)
	{
		if (ch == op[i])
			return i;
	}
	return -1;
}

//比较两个运算符的优先级
char Compare(char ch1, char ch2)
{
	int m, n;
	m = Isoperator(ch1);
	n = Isoperator(ch2);
	return cmp[m][n];
}

//返回两个操作数运算的结果
int Execute(int a, char theta, int b)
{
	int result = 0;
	switch (theta)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	default:
		break;
	}
	return result;
}

//输入算数表达式并求值
int EvaluateExp()
{
	char ch, theta;
	int a = 0, b = 0, k = 0, x = 0;
	char str[50] = { 0 };
	SeqStackR OPTR;
	SeqStackD OPND;
	InitStackR(&OPTR);
	InitStackD(&OPND);

	printf("Please input expreeion:\n");
	PushR(&OPTR, '#');
	gets(str);
	ch = str[k];
	k++;

	while (ch != '#' || GetTopR(&OPTR) != '#')
	{
		if (Isoperator(ch) == -1)
		{
			x = ch - '0';
			ch = str[k];
			k++;
			while (Isoperator(ch) == -1)
			{
				x = x * 10 + ch - '0';
				ch = str[k];
				k++;
			}
			PushD(&OPND, x);
		}
		else
		{
			switch (Compare(GetTopR(&OPTR), ch))
			{
			case '<':
				PushR(&OPTR, ch);
				ch = str[k];
				k++;
				break;
			case '=':
				PopR(&OPTR, &ch);
				ch = str[k];
				k++;
				break;
			case '>':
				PopR(&OPTR, &theta);
				PopD(&OPND, &b);
				PopD(&OPND, &a);
				PushD(&OPND, Execute(a, theta, b));
				break;
			}
		}
	}
	return GetTopD(&OPND);
}

int main()
{
	printf("The value of expression is:%d\n", EvaluateExp());

	return 0;
}