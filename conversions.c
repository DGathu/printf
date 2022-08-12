#include <stdlib.h>
#include "main.h"

/**
 * convert_rot13 - converts rot13
 * @str: string
 *
 * Return: printed char
 */

char *convert_rot13(char *str)
{
	int i = 0;
	char *s;
	int size = _strlen_recursion(str);

	s = malloc(sizeof(char) * size + 1);
	if (!s)
	{
		return (0);
	}
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
		{
			s[i] = str[i] + 13;
		}
		else if ((str[i] >= 'n' && str [i] <= 'z')
				|| (str[i] >= 'N' && str[i] <= 'Z'))
		{
			s[i] = str[i] - 13;
		}
		else
		{
			s[i] = str[i];
		}
		i++;
	}
	s[i] = '\0';
	return (s);
}

/**
 * convert_base_pointer - converts base pointer
 * @p: pointer
 *
 * Return: printed char
 */

char *convert_base_pointer(unsigned long p)
{
	unsigned long address;
	char *str;

	address = p;
	if (address == 0)
	{
		return ("0");
	}
	str = convert_base(address, 16, 0);
	return (str);
}

/**
 * convert_base - converts to base
 * @nb: decimal
 * @base: base to convert
 * @upper: upper case
 *
 * Return: printed char
 */

char *convert_base(unsigned long nb, unsigned int base, int upper)
{
	int x = 0;
	char *str;
	unsigned long nbr = nb;

	while (nbr >= base)
	{
		nbr /= base;
		x++;
	}
	str = malloc(sizeof(char) * x + 2);
	if (!str)
	{
		return (0);
	}
	str[x + 1] = '\0';

	while (x >= 0)
	{
		nbr = nb % base;
		str[x] = convert_alpha_numeric(nbr, upper);
		nb /= base;
		x--;
	}
	return (str);
}

/**
 * convert_alpha_numeric - converts alpha to numeric
 * @nb: digit
 * @upper: upper case
 *
 * Return: printed char
 */

int convert_alpha_numeric(int nb, int upper)
{
	if (nb >= 10)
	{
		return (nb - 10 + ((upper) ? 'A' : 'a'));
	}
	else
	{
		return (nb + '0');
	}
}
