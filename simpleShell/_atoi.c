#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @str: pointer to a string
 * Return: an integer
 */
int _atoi(const char *str)
{
	int sign = 1;
    int num = 0;

    while (isspace(*str))
        str++;
    
    if (*str == '-')
	{
        sign = -1;
        str++;
    }
	else if (*str == '+')
	    str++;
    
    while (isdigit(*str))
	{
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (*str - '0') > INT_MAX % 10))
		{
            /* Handle overflow */
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        num = num * 10 + (*str - '0');
        str++;
    }
    return (sign * num);
}

