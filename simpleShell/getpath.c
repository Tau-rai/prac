#include "main.h"

int _setenv(const char *name, const char *value, int overwrite) {
    if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL) {
        return -1;
    }

    size_t len = _strlen(name) + _strlen(value) + 2;
    char *env = malloc(len);
    if (env == NULL) {
        return -1;
    }

    char *p = env;
    while (*name != '\0') {
        *p++ = *name++;
    }
    *p++ = '=';
    while (*value != '\0') {
        *p++ = *value++;
    }
    *p = '\0';

    if (getenv(name) != NULL && !overwrite) {
        free(env);
        return 0;
    }

    extern char **environ;
    size_t env_len = 0;
    while (environ[env_len] != NULL) {
        env_len++;
    }

    char **new_environ = malloc((env_len + 2) * sizeof(char *));
    if (new_environ == NULL) {
        free(env);
        return -1;
    }

    memcpy(new_environ, environ, env_len * sizeof(char *));
    new_environ[env_len] = env;
    new_environ[env_len + 1] = NULL;

    environ = new_environ;

    return 0;
}

