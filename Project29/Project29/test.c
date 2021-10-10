#define _CRT_SECURE_NO_WARNINGS 1
//һԪ����ʽ������
#include <stdio.h>
#include <malloc.h>

//����������
typedef struct Node
{
	float coef;
	int exp;
	struct Node* next;
}Node;

//��������
Node* create(int n)
{
	Node* head, * s, * rear;
	int i;
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	rear = head;
	for (i = 1; i <= n; i++)
	{
		s = (Node*)malloc(sizeof(Node));
		printf("�������%d���ϵ����ָ����", i);
		scanf("%f %d", &s->coef, &s->exp);
		rear->next = s;
		rear = s;
	}
	rear->next = NULL;
	return head;
}

//��������е�����Ԫ��
void display(Node* head)
{
	Node* p = NULL;
	p = head->next;
	while (p)
	{
		printf("(%f,%d) ", p->coef, p->exp);
		p = p->next;
	}
	printf("\n");
}

//��������ʽ��ӣ����ض���ʽ�����ͷָ��
Node* addPolyn(Node* head1, Node* head2)
{
	Node* p, * q, * head, * rear, * s;
	int temp;
	float sum;
	p = head1->next;
	q = head2->next;
	head = (Node*)malloc(sizeof(Node));
	rear = head;

	while (p && q)
	{
		if (p->exp == q->exp)
			temp = 0;
		else if (p->exp < q->exp)
			temp = 1;
		else
			temp = -1;

		switch (temp)
		{
		case 0:
			sum = p->coef + q->coef;
			if (sum != 0.0)
			{
				s = (Node*)malloc(sizeof(Node));
				s->coef = sum;
				s->exp = p->exp;
				rear->next = s;
				rear = s;
			}
			p = p->next;
			q = q->next;
			break;
		case 1:
			s = (Node*)malloc(sizeof(Node));
			s->coef = p->coef;
			s->exp = p->exp;
			rear->next = s;
			rear = s;
			p = p->next;
			break;
		case -1:
			s = (Node*)malloc(sizeof(Node));
			s->coef = q->coef;
			s->exp = q->exp;
			rear->next = s;
			rear = s;
			q = q->next;
			break;
		}
	}
	while (p)
	{
		s = (Node*)malloc(sizeof(Node));
		s->coef = p->coef;
		s->exp = p->exp;
		rear->next = s;
		rear = s;
		p = p->next;
	}
	while (q)
	{
		s = (Node*)malloc(sizeof(Node));
		s->coef = q->coef;
		s->exp = q->exp;
		rear->next = s;
		rear = s;
		q = q->next;
	}
	rear->next = NULL;
	return head;
}

int main()
{
	Node* h1, * h2, * h;
	int m;
	printf("�������һ������ʽ��������");
	scanf("%d", &m);
	h1 = create(m);
	display(h1);
	printf("������ڶ�������ʽ��������");
	scanf("%d", &m);
	h2 = create(m);
	display(h2);
	printf("����Ͷ���ʽ��ϵ����ָ����");
	h = addPolyn(h1, h2);
	display(h);

	return 0;
}