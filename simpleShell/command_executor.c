#include "main.h"

/**
 * command_executor - executes the commands
 * @args: an array of strings
 * Return: Nothing
*/
void command_executor(char **args)
{
    _setenv("PATH", "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin", 1);
    
    if (execve(args[0], args, NULL) == - 1)
    {
        perror("Error: Failed to execute");
        exit(1);
    }
}