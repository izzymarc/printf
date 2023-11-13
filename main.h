#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/* Defining macros for general use in this header */
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* Defining bit flags for formatting options */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* Constants for size modifiers in printf */
#define S_LONG 2
#define S_SHORT 1

/* 
 * Format structure definition - part of my custom printf implementation 
 * char fmt: Format character
 * int (*fn)(va_list, char[], int, int, int, int): Pointer to function handling the format
 */
struct fmt {
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
};

/* Typedef for format structure for ease of use */
typedef struct fmt fmt_t;

/* Declaration of my version of printf function */
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

/************ PRINT FUNCTIONS ************/

/* Character and string print functions */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Number print functions */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Hexadecimal print helpers */
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Special character print functions */
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);

/************ HELPER FUNCTIONS ************/

/* Functions to parse format specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* String manipulation functions */
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Width handling for formatted output */
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);

/* Unsigned number handling */
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);

/************ UTILITY FUNCTIONS ************/

/* Utility functions for character processing */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

/* Size conversion functions for numbers */
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
