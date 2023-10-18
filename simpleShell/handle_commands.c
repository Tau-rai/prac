#include "main.h"

void update_pwd(void);
char *get_homeDir(void);
/**
 * handle_command - handles buil in commands
 * @command: pointer to a command
 * @argv: an array of strings
 * Return: Nothing.
*/
void handle_command(char *command, char  *argv[])
{
    char *stat_arg;
    char *args[2];
    char *dir, *home_dir, *last_dir;

    if (_strcmp(command, "exit") == 0)
    {
        handle_exit(NULL); /*handle exit */
        free(command);
    }
    else if (_strncmp(command, "exit ", 5) == 0)
    {
        stat_arg = command + 5;
        handle_exit(stat_arg);
        free(command);
    }
    else if (_strcmp(command, "env") == 0)
    {
        handle_env(); /* handle env command */
    }
    else if (_strncmp(command, "setenv", 7) == 0)
    {
        handle_setenv(command);
        free(command);
    }
    else if (_strncmp(command, "unsetenv", 9) == 0)
    {
        handle_unsetenv(command);
        // free(command);
    }
    else if (_strcmp(command, "cd") == 0)
    {
            home_dir = get_homeDir();
            if (home_dir != NULL)
            {
                chdir(home_dir);
                update_pwd();
            }
        }
        else if (_strncmp(command, "cd ", 3) == 0)
        {
            dir = command + 3;
            if (_strcmp(dir, "-") == 0)
            {
                last_dir = _getenv("OLDPWD");
                if (last_dir != NULL) {
                    chdir(last_dir);
                }
            } else {
                chdir(dir);
            }
            update_pwd();
        }
    else
        fork_execute(command, argv);
    
}
char *get_homeDir()
{
    return _getenv("HOME");
}

void update_pwd()
{
    char cur_dir[BUFF_SIZE];
    getcwd(cur_dir, BUFF_SIZE);
    _setenv("PWD", cur_dir, 1);
}