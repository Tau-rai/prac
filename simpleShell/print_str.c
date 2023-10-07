#include "main.h"

void print_str(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	write(STDOUT_FILENO, str, len);
}
