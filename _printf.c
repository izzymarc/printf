#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Prints a character
 * @c: Character to print
 * Return: Number of characters printed
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @str: String to print
 * Return: Number of characters printed
 */
int print_string(char *str)
{
	int count = 0;
	int i;	/* Declare loop variable outside the for loop */

	if (!str)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		count += print_char(str[i]);
	return (count);
}

/**
 * print_int - Prints an integer
 * @n: Integer to print
 * Return: Number of characters printed
 */
int print_int(int n)
{
	int count = 0;

	if (n < 0)
	{
		count += print_char('-');
		n = -n;
	}
	if (n / 10)
		count += print_int(n / 10);
	count += print_char((n % 10) + '0');
	return (count);
}

/**
 * print_unsigned - Prints an unsigned integer
 * @n: Unsigned integer to print
 * Return: Number of characters printed
 */
int print_unsigned(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned(n / 10);
	count += print_char((n % 10) + '0');
	return (count);
}

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;	/* Declare loop variable outside the for loop */

	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += print_char(va_arg(args, int));
					break;
				case 's':
					count += print_string(va_arg(args, char*));
					break;
				case '%':
					count += print_char('%');
					break;
				case 'd':
				case 'i':
					count += print_int(va_arg(args, int));
					break;
				case 'u':
					count += print_unsigned(va_arg(args, unsigned int));
					break;
				default:
					count += print_char('%');
					count += print_char(format[i]);
					break;
			}
		}
		else
			count += print_char(format[i]);
	}
	va_end(args);

	return (count);
}
