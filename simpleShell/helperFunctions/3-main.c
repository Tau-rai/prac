#include "main.h"

int main(void) {
    const char *name = "MY_ENV_VAR";
    const char *value = "12345";

    // Test setting the environment variable
    printf("Setting environment variable: %s=%s\n", name, value);
    if (_setenv(name, value, 1) == 0) {
        printf("Environment variable set successfully.\n");
    } else {
        perror("Failed to set environment variable");
        return 1;
    }

    // Test getting the environment variable
    const char *env_var = getenv(name);
    if (env_var) {
        printf("Environment variable %s=%s\n", name, env_var);
    } else {
        perror("Failed to get environment variable");
        return 1;
    }

    return 0;
}