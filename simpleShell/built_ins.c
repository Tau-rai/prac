#include "main.h"

/**
 * handle_env - handles the environ variable
 * Return: Nothing
 */
void handle_env(void)
{
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
/**
 * handle_exit - handles the built-in exit shell command
 * @status: pointer to a string
 * Return: an integer value
*/
void handle_exit(char *status)
{
    int exit_status = 0;

    if (status != NULL)
        exit_status = _atoi(status);
    
    exit(exit_status);
}
/**
 * handle_setenv - handles the built-in setenv function
 * @command: pointer to a command
 * Return: Nothing
*/
void handle_setenv(char *command)
{
    char *env_cmd = command + 7; /*Skip setenv*/
    char *var = _strtok(env_cmd, " ");
    char *value = _strtok(NULL, " ");

    if (var != NULL && value != NULL)
    {
        if (setenv(var, value, 1) == -1)
        {
            perror("Error: Failed to set env var");
        }
    }
    else
        perror("Error: Invalid syntax for setenv");
    
}
/**
 * handle_unsetenv - handles the built-in unsetenv function
 * @command: pointer to a command
 * Return: Nothing
*/
void handle_unsetenv(char *command)
{
    char *var = command + 9;
    
    if (unsetenv(var) == -1)
        perror("Error: Failed to unset env var");
    
}
