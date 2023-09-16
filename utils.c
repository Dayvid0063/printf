#include "main.h"
/**
 * is_printable - Func checks if char is printable
 * @c: Evaluated char
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);
return (0);
}
/**
 * append_hexa_code - Func append hexa code
 * @buffer: Ar of chars
 * @i: Index
 * @ascii_code: Ascii code
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";
/* The hexa fmt code is always 2 digits long */
if (ascii_code < 0)
ascii_code *= -1;
buffer[i++] = '\\';
buffer[i++] = 'x';
buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];
return (3);
}
/**
 * is_digit - Func checks if char is a digit
 * @c: Evaluated char
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);
return (0);
}
/**
 * convert_size_number - Func convert num size
 * @num: Num casted
 * @size: Num casted size
 *
 * Return: Num value
 */
long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);
return ((int)num);
}
/**
 * convert_size_unsgnd - Func convert size unsgnd
 * @num: Num casted
 * @size: Num casted size
 *
 * Return: Num value
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);
return ((unsigned int)num);
}
