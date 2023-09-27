#include <stdio.h>
#include <math.h>

/*this function adds two integers and returns the result*/
int integer_add(int x, int y)
{
	int result;
	
	result = x + y;
	return (result);
}
int main(void)
{
	int sum;

	sum = integer_add(37,17);
	printf("The addition of 37 and 17 is : %d\n", sum);

	return (0);
}
