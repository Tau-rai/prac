#include <stdio.h>

int main(void)
{
	int i;

	printf("Hex(upper)	Hex(lower)	Decimal\n");
	for (i = 0; i < 16; i++)
	{
		printf("%X	%x	%d\n", i, i , i);
	}
	return (0);
}

