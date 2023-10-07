#include "main.h"

#define BUFF_SIZE 514

int main(void)
{
	pid_t pid; 
	char *command;
	size_t command_size = BUFF_SIZE;
	char *token;
	char *args[128]; 
	int i = 0, status;
	char cmd[] = "$ ";
	ssize_t read_size;

	command = (char *)malloc(command_size * sizeof(char));

	while (1)
	{
		write(STDOUT_FILENO, &cmd, 2);
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
			i = 0;
			
			token = strtok(command, " \n");
			while (token != NULL)
			{
				args[i++] = token;
				token = strtok(NULL, " \n");
			}
			args[i] = NULL;

			/* execute commands */
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Failed to execute");
				exit(1);
			}
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
