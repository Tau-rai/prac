#include "main.h"

/**
 * _strchr - locates a character in a string
 * @str: pointer to a string
 * @c: character to be located
 * Return: a pointer to the first occurance of the char
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != c)
	{
		str++;
	}
	if (*str == c)
	{
		return ((char *)str);
	}
	else
	{
		return (NULL);
	}
}
/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to the new string
*/
char *_strcat(char *dest, const char *src)
{
    char *ptr = dest + _strlen(dest);
    
	while (*src != '\0')
	{
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return (dest);
}