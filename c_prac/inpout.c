#include <stdio.h>

int main(void)
{
	int num7;
	char k;

	printf("Enter a number followed by a letter : ");
	num7 = getchar();
	k = getchar();
	putchar(num7);
	putchar(k);
	putchar('\n');
	return (0);
}
