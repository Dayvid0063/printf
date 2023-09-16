#include "main.h"
/**
 * print_pointer - Func prints ptr value
 * @types: List arguments
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char y = 0, d = ' ';
int n = BUFF_SIZE - 2, h = 2, p = 1; /* h=2, for '0x' */
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);
UNUSED(width);
UNUSED(size);
if (addrs == NULL)
return (write(1, "(nil)", 5));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
num_addrs = (unsigned long)addrs;
while (num_addrs > 0)
{
buffer[n--] = map_to[num_addrs % 16];
num_addrs /= 16;
h++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
d = '0';
if (flags & F_PLUS)
y = '+', h++;
else if (flags & F_SPACE)
y = ' ', h++;
n++;
/*return (write(1, &buffer[u], BUFF_SIZE - u - 1));*/
return (write_pointer(buffer, n, h,
width, flags, d, y, p));
}
/**
 * print_non_printable - Func prints ascii codes ...
 * @types: List arguments
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int u = 0, t = 0;
char *string = va_arg(types, char *);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (string == NULL)
return (write(1, "(null)", 6));
while (string[u] != '\0')
{
if (is_printable(string[u]))
buffer[u + t] = string[u];
else
t += append_hexa_code(string[u], buffer, u + t);
u++;
}
buffer[u + t] = '\0';
return (write(1, buffer, u + t));
}
/**
 * print_reverse - Func print reverse str
 * @types: List arguments
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *str;
int u, c = 0;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);
string = va_arg(types, char *);
if (string == NULL)
{
UNUSED(precision);
string = ")Null(";
}
for (u = 0; string[u]; u++)
;
for (u = u - 1; u >= 0; u--)
{
char z = string[u];
write(1, &z, 1);
c++;
}
return (c);
}
/**
 * print_rot13string - Func print str in rot13
 * @types: List arguments
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char a;
char *string;
unsigned int u, o;
int c = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
string = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (string == NULL)
string = "(AHYY)";
for (u = 0; string[u]; u++)
{
for (o = 0; in[o]; o++)
{
if (in[o] == string[u])
{
a = out[o];
write(1, &a, 1);
c++;
break;
}
}
if (!in[o])
{
a = string[u];
write(1, &a, 1);
c++;
}
}
return (t);
}
