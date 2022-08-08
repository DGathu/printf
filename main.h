#ifndef MAIN
#define MAIN
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct fmt - check formats
 * @type: format to print
 * @f: function
 */
typedef struct fmt
{
	char *type;
	int (*f)();
} fmt_t;

int _printf(const char *format, ...);
int print_op(const char *format, fmt_t *print_arr, va_list list);
int _putchar(char c);
int ch(va_list charact);
int _bin(va_list bin);
int _strlen(char *s);
int str(va_list string);
int _hex_u(va_list hexa);
int _hex_l(va_list hexa);
int _int(va_list integer);
int _ui(va_list unsign);
int _oct(va_list octo);
int _rot13(va_list rot);
int _hex_str(unsigned int n, unsigned int hex, char alpha);

#endif
