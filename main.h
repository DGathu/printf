#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct find_printf - check formats
 * @c: string
 * @f: function
 */
typedef struct find_printf
{
	char *c;
	int (*f)(va_list);
} find_op;

int _printf(const char *format, ...);
int print_char(va_list ep);
int print_str(va_list ep);
int print_nbr(va_list ep);
int print_binary(va_list ep);
int print_octal(va_list ep);
int print_hexa_lower(va_list ep);
int print_hexa_upper(va_list ep);
int print_unsigned(va_list ep);
int print_str_unprintable(va_list ep);
int print_str_reverse(va_list ep);
int print_ptr(va_list ep);
int print_rot13(va_list ep);
int print_percent(va_list ep __attribute__((unused)));
int print_number(int n);
int print_unsigned_number(unsigned int n);
int _putchar(char c);
int _puts(char *str, int ascii);
int _nbr_len(int prmnumber);
int _strlen_recursion(char *s);
int convert_alpha_numeric(int nb, int upper);
char *convert_rot13(char *str);
char *convert_base(unsigned long nb, unsigned int base, int upper);
char *_strdup(char *str);
char *convert_base_pointer(unsigned long p);

#endif
