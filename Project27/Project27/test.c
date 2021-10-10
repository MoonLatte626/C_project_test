#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>

//约瑟夫环问题
//建立一个有n个结点的循环链表，每个人用链表的一个结点描述。
//用指针p指向第一个报数的人的位置（编号为k），用链表模拟从
//1到m的报数，然后删除报数为m的结点，直至链表中仅剩下一个
//结点时结束，最后依次输出被删除结点的编号值。

//定义链表结点类型
typedef struct Node
{
	int data;							//数据域
	struct Node* next;					//指针域
}Node;

//约瑟夫环问题
void Josephu(int n, int k, int m)
{
	Node* head, * p, * q;
	int i;
	head = NULL;							//初始化头指针为空
	p = NULL;							//初始化指针为空
	q = NULL;							//初始化指针为空
	
	for ( i = 1; i <= n; i++)			//创建循环链表,i作为编号从1开始
	{
		p = (Node*)malloc(sizeof(Node));//生成新结点
		p->data = i;						//新结点的数据域为编号

		if (head == NULL)
			head = p;
		else
			q->next = p;					//将新结点插入链表
		q = p;							//q后移一位,即q始终是链表最后一位
	}

	p->next = head;						//构成循环链表
	p = head;
	for ( i = 1; i < k; i++)				//指针p指向编号为k的结点
	{									//只需要向后偏移k-1次
		q = p;
		p = p->next;						//p始终在q后一位
	}

	printf("出列的顺序依次为：");
	while (p != q)						//p = q时说明只剩最后一个元素了
	{
		for ( i = 1; i < m; i++)			//使p指向第m个结点
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;				//将结点p删除
		printf("%4d", p->data);
		free(p);
		p = q->next;						//p指向新的出发结点
	}
	printf("%4d\n", p->data);			//打印最后一个元素
}

int main()								//教材中用的void main（）不建议
{
	int n, k, m;
	printf("输入n的值：");
	scanf("%d", &n);
	printf("输入k的值：");
	scanf("%d", &k);
	printf("输入m的值：");
	scanf("%d", &m);
	Josephu(n, k, m);

	return 0;
}