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

//���������ջ
typedef struct
{
	char elem[MAXSIZE];
	int top;
}SeqStackR;

//���������ջ
typedef struct
{
	int elem[MAXSIZE];
	int top;
}SeqStackD;

//��ʼ�������ջ
void InitStackR(SeqStackR* S)
{
	S->top = 0;
}

//��ʼ��������ջ
void InitStackD(SeqStackD* S)
{
	S->top = 0;
}

//�������ջ
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

//��������ջ
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

//�������ջ
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

//��������ջ
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

//�����ջȡջ��Ԫ��
char GetTopR(SeqStackR* S)
{
	if (S->top == 0)
		printf("The operator stack is null!\n");
	else
		return (S->elem[S->top - 1]);
}

//������ȡջ��Ԫ��
int GetTopD(SeqStackD* S)
{
	if (S->top == 0)
		printf("The operand stack is null!\n");
	else
		return (S->elem[S->top - 1]);
}

//�����ַ��Ƿ�������������ϣ�����ǣ��������������е�λ�ã����򷵻�-1
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

//�Ƚ���������������ȼ�
char Compare(char ch1, char ch2)
{
	int m, n;
	m = Isoperator(ch1);
	n = Isoperator(ch2);
	return cmp[m][n];
}

//������������������Ľ��
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

//�����������ʽ����ֵ
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