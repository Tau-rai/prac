#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name) {
	char **env = environ;
	
	while (*env)
	{
		char *env_var = *env;
		const char *env_name = name;
		while (*env_var == *env_name && *env_var != '=' && *env_name != '\0')
		{
			env_var++;
			env_name++;
		}
		if (*env_var == '=' && *env_name == '\0')
		{
			return (env_var + 1);
		}
		env++;
	}
	return NULL;
}

