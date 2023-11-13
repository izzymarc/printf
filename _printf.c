#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Writes the character c to stdout
 * @c: The character to print
 * Return: On success 1, On error -1, and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Custom printf function to produce output according to a format
 * @format: Format string containing the characters and the specifiers
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	unsigned int i;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			continue;
		}

		/* Move to the next character for specifier */
		i++;
		switch (format[i])
		{
			case 'c':
				count += _putchar(va_arg(args, int));
				break;
			case 's':
				count += print_string(va_arg(args, char *));
				break;
			case '%':
				count += _putchar('%');
				break;
			default:
				count += _putchar('%');
				count += _putchar(format[i]);
				break;
		}
	}

	va_end(args);
	return (count);
}

/**
 * print_string - Helper function to handle string format specifier
 * @str: String to print
 * Return: Number of characters printed
 */
int print_string(char *str)
{
	int count = 0, j;

	if (str == NULL)
		str = "(null)";
	for (j = 0; str[j] != '\0'; j++)
	{
		count += _putchar(str[j]);
	}
	return (count);
}
