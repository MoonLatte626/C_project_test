#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//�ṹ��
struct stu
{
	char name[20];
	double score;
	int age;
};

int main()
{
	struct stu s = { "����", 99.9, 15 };
	struct stu* ps = &s;
	printf("1:%s,%lf,%d\n", s.name, s.score, s.age);
	printf("2:%s,%lf,%d\n", (*ps).name, (*ps).score, (*ps).age);
	printf("3:%s,%lf,%d\n", ps->name, ps->score, ps->age);

	return 0;
}//��ʶC���Խ���