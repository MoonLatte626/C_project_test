#define _CRT_SECURE_NO_WARNINGS 1
//一元多项式的运算
#include <stdio.h>
#include <malloc.h>

//定义结点类型
typedef struct Node
{
	float coef;
	int exp;
	struct Node* next;
}Node;

//建立链表
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
		printf("请输入第%d项的系数和指数：", i);
		scanf("%f %d", &s->coef, &s->exp);
		rear->next = s;
		rear = s;
	}
	rear->next = NULL;
	return head;
}

//输出链表中的数据元素
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

//两个多项式相加，返回多项式链表的头指针
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
	printf("请输入第一个多项式的项数：");
	scanf("%d", &m);
	h1 = create(m);
	display(h1);
	printf("请输入第二个多项式的项数：");
	scanf("%d", &m);
	h2 = create(m);
	display(h2);
	printf("输出和多项式的系数和指数：");
	h = addPolyn(h1, h2);
	display(h);

	return 0;
}