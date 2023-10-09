#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *path = getenv("PATH");
    char *dir = strtok(path, ":");
    while (dir != NULL) {
        printf("%s\n", dir);
        dir = strtok(NULL, ":");
    }
    return 0;
}

