#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_percent - print percent
 * @args: char
 *
 * Return: printed char
 */

int print_percent(va_list args __attribute__((unused)))
{
	return (_putchar('%'));
}
