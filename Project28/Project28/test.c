#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#define ElemType int

//������ṹ��
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

//��������
LNode* create(ElemType data[], int n)
{
	LNode* head = NULL;
	LNode* p = NULL;
	LNode* rear = NULL;
	head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	rear = head;

	for (int i = 0; i < n; i++)
	{
		p = (LNode*)malloc(sizeof(LNode));
		p->data = data[i];
		p->next = NULL;
		rear->next = p;
		rear = p;
	}
	return head;
}

//�������������Ԫ��
void display(LNode* head)
{
	LNode* p = NULL;
	p = head->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//����������Ͻ���
LNode* inter(LNode* head1, LNode* head2)
{
	LNode* p = head1->next;
	LNode* q = head2->next;
	LNode* s = NULL;
	LNode* head = NULL;
	head = (LNode*)malloc(sizeof(LNode));
	while (p)
	{
		while (q)
		{
			if (p->data == q->data)
			{
				s = (LNode*)malloc(sizeof(LNode));
				s->data = p->data;
				s->next = head->next;
				head->next = s;
				break;
			}
			else
				q = q->next;
		}
		p = p->next;
		q = head2->next;
	}
	return head;
}

int main()
{
	int data1[10] = { 0 };
	int data2[10] = { 0 };
	int num1, num2, i;
	LNode* h1 = NULL;
	LNode* h2 = NULL;
	LNode* h3 = NULL;
	printf("�����뼯��A�е�Ԫ������");
	scanf("%d", &num1);
	printf("�����뼯��A�е�����Ԫ�أ�");
	for (i = 0; i < num1; i++)
		scanf("%d", &data1[i]);

	printf("�����뼯��B�е�Ԫ������");
	scanf("%d", &num2);
	printf("�����뼯��B�е�����Ԫ�أ�");
	for (i = 0; i < num2; i++)
		scanf("%d", &data2[i]);

	h1 = create(data1, num1);
	h2 = create(data2, num2);
	printf("����������������\n");
	printf("����1��");
	display(h1);
	printf("����2��");
	display(h2);
	h3 = inter(h1, h2);
	printf("�������ϵĽ����ǣ�");
	display(h3);

	return 0;
}