#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void print1(int arr[3][5], int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void print2(int (*p)[5], int x, int y)
{
	for (int i = 0; i < x; i++)	
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	print1(arr, 3, 5);
	print2(arr, 3, 5);

	return 0;
}