#include "main.h"
/**
 * get_width - Func prints width
 * @format: Fmtted str
 * @i: List arguments
 * @list: list arguments
 * Return: The width
 */
int get_width(const char *format, int *i, va_list list)
{
int r;
int v = 0;
for (r = *i + 1; format[r] != '\0'; r++)
{
if (is_digit(format[r]))
{
v *= 10;
v += format[r] - '0';
}
else if (format[r] == '*')
{
r++;
v = va_arg(list, int);
break;
}
else
break;
}
*i = r - 1;
return (r);
}
