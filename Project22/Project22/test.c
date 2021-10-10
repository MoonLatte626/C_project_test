#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>

char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* p = dest;

	while (*dest++ = *src++)
	{
	}
	return p;
}

int main()
{
	char arr1[] = "qwert";
	char arr2[40];
	my_strcpy(arr2, arr1);
	printf("%s\n%s\n", arr1, arr2);
	printf("%p\n%p\n", arr1, arr2);

	return 0;
}