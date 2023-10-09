#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>

#define BUFF_SIZE 514

extern char **environ;

int _strcmp(const char *str1, const char *str2);
size_t _strlen(const char *str);
char *_getenv(const char *name);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *src);
char *_getenv(const char *name);
char *_strchr(const char *str, int c);
char *_strcat(char *dest, const char *src);
void handle_env(void);
void *_memcpy(void *dest, const void *src, size_t n);
void fork_execute(char *command);
int _setenv(const char *name, const char *value, int overwrite);
void command_parser(char *command, char **args, int *counter);
void command_executor(char **args, const char *path);



#endif /* MAIN_H */
