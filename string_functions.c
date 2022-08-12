#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_rot13 - print rot13
 * @ep: arguments
 *
 * Return: printed char
 */

int print_rot13(va_list ep)
{
	int sum = 0;
	char *str, *argument = va_arg(ep, char*);

	if (!argument)
	{
		sum += _puts("%R", 0);
		return (sum);
	}
	str = convert_rot13(argument);

	if (!str)
	{
		return (0);
	}
	sum = _puts(str, 0);
	free(str);
	return (sum);
}

/**
 * print_str_reverse - print string in reverse
 * @ep: arguments
 *
 * Return: printed char
 */

int print_str_reverse(va_list ep)
{
	char *argument = va_arg(ep, char *), *str;
	int size, left, limit, right, sum = 0;

	if (!argument)
	{
		sum += _puts("%r", 0);
		return (sum);
	}

	size = _strlen_recursion(argument);
	right = size - 1;
	limit = (size % 2 == 0) ? (size + 1) / 2 : (size / 2);

	str = malloc(sizeof(char) * size + 1);

	if (str == NULL)
	{
		return (0);
	}
	if (size % 2 != 0)
	{
		str[limit] = argument[limit];
	}
	for (left = 0; left < limit; left++)
	{
		str[left] = argument[right];
		str[right] = argument[left];
		right--;
	}
	str[size] = '\0';
	sum = _puts(str, 0);
	free(str);
	return (sum);
}

/**
 * print_str_unprintable - print string unprintable
 * @ep: arguments
 *
 * Return: printed char
 */

int print_str_unprintable(va_list ep)
{
	char *argument = va_arg(ep, char *);
	int sum = 0;

	if (!argument)
	{
		sum += _puts("(null)", 0);
		return (sum);
	}
	return (_puts(argument, 1));
}

/**
 * print_str - print string
 * @ep: arguments
 *
 * Return: printed char
 */

int print_str(va_list ep)
{
	char *argument = va_arg(ep, char *);
	int sum = 0;

	if (!argument)
	{
		sum += _puts("(null)", 0);
		return (sum);
	}
	return (_puts(argument, 0));
}

/**
 * print_char - print character
 * @ep: arguments
 *
 * Return: printed char
 */

int print_char(va_list ep)
{
	char c = va_arg(ep, int);

	if (c == '\0')
	{
		return (write(1, &c, 1));
	}
	_putchar(c);
	return (1);
}
