#include "main.h"
/**
 * handle_print - Func prints an argument.
 * @fmt: Fmtted str.
 * @list: Lists arguments.
 * @ind: ind.
 * @buffer: Buffer array.
 * @flags: Calculation of flags.
 * @width: The width.
 * @precision: Precision.
 * @size: Size.
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
int u, h = 0, v = -1;
fmt_t fmt_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};
for (u = 0; fmt_types[u].fmt != '\0'; u++)
if (fmt[*ind] == fmt_types[u].fmt)
return (fmt_types[u].fn(list, buffer, flags, width, precision, size));
if (fmt_types[u].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);
h += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
h += write(1, " ", 1);
else if (width)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
h += write(1, &fmt[*ind], 1);
return (h);
}
return (v);
}
