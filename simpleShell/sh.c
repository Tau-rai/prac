#include "main.h"

/**
 * main - entry point
 * 
 * Return: Always 0 Success.
*/
int main(void)
{
	pid_t pid; 
	char *command;
	size_t command_size = BUFF_SIZE;
	char *args[128]; 
	int counter, status;
	char cmd[] = "$ ";
	ssize_t read_size;
	// char *envp[];

	command = (char *)malloc(command_size * sizeof(char));

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			/* only print $ prompt if input comes from terminal*/
			write(STDOUT_FILENO, &cmd, 2);
		}
				
		read_size =  getline(&command, &command_size, stdin);

		if (read_size <= 0)
		{
			break; /* handle end of file*/
		}

		command[_strlen(command) - 1] = '\0';

		if(_strcmp(command, "exit") == 0) 
		{
			break; /*handle exit */
		}

		pid = fork();
		if (pid == -1)
		{
			perror("Error: Failed to fork");
			exit(1);
		}
		else if (pid == 0)
		{
			command_parser(command, args, &counter);
			command_executor(args);
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

	free(command);

	return (0);
}
