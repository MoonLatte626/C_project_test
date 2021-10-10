#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int cmb_int(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int cmb_float(const void* a, const void* b)
{
	if (*(float*)a > *(float*)b)
		return 1;
	else if (*(float*)a < *(float*)b)
		return -1;
	else
		return 0;
}

void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	qsort(arr, 10, sizeof(int), cmb_int);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test2()
{
	float arr[] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0 };
	qsort(arr, 9, sizeof(float), cmb_float);
	for (int i = 0; i < 9; i++)
	{
		printf("%f ", arr[i]);
	}
	printf("\n");
}

int main()
{
	test1();
	test2();

	return 0;
}