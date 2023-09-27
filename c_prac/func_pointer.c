#include <stdio.h>

void fun(int a)
{
	printf("The value of a is %d\n", a);
}
int main()
{
	// fun_ptr is a pointer to function fun
	void (*fun_ptr)(int) = &fun;

	/* The above line is equivalent of the following two
	 * void (*fun_ptr)(int);
	 * fun_ptr = &fun;
	 */

	// Invoking fun() using fun_ptr
	(*fun_ptr)(10);

	return (0);
}
