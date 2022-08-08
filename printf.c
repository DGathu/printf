#include "main.h"

/**
 * check_buffer_overflow - checks buffer
 * @buffer: the buffer holding string
 * @len: position
 *
 * Return: len
 */

int check_buffer_overflow(char *buffer, int len)
{
	if (len > 1020)
	{
		write(1, buffer, len);
		len = 0;
	}
	return (len);
}

/**
 * _printf - copy of printf functionality
 * @format: indentities
 *
 * Return: strings with identifiers
 */

int _printf(const char *format, ...)
{
	int len = 0;
	int total_len = 0;
	int x = 0;
	int y = 0;
	va_list list;
	char *buffer;
	char *str;
	char* (*f)(va_list);

	if (format == NULL)
	{
		return (-1);
	}
	buffer = create_buffer();

	if (buffer == NULL)
	{
		return (-1);
	}
	va_start(list, format);

	while (format[x] != '\0')
	{
		if (format[x] != '%')
		{
			len = check_buffer_overflow(buffer, len);
			buffer[len++] = format[x++];
			total_len++;
		}
		else
		{
			x++;
			if (format[x] == '\0')
			{
				va_end(list);
				free(buffer);
				return (-1);
			}
			if (format[x] == '%')
			{
				len = check_buffer_overflow(buffer, len);
				buffer[len++] = format[x];
				total_len++;
			}
			else
			{
				f = get_func(format[x]);
				if (f == NULL)
				{
					len = check_buffer_overflow(buffer, len);
					buffer[len++] = '%';
					total_len++;
					buffer[len++] = format[x];
					total_len++;
				}
				else
				{
					str = f(list);
					if (str == NULL)
					{
						va_end(list);
						free(buffer);
						return (-1);
					}
					if (format[x] == 'c' && str[0] == '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = '\0';
						total_len++;
					}
					y = 0;

					while (str[y] != '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = str[y];
						total_len++;
						y++;
					}
					free(str);
				}
			}
			x++;
		}
	}
	write_buffer(buffer, len, list);
	return (total_len);
}
