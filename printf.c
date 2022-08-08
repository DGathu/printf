#include <stdio.h>
#include "main.h"

/**
 * print_op - checks specifier
 * @format: the format
 * @print_arr: array of struct
 * @list: arguments
 * 
 * Return: char to print
 */

int print_op(const char *format, fmt_t *print_arr, va_list list)
{
	char x;
	int count = 0, y = 0, z = 0;

	x = format[y];

	while (x != '\0')
	{
		if (x == '%')
		{
			z = 0;
			y++;
			x = format[y];
			
			while (print_arr[z].type != NULL &&
					x != *(print_arr[z].type))
			{
				z++;
			}
			if (print_arr[z].type != NULL)
			{
				count = count + print_arr[z].f(list);
			}
			else
			{
				if (x == '\0')
				{
					return (-1);
				}
				if (x != '%')
				{
					count += _putchar('%');
				}
				count += _putchar(x);
			}
		}
		else
		{
			count += _putchar(x);
		}
		y++;
		x = format[y];
	}
	return (count);
}

/**
 * _printf - prints output
 * @format: the format
 *
 * Return: char to print
 */

int _printf(const char *format, ...)
{
	va_list list;
	int x = 0;

	fmt_t ops[] = {
		{"c", ch},
		{"R", _rot13},
		{"s", str},
		{"X", _hex_u},
		{"d", _int},
		{"x", _hex_l},
		{"b", _bin},
		{"o", _oct},
		{"i", _int},
		{"u", _ui},
		{NULL, NULL}
	};
	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);
	x = print_op(format, ops, list);
	va_end(list);
	return (x);
}
