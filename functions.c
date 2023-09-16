#include "main.h"
/************************* PRINT CHARACTER *************************/
/**
 * print_char - Func prints char
 * @types: List arguments
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT STRING *************************/
/**
 * print_string - Func prints str
 * @types: List arguments
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int h = 0, u;
char *string = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (string == NULL)
{
string = "(null)";
if (precision >= 6)
string = "      ";
}
while (string[h] != '\0')
h++;
if (precision >= 0 && precision < h)
h = precision;
if (width > h)
{
if (flags & F_MINUS)
{
write(1, &string[0], h);
for (u = width - h; u > 0; u--)
write(1, " ", 1);
return (width);
}
else
{
for (u = width - h; u > 0; u--)
write(1, " ", 1);
write(1, &string[0], h);
return (width);
}
}
return (write(1, string, h));
}
/************************* PRINT % SIGN *************************/
/**
 * print_percent - Func prints percent sign
 * @types: Lista arguments
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
/************************* PRINT INT *************************/
/**
 * print_int - Func print int
 * @types: List arguments
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int u = BUFF_SIZE - 2;
int k = 0;
long int w = va_arg(types, long int);
unsigned long int v;
w = convert_size_number(w, size);
if (w == 0)
buffer[u--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
v = (unsigned long int)w;
if (w < 0)
{
v = (unsigned long int)((-1) * w);
k = 1;
}
while (v > 0)
{
buffer[u--] = (v % 10) + '0';
v /= 10;
}
u++;
return (write_number(k, u, buffer, flags, width, precision, size));
}
/************************* PRINT BINARY *************************/
/**
 * print_binary - Func print unsigned num
 * @types: List arguments
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of char
 */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int w, o, u, g;
unsigned int a[32];
int t;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
w = va_arg(types, unsigned int);
o = 2147483648; /* (2 ^ 31) */
a[0] = w / o;
for (u = 1; u < 32; u++)
{
o /= 2;
a[u] = (w / o) % 2;
}
for (u = 0, g = 0, t = 0; u < 32; u++)
{
g += a[u];
if (g || u == 31)
{
char z = '0' + a[u];
write(1, &z, 1);
t++;
}
}
return (t);
}
