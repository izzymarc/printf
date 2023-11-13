#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Produces output according to a format.
 * @format: Format string containing the characters and the specifiers
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i;
	va_list args;
	int count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += handle_char(args);
					break;
				case 's':
					count += handle_string(args);
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					/* Print unknown format specifier as a literal */
					count += _putchar('%');
					count += _putchar(format[i]);
					break;
			}
		}
		else
			count += _putchar(format[i]);
	}

	va_end(args);
	return (count);
}

/**
 * handle_char - Handles character format specifier
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int handle_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * handle_string - Handles string format specifier
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int handle_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0, j;

	if (str == NULL)
		str = "(null)";
	for (j = 0; str[j]; j++)
	{
		count += _putchar(str[j]);
	}
	return (count);
}
