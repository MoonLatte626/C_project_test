#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct Student
{
	int num;
	char name[20];
	float score;
};

int main()//½á¹¹Ìå
{
	struct Student stu[5] =
	{
		{0001, "zhang", 98.0f},
		{0002, "li", 78.7f},
		{0003, "wang", 90.0f},
		{0004, "ling", 80.8f},
		{0005, "yang", 77.5f}
	};
	struct Student temp;
	const int n = 5;
	int i, j, k;
	printf("The order is:\n");
	for ( i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (stu[j].score > stu[k].score)
			{
				k = j;
			}
		}
		temp = stu[k];
		stu[k] = stu[i];
		stu[i] = temp;
	}
	for ( i = 0; i < n; i++)
	{
		printf("%6d%8s%10.2F\n", stu[i].num, stu[i].name, stu[i].score);
	}
	printf("\n");

	return 0;
}