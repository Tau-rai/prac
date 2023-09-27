#include <stdio.h>

int main(void)
{
	int num1;
	float num2;

	num1 = 123;
	num2 = 123.456789;
	printf("Align number to the left : -%08d\n", num1);
	printf("Align number to the right : %8.3f\n", num2);
	printf("The integer %d is the same as the hex %x\n", 21, 21);
	printf("the value of %c is :\n ", 'c');
	return (0);
}

