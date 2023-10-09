#include "main.h"

int main(void);
/**
 * main - entry point
 * Return: Always 0 Success.
 */
int main(void)
{
	pid_t pid;
	char *command, *path, **env;
	size_t command_size = BUFF_SIZE;
	char *args[128];
	int counter, status;
	char cmd[] = "$ ";
	ssize_t r_size;

	command = (char *)malloc(command_size * sizeof(char));

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			/* only print $ prompt if input comes from terminal*/
			write(STDOUT_FILENO, &cmd, 2);
		}

		r_size =  getline(&command, &command_size, stdin);

		if (r_size <= 0)
		{
			break; /* handle end of file*/
		}

		command[_strlen(command) - 1] = '\0';

		if (_strcmp(command, "exit") == 0)
		{
			break; /*handle exit */
		}
		else if (_strcmp(command, "env") == 0)
		{
			/* handle env command */
			*env = environ;

			while (*env)
			{
				write(STDOUT_FILENO, *env, _strlen(*env));
				write(STDOUT_FILENO, "\n", 1);
				env++;
			}
		}
		else
		{
			pid = fork();
			if (pid == -1)
			{
				perror("Error: Failed to fork");
				exit(1);
			}
			else if (pid == 0)
			{
				path = _getenv("PATH");
				command_parser(command, args, &counter);
				command_executor(args, path);
			}
			else
			{
				if (waitpid(pid, &status, 0) == -1)
				{
					perror("waitpid");
					exit(1);
				}
			}
		}
	}

	free(command);

	return (0);
}
