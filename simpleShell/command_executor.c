#include "main.h"

/**
 * command_executor - executes the commands
 * @args: an array of strings
 * @path: value of the PATH environ variable
 * Return: Nothing
 */
void command_executor(char **args, const char *path)
{
	char *token;
	char *full_path = NULL;
	size_t len;

	token = strtok(_strdup(path), ":");

	while (token != NULL)
	{
		len = _strlen(token) + _strlen(args[0]) + 2;
		full_path = (char *)malloc(len);

		if (full_path == NULL)
		{
			perror("Error: Failed to allocate memory");
			exit(1);
		}
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, args[0]);

		/* check if executable exists in the directory*/
		if (access(full_path, X_OK) == 0)
		{
			/* execute command */
			if (execve(full_path, args, NULL) == -1)
			{
				perror("Error: Failed to execute");
				exit(1);
			}
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	write(STDERR_FILENO, args[0], _strlen(args[0]));
	write(STDERR_FILENO, ": not found\n", 12);
	exit(1);
}
