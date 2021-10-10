#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>

//Լɪ������
//����һ����n������ѭ������ÿ�����������һ�����������
//��ָ��pָ���һ���������˵�λ�ã����Ϊk����������ģ���
//1��m�ı�����Ȼ��ɾ������Ϊm�Ľ�㣬ֱ�������н�ʣ��һ��
//���ʱ������������������ɾ�����ı��ֵ��

//��������������
typedef struct Node
{
	int data;							//������
	struct Node* next;					//ָ����
}Node;

//Լɪ������
void Josephu(int n, int k, int m)
{
	Node* head, * p, * q;
	int i;
	head = NULL;							//��ʼ��ͷָ��Ϊ��
	p = NULL;							//��ʼ��ָ��Ϊ��
	q = NULL;							//��ʼ��ָ��Ϊ��
	
	for ( i = 1; i <= n; i++)			//����ѭ������,i��Ϊ��Ŵ�1��ʼ
	{
		p = (Node*)malloc(sizeof(Node));//�����½��
		p->data = i;						//�½���������Ϊ���

		if (head == NULL)
			head = p;
		else
			q->next = p;					//���½���������
		q = p;							//q����һλ,��qʼ�����������һλ
	}

	p->next = head;						//����ѭ������
	p = head;
	for ( i = 1; i < k; i++)				//ָ��pָ����Ϊk�Ľ��
	{									//ֻ��Ҫ���ƫ��k-1��
		q = p;
		p = p->next;						//pʼ����q��һλ
	}

	printf("���е�˳������Ϊ��");
	while (p != q)						//p = qʱ˵��ֻʣ���һ��Ԫ����
	{
		for ( i = 1; i < m; i++)			//ʹpָ���m�����
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;				//�����pɾ��
		printf("%4d", p->data);
		free(p);
		p = q->next;						//pָ���µĳ������
	}
	printf("%4d\n", p->data);			//��ӡ���һ��Ԫ��
}

int main()								//�̲����õ�void main����������
{
	int n, k, m;
	printf("����n��ֵ��");
	scanf("%d", &n);
	printf("����k��ֵ��");
	scanf("%d", &k);
	printf("����m��ֵ��");
	scanf("%d", &m);
	Josephu(n, k, m);

	return 0;
}