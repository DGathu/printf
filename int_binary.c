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
	int twos = 1;
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
		twos *= 2;
	}
	while (twos > 0)
	{
		s[y++] = (x / twos + '0');
		x %= twos;
		twos /= 2;
	}
	s[y] = '\0';
	return (s);
}
