#include <stdarg.h>
#include "main.h"
#include <limits.h>
#include <stdlib.h>

/**
 * print_unsigned - unsigned int
 * @ep: arguments
 *
 * Return: value
 */

int print_unsigned(va_list ep)
{
	unsigned int argument = va_arg(ep, unsigned int);

	return (print_unsigned_number(argument));
}

/**
 * print_ptr - print pointer addr
 * @ep: arguments
 *
 * Return: printed char
 */

int print_ptr(va_list ep)
{
	char *str;
	int sum = 0;
	unsigned long p = (unsigned long) va_arg(ep, void*);

	if (!p)
	{
		sum += _puts("(nil)", 0);
		return (sum);
	}
	str = convert_base_pointer(p);
	if (!str)
	{
		return (0);
	}
	sum += _puts("0x", 0);
	sum += _puts(str, 0);
	free(str);
	return (sum);
}
