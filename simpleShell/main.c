#include <stdio.h>

char *_getenv(const char *name);

int main(void)
{
	char *path = _getenv("PATH");

	if (path)
	{
		printf("PATH envron variable : %s\n", path);
	}
	else
	{
		printf("Path env variable not found.\n");
	}
	return (0);
}
