#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv) {
    char *command = NULL;
    char *prompt = "$ ";
    //char *line = NULL;
    size_t c_size = 0;
    char *args[128];
    int status;

    while (1) {
        // Print a prompt and wait for user input
	if (isatty(STDIN_FILENO))
	{
        	write(STDOUT_FILENO, &prompt, 2);
	}
        ssize_t read_size = getline(&command, &c_size, stdin);

        if (read_size == -1) {
            break;
        }

        // Tokenize the command and store the arguments in an array
        char *token = strtok(command, " \n");
        int i = 0;
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " \n");
        }
        args[i] = NULL;

        // Check if the entered command is an executable using stat
        struct stat file_stat;
        if (i > 0 && stat(args[0], &file_stat) == 0 && S_ISREG(file_stat.st_mode) && (file_stat.st_mode & S_IXUSR)) {
            pid_t pid = fork();
            if (pid == -1) {
                perror("Error: Failed to fork");
                free(command);
                exit(1);
            } else if (pid == 0) {
                execve(args[0], args, NULL);
                perror("Failed to execute");
                free(command);
                exit(1);
            } else {
                if (waitpid(pid, &status, 0) == -1) {
                    perror("waitpid");
                    free(command);
                    exit(1);
                }
            }
        } else {
            printf("Error: Not an executable or not found\n");
        }
    }

    // Free the allocated memory
    free(command);

    return 0;
}

