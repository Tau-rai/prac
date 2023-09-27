#include <unistd.h>

/**
 * myprint - prints out a string to  the std out
 * @string - pointer to a string
 * Return: Nthing
 */
void myprint(char *string)
{
	int len = strlen(string);

	write(1, string, len);
}

void myprintInt(int num)
{
	char buffer[50];
	sprintf(buffer, "%d", num);
	myprint(buffer);
}

void mypfintFloat(float num)
{
	char buffer [50];
	sprintf(buffer, "%f", num);
	myprint(buffer);
}

void myPrintf(char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'd':
                    myPrintInt(va_arg(args, int));
                    break;
                case 'f':
                    myPrintFloat(va_arg(args, double));
                    break;
                case 's':
                    myPrint(va_arg(args, char *));
                    break;
                default:
                    break;
            }
        } else {
            char c = *format;
            write(1, &c, 1);
        }
        format++;
    }

    va_end(args);
}
