#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf func
 * @format: the fmt
 * Return: Chars printed
 */
int _printf(const char *format, ...)
{
int u, w = 0, v = 0;
int k, h, n, e, buff_ind = 0;
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
v++;
}
else
{
print_buffer(buffer, &buff_ind);
k = get_k(format, &u);
h = get_h(format, &u, list);
n = get_n(format, &u, list);
e = get_e(format, &u);
++u;
w = handle_print(format, &u, list, buffer, k, h, n, e);
if (w == -1)
return (-1);
v += w;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (v);
}
/**
 * print_buffer - Prints buffer contents
 * @buffer: Ar of characters
 * @buff_ind: Index adds char, show the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}