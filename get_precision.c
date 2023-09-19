#include "main.h"

/**
 * get_precision - Func get presicion
 * @format: Format
 * @i: Index
 * @list: List
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int p = -1;

	if (format[curr_i] != '.')
		return (p);

	p = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			p *= 10;
			p += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			p = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (p);
}
