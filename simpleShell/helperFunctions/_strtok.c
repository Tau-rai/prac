#include "main.h"

/**
 * _strtok - tokenizes a string
 * @s: pointer to a string
 * @delim: the delimiter
 * Return: tokenized strings
*/

char *_strtok(char *s, const char *delim)
{
  static char *ptr = NULL;
  
  if (!s)
    s = ptr;
  
  while (*s && _strchr(delim, *s))
    s++;
  
  if (!*s)
    return (NULL);
  
  ptr = s;
  while (*s && !_strchr(delim, *s))
    s++;
  
  if (*s)
  {
    *s = '\0';
    s++;
  }
  return (ptr);
}
