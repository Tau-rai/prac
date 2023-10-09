#include "main.h"

/**
 * _setenv - sets the environment of a var name to a specified value
 * @name: variable name of the environ
 * @value: value of the name
 * @overwrite: an integer value
 * Return: Always 0 Success.
*/
int _setenv(const char *name, const char *value, int overwrite)
{
  // size_t env_len;
  // char *new_env;
  char *env = getenv(name); 

  if (env == NULL || overwrite)
  {
    size_t env_len = strlen(name) + strlen(value) + 2; 
    /* Allocate memory for the new environment variable */
    char *new_env = malloc(env_len);

    if (new_env == NULL)
    {
      return (-1);
    }

    /* Copy the name and value into the new environment variable */
    memcpy(new_env, name, strlen(name));
    new_env[strlen(name)] = '=';
    memcpy(new_env + strlen(name) + 1, value, strlen(value));
    new_env[env_len - 1] = '\0'; 

    /* Set the new environment variable using the setenv function */
    if (_setenv(name, new_env, 1) != 0)
    {
      free(new_env);
      return (-1);
    }

    free(new_env); 
  }

  return (0);

}