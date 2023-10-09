#include "main.h"

/**
 * fork_execute - forks and executes commands from terminal
 * @command: exxcutables from the terminal
 * Return:nothing
 */
void fork_execute(char *command)
{
	pid_t pid;
	char *path;
	char *args[128];
	int counter, status;

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
