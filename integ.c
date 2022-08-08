#include "main.h"
#include <stdio.h>

/**
 * _int - print integers
 * @integer: list
 * 
 * Return: Integers
 */

int _int(va_list integer)
{
	int x;
	int exp = 1;
	int len = 0;
	unsigned int y;

	x = va_arg(integer, int);

	if (x < 0)
	{
		len = len + _putchar('_');
		y = x * -1;
	}
	else
	{
		y = x;
	}
	while (y / exp > 9)
	{
		exp *= 10;
	}
	while (exp != 0)
	{
		len = len + _putchar(y / exp + '0');
		y = y % exp;
		exp = exp / 10;
	}
	return (len);
}
