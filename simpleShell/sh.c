#include "main.h"

/**
 * main - entry point
 * Return: Always 0 Success.
 */
int main(void)
{
	char *command;
	size_t command_size = BUFF_SIZE;
	char cmd[] = "$ ";
	ssize_t r_size;

	command = (char *)malloc(command_size * sizeof(char));

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			/* only print prompt if input comes from terminal*/
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

			handle_env(); /* handle env command */
		}
		else
			fork_execute(command);

	}
	free(command);

	return (0);
}
