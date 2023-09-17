#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf func.
 * @format: Format style.
 * Return: Num of chars printed.
 */
int _printf(const char *format, ...)
{
int u, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list args;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(args, format);
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
width = get_width(format, &u, args);
precision = get_precision(format, &u, args);
size = get_size(format, &u);
++u;
printed = handle_print(format, &u, args, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buffer(buffer, &buff_ind);
va_end(args);
return (printed_chars);
}
/**
 * print_buffer - Prints buffer contents.
 * @buffer: Ar of characters.
 * @buff_ind: Index adds char, shows the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}
