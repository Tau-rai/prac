#include "main.h"

/**
 * command_parser - parse through the tokens to find a command
 * @command: pointer to a command
 * @args: pointer to an array of strings
 * @counter: counts the args
 * Return: Nothing.
 */
int command_parser(char *command, char **args, int *counter)
{
	char *token;

	if (command == NULL || args == NULL || counter == NULL)
				return (-1);

	token = _strtok(command, " \n");
	*counter = 0;

	while (token != NULL)
	{
		if (*counter >=  127)
			return (-1);

		args[(*counter)++] = token;
		token = _strtok(NULL, " \n");
	}
	args[*counter] = NULL;

	return (0);
}
