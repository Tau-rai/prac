#include "main.h"

/**
 * main - entry point
 * @argv: array of strings
 * @argc: number of arguments
 * Return: Always 0 Success.
 */
int main(__attribute__((unused))int argc, char *argv[])
{
	char *command = NULL;
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

		r_size = (ssize_t)_getline(&command, &command_size, stdin);

		if (r_size <= 0)
		{
			break; /* handle end of file*/
		}

		command[_strlen(command) - 1] = '\0';

		
        handle_command(command, argv);
        
		free(command);

		command = NULL;
		command_size = 0;
	}
	free(command);

	return (0);
}
