#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

/* Prototype for the _putchar function */
int _putchar(char c);

/* Prototype for the _printf function */
int _printf(const char *format, ...);

/* Prototypes for helper functions used by _printf */
int handle_char(va_list args);
int handle_string(va_list args);

/* Prototype for print_string helper function */
int print_string(char *str);

#endif /* MAIN_H */
