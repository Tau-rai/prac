#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

int main() {
    char *input;
    size_t input_size = MAX_INPUT_LENGTH;
    input = (char *) malloc(input_size * sizeof(char));
    while (1) {
        printf("$ ");
        getline(&input, &input_size, stdin);
        int argc = 0;
        char **argv = malloc(input_size * sizeof(char *));
        char *token = strtok(input, " \n");
        while (token != NULL) {
            argv[argc++] = token;
            printf("%s\n", token);
            token = strtok(NULL, " \n");
        }
        write(1, "Total number of arguments:\n",28);
        free(argv);
    }
    free(input);
    return 0;
}
