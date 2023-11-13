#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

// Declaration for standard printf function
int printf(const char *format, ...);

// Define INT_MAX if not modifying main.c
#ifndef INT_MAX
#define INT_MAX 2147483647 // Assuming 32-bit int
#endif

// Existing prototypes
int _putchar(char c);
int _printf(const char *format, ...);
int handle_char(va_list args);
int handle_string(va_list args);

#endif /* MAIN_H */
