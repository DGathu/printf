#include "main.h"
#include <stddef.h>
#include <starg.h>

/**
 * get_op - function for conversion
 * @c: character to check
 *
 * Return: pointer
 */

int (*get_op(const char c))(va_list)
{
	int x = 0;

	find_op op[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_nbr},
		{"d", print_nbr},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hexa_lower},
		{"X", print_hexa_upper},
		{"u", print_unsigned},
		{"S", print_str_unprintable},
		{"r", print_str_reverse},
		{"p", print_ptr},
		{"R", print_rot13},
		{"%", print_percent}
	};
	while (x < 14)
	{
		if (c == op[x].c[0])
		{
			return (op[x].f);
		}
		x++;
	}
	return (NULL);
}

/**
 * _printf - copy of printf functionality
 * @format: indentities
 *
 * Return: strings with identifiers
 */

int _printf(const char *format, ...)
{
	va_list ep;
	int sum = 0, x = 0;
	int (*func)();

	if (!format || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
	va_start(ep, format);

	while (format[x])
	{
		if (format[x] == '%')
		{
			if (format[x + 1] != '\0')
			{
				func = get_op(format[x + 1]);
			}
			if (func == NULL)
			{
				_putchar(format[x]);
				sum++;
				x++;
			}
			else
			{
				sum += func(ep);
				x += 2;
				continue;
			}
		}
		else
		{
			_putchar(format[x]);
			sum++;
			x++;
		}
	}
	va_end(ep);
	return (sum);
}
