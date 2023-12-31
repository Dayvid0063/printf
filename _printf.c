#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Function printf
 * @format: Fmt
 * Return: Chars printed
 */
int _printf(const char *format, ...)
{
	int u, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (u = 0; format && format[u] != '\0'; u++)
	{
		if (format[u] != '%')
		{
			buffer[buff_ind++] = format[u];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[u], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &u);
			width = get_width(format, &u, list);
			precision = get_precision(format, &u, list);
			size = get_size(format, &u);
			++u;
			printed = handle_print(format, &u, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Func print buffer
 * @buffer: Buffer
 * @buff_ind: Buffer index
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
