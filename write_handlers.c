#include "main.h"
/**
 * handle_write_char - Func prints a str.
 * @c: char type.
 * @buffer: Buffer array.
 * @flags:  Calculations of flags.
 * @width: The width.
 * @precision: Precision.
 * @size: Size.
 *
 * Return: Num of chars
 */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
int u = 0;
char padd = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & F_ZERO)
padd = '0';
buffer[u++] = c;
buffer[u] = '\0';
if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (u = 0; u < width - 1; u++)
buffer[BUFF_SIZE - u - 2] = padd;
if (flags & F_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - u - 1], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - u - 1], width - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}
/**
 * write_number - Func prints a str.
 * @is_negative: List arguments.
 * @ind: char type.
 * @buffer: Buffer array.
 * @flags:  Calculations of flags.
 * @width: The width.
 * @precision: Precision.
 * @size: Size.
 *
 * Return: Num of chars
 */
int write_number(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size)
{
int length = BUFF_SIZE - ind - 1;
char padd = ' ', h = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (is_negative)
h = '-';
else if (flags & F_PLUS)
h = '+';
else if (flags & F_SPACE)
h = ' ';
return (write_num(ind, buffer, flags, width, precision,
length, padd, h));
}
/**
 * write_num - Func writes a num.
 * @ind: Index.
 * @buffer: Buffer array.
 * @flags: Calculations of flag.
 * @width: The width.
 * @prec: Precision.
 * @length: Length num.
 * @padd: Char padding.
 * @extra_c: Extra char.
 * Return: Num of chars
 */
int write_num(int ind, char buffer[],
int flags, int width, int prec,
int length, char padd, char extra_c)
{
int u, padd_start = 1;
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
return (0); /* printf(".0d", 0)  no char is printed */
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buffer[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (width > length)
{
for (u = 1; u < width - length + 1; u++)
buffer[u] = padd;
buffer[u] = '\0';
if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[1], u - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[1], u - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
{
if (extra_c)
buffer[--padd_start] = extra_c;
return (write(1, &buffer[padd_start], u - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start)));
}
}
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length));
}
/**
 * write_unsgnd - Func writes an unsigned num.
 * @is_negative: Num shows negative.
 * @ind: Index.
 * @buffer: Buffer array.
 * @flags: Calculations of flags.
 * @width: The width.
 * @precision: Precision.
 * @size: Size.
 *
 * Return: Num of chars
 */
int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size)
{
/* The number is stored at the bufer's right and starts at position u */
int length = BUFF_SIZE - ind - 1, u = 0;
char padd = ' ';
UNUSED(is_negative);
UNUSED(size);
if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
return (0); /* printf(".0d", 0)  no char is printed */
if (precision > 0 && precision < length)
padd = ' ';
while (precision > length)
{
buffer[--ind] = '0';
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (width > length)
{
for (u = 0; u < width - length; u++)
buffer[u] = padd;
buffer[u] = '\0';
if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
{
return (write(1, &buffer[ind], length) + write(1, &buffer[0], u));
}
else /* Asign extra char to left of padding [padd>buffer]*/
{
return (write(1, &buffer[0], u) + write(1, &buffer[ind], length));
}
}
return (write(1, &buffer[ind], length));
}
/**
 * write_pointer - Func write a ptr.
 * @buffer: Buffer array.
 * @ind: Index.
 * @length: Length.
 * @width: The width.
 * @flags: Calculations of flags.
 * @padd: Char padding.
 * @extra_c: Extra char.
 * @padd_start: Index padding start.
 *
 * Return: Num of chars
 */
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start)
{
int u;
if (width > length)
{
for (u = 3; u < width - length + 3; u++)
buffer[u] = padd;
buffer[u] = '\0';
if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[3], u - 3));
}
else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[3], u - 3) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
{
if (extra_c)
buffer[--padd_start] = extra_c;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], u - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
