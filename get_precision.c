#include "main.h"
/**
 * get_precision - Func calculates the precision.
 * @format: Fmtted str.
 * @i: List arguments.
 * @list: list arguments.
 *
 * Return: The precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
int r = *i + 1;
int n = -1;
if (format[r] != '.')
return (n);
n = 0;
for (r += 1; format[r] != '\0'; r++)
{
if (is_digit(format[r]))
{
n *= 10;
n += format[r] - '0';
}
else if (format[r] == '*')
{
r++;
n = va_arg(list, int);
break;
}
else
break;
}
*i = r - 1;
return (n);
}
