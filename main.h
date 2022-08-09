#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct fmt - check formats
 * @type: format to print
 * @f: function
 */
typedef struct types
{
	char id;
	char* (*func)(va_list);
} print;

char* (*get_func(char i))(va_list);
char *create_buffer(void);
void write_buffer(char *buffer, int len, va_list list);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

int _printf(const char *format, ...);
char *getoct(va_list list);
char *rev_string(va_list list);
char *rot13(va_list list);
char *getob(va_list list);
char *print_d(va_list list);
char *print_c(va_list list);
char *print_s(va_list list);

#endif
