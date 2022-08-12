#include <stdlib.h>
#include "main.h"
#include <stdarg.h>

/**
 * print_hexa_upper - print hexa upper
 * @ep: arguments
 *
 * Return: printed char
 */

int print_hexa_upper(va_list ep)
{
	char *str;
	int sum;

	str = convert_base(va_arg(ep, unsigned int), 16, 1);
	sum = _puts(str, 0);
	free(str);
	return (sum);
}

/**
 * print_hexa_lower - print hexa lower
 * @ep: arguments
 *
 * Return: printed char
 */

int print_hexa_lower(va_list ep)
{
	char *str;
	int sum;

	str = convert_base(va_arg(ep, unsigned int), 16, 0);
	sum = _puts(str, 0);
	free(str);
	return (sum);
}

/**
 * print_octal - print octal
 * @ep: arguments
 *
 * Return: printed char
 */

int print_octal(va_list ep)
{
	char *str;
	int sum;

	str = convert_base(va_arg(ep, unsigned int), 8, 0);
	sum = _puts(str, 0);
	free(str);
	return (sum);
}

/**
 * print_binary - print binary
 * @ep: arguments
 *
 * Return: printed char
 */

int print_binary(va_list ep)
{
	char *str;
	int sum = 0;
	unsigned int argument = va_arg(ep, unsigned int);

	if (!argument)
	{
		sum += _puts("0", 0);
		return (sum);
	}
	str = convert_base(argument, 2, 0);
	if (!str)
	{
		return (0);
	}
	sum = _puts(str, 0);
	free(str);
	return (sum);
}

/**
 * print_nbr - print number
 * @ep: arguments
 *
 * Return: printed char
 */

int print_nbr(va_list ep)
{
	return (print_number(va_arg(ep, int)));
}
