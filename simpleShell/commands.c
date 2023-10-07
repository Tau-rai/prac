#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

int main() {
	char *input;
	size_t input_size = MAX_INPUT_LENGTH;
	int i, status;
	int argc = 0;
	char **argv;
	char *token;
	input = (char *) malloc(input_size * sizeof(char));

	/* Set the PATH environment variable to include standard paths */
	setenv("PATH", "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin", 1);

	while (1) {
		printf("$ ");
		if (getline(&input, &input_size, stdin) == -1) {
			perror("getline");
			exit(1);
		}


		*argv = malloc(input_size * sizeof(char *));
		token = strtok(input, " \n");

		while (token != NULL) {
			argv[argc++] = token;
			token = strtok(NULL, " \n");
		}

		/* Check if any of the arguments are commands and execute them*/
		for (i = 0; i < argc; i++) {
			if (access(argv[i], X_OK) == 0) {
				if (fork() == 0) {
					/* Child process */
					execve(argv[i], &argv[i], NULL);
					perror("execve");
					exit(1);
				} else {
					/* Parent process */
					wait(&status);
					if (WIFEXITED(status)) {
						printf("Command '%s' exited with status %d\n", argv[i], WEXITSTATUS(status));
					}
				}
			}
		}


		free(argv);
	}

	free(input);
	return 0;
}

