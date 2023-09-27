#include <stdio.h>

int main()
{
	int a, b, sum, sub, div, mul;
	char operator;
	printf("Enter operator : ");
	scanf(" %c", &operator);
	printf("Enter two operands: ");
	scanf("%d %d ", &a, &b);
	switch (operator)
	{
		case '+':
			sum = a + b;
			printf("Sum is : %d\n", sum);
			break;
		case '-':
			sub = a - b;
			printf("Sub is : %d\n", sub);
			break;
		case '*':
			mul = a * b;
			printf("Mul is : %d\n", mul);
			break;
		case '/':
			div = a / b;
			printf("Div is : %d\n", div);
		default:
			printf("Enter a valid operator:\n");
	}
}
