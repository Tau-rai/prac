#include <stdio.h>
#include <stdarg.h>

/**
 * printargs - prints all args one at a time until a -ve arg is met; all args are assumed to be of tpye int
 * @arg1: first arguments
 * Return: Nothing
 */
void printargs(int arg1, ...)
{
	va_list ap;
	int i;

	va_start(ap, arg1);
	for (i = arg1; i >= 0; i = va_arg(ap, int))
		printf("%d ", i);
	va_end(ap);
	putchar('\n');
}

int main(void)
{
	printargs(5, 3, 15, 84, 97, 10, -1, 28, -1);
	printargs(84, 87, -1, 3);
	printargs(-1);
	printargs(6, 'h', "t", -4);
	printargs(1, -3);
	return (0);
}
