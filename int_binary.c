#include "main.h"

/**
 * getob - int to binary
 * @list: int
 *
 * Return: binary
 */

char *getob(va_list list)
{
	int y = 0;
	two = 1;
	int x;
	int z;
	char *s;

	z = va_arg(list, int);
	x = z;
	s = malloc(sizeof(char) * 33);

	if (s == NULL)
	{
		return (NULL);
	}
	if (z < 0)
	{
		s[0] = 1 + '0';
		y++;
		z *= -1;
		x *= -1;
	}
	while (z > 1)
	{
		z /= 2;
		two *= 2;
	}
	while (two > 0)
	{
		s[y++] = (x / two + '0');
		x %= two;
		two /= 2;
	}
	s[y] = '\0';
	return (s);
}
