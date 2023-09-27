#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...)
{
	va_list ap;
	int chars_printed = 0;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(ap, int);
				putchar(c);
				chars_printed++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(ap, char *);

				while (*s != '\0')
				{
					putchar(*s);
					s++;
					chars_printed++;
				}
			}
			else if (*format == '%')
				putchar('%');
			        chars_printed++;
		} 
		else
		{
			putchar(*format);
			chars_printed++;
		}
		format++;
	}
	va_end(ap);
	return (chars_printed);
}
