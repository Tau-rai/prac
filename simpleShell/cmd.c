#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFF_SIZE 1024

int main(void)
{
	pid_t pid;    
	char *command;
	int i = 0, status;
	size_t command_size = BUFF_SIZE;
	char *token;
	char *args[BUFF_SIZE];

	//command = (char *) malloc(command_size * sizeof(char));

	while (1)
	{
		printf("$ ");
		getline(&command, &command_size, stdin);

		token = strtok(command, " \n");

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		pid = fork();
		if (pid == 0)
		{
			execve(args[0], args, NULL);
			printf("Error: Failed to execute command.\n");
			exit(1);
		}
		else if (pid > 0)
		{
			wait(&status);
		}
		else
		{
			printf("Error: Failed to fork.\n");
}
	free(args);
	free(command);
	return 0;
}
