#include "main.h"
#include <assert.h>

int main() {
    // Test adding a new environment variable
    assert(_setenv("TEST_VAR", "test_value", 1) == 0);
    assert(strcmp(getenv("TEST_VAR"), "test_value") == 0);

    // Test modifying an existing environment variable
    assert(_setenv("TEST_VAR", "new_value", 1) == 0);
    assert(strcmp(getenv("TEST_VAR"), "new_value") == 0);

    // Test not overwriting an existing environment variable
    assert(_setenv("TEST_VAR", "should_not_change", 0) == 0);
    assert(strcmp(getenv("TEST_VAR"), "new_value") == 0);

    // Test invalid arguments
    assert(_setenv("", "value", 1) == -1);
    assert(_setenv("name=", "value", 1) == -1);
    assert(_setenv(NULL, "value", 1) == -1);

    // Test freeing memory
    char *old_env = getenv("TEST_VAR");
    assert(old_env != NULL);
    free(old_env);

    return 0;
}

