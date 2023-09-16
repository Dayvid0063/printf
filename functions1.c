#include "main.h"
/**
 * print_unsigned - Func print unsigned num
 * @types: List arguments
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int u = BUFF_SIZE - 2;
unsigned long int v = va_arg(types, unsigned long int);
v = convert_size_unsgnd(v, size);
if (v == 0)
buffer[u--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (v > 0)
{
buffer[u--] = (v % 10) + '0';
v /= 10;
}
u++;
return (write_unsgnd(0, u, buffer, flags, width, precision, size));
}
/**
 * print_octal - Func print unsigned num in octal not.
 * @types: Lista arguments
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int u = BUFF_SIZE - 2;
unsigned long int v = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
v = convert_size_unsgnd(v, size);
if (v == 0)
buffer[u--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (v > 0)
{
buffer[u--] = (v % 8) + '0';
v /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[u--] = '0';
u++;
return (write_unsgnd(0, u, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Func print unsigned num in hexadecimal
 * @types: List arguments
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - Func print unsigned num in upper hexadecimal
 * @types: List arguments
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}
/**
 * print_hexa - Func print a hexadecimal num in lower or upper
 * @types: List arguments
 * @map_to: Values to map
 * @buffer: Buffer array
 * @flags:  Calculation of flags
 * @flag_ch: Calculation of flags
 * @width: The width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int u = BUFF_SIZE - 2;
unsigned long int v = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
v = convert_size_unsgnd(v, size);
if (v == 0)
buffer[u--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (v > 0)
{
buffer[u--] = map_to[v % 16];
v /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[u--] = flag_ch;
buffer[u--] = '0';
}
u++;
return (write_unsgnd(0, u, buffer, flags, width, precision, size));
}
