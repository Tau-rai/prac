#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int i;
    pid_t pid;
    char *args[] = {"ls", "-l", "/tmp", NULL};
    for (i = 0; i < 2; i++) {
        pid = fork();
        if (pid == 0) {
            execve("/bin/ls", args, NULL);
            exit(0);
        } else if (pid > 0) {
            printf("Child %d PID: %d\n", i + 1, pid);
            wait(NULL);
        } else {
            printf("Error: Failed to fork.\n");
            exit(1);
        }
    }
    printf("Total number of arguments: %d\n", argc);
    return 0;
}
