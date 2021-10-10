#include <stdio.h>
#include <string.h>

int main()
{
	char* p1 = "qwert";
	char* p2 = "asdfg";
	printf("%d\n", strcmp(p1, p2));
	printf("%d\n", strcmp(p1, p1));
	printf("%d\n", strcmp(p2, p1));

	return 0;
}
