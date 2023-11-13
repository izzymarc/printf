#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _print_char - Prints a character.
 * @c: Character to print.
 * Return: Number of characters printed.
 */
int _print_char(char c) {
    return write(1, &c, 1);
}

/**
 * _print_str - Prints a string.
 * @str: String to print.
 * Return: Number of characters printed.
 */
int _print_str(char *str) {
    int count = 0;

    if (str == NULL) {
        str = "(null)";
    }

    while (*str) {
        count += _print_char(*str++);
    }

    return count;
}

/**
 * _printf - Custom printf function to handle 'c', 's', and '%' specifiers.
 * @format: Format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...) {
    int count = 0;
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    count += _print_char(va_arg(args, int));
                    break;
                case 's':
                    count += _print_str(va_arg(args, char *));
                    break;
                case '%':
                    count += _print_char('%');
                    break;
                default:
                    count += _print_char('%');
                    count += _print_char(*format);
            }
        } else {
            count += _print_char(*format);
        }
        format++;
    }

    va_end(args);
    return count;
}
