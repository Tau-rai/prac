#include <stdio.h>
#include <unistd.h>

int main(__attribute__((unused))int ac, char **av)
{
	int i = 0;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("av[%d] : %s\n", i, av[i]);

	}
	return (0);
}
