#include "main.h"

/**
 * get_func - returns needed func
 * @i: identifier
 *
 * Return: pointer to func
 */

char* (*get_func(char i))(va_list)
{
	int x = 0;
	print keys[] = {
		{'c', print_c},
		{'o', getoct},
		{'s', print_s},
		{'r', rev_string},
		{'d', print_d},
		{'R', rot13},
		{'b', getob},
		{'\0', NULL}
	};

	while (keys[x].id != '\0')
	{
		if (keys[x].id == i)
		{
			return (keys[x].func);
		}
		x++;
	}
	return (NULL);
}

/**
 * create_buffer - creates buffer
 *
 * Return: pointer to buffer
 */

char *create_buffer(void)
{
	char *buffer;
	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		return (NULL);
	}
	return (buffer);
}

/**
 * write_buffer - prints buffer
 * @buffer: buffer
 * @len: length of string
 * @list: va_list
 */

void write_buffer(char *buffer, int len, va_list list)
{
	char *buff;

	buff = realloc(buffer, len);
	write(1, buff, len);
	free(buff); va_end(list);
}
