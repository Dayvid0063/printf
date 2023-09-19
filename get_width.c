#include "main.h"

/**
 * get_width - Func get width
 * @format: Format
 * @i: Index
 * @list: list
 *
 * Return: Width
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int h = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			h *= 10;
			h += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			h = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (h);
}
