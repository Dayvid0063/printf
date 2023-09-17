#include "main.h"
/**
 * get_size - Func prints size.
 * @format: Fmtted str.
 * @i: Lists arguments.
 *
 * Return: The size
 */
int get_size(const char *format, int *i)
{
int r = *i + 1;
int k = 0;
if (format[r] == 'l')
k = S_LONG;
else if (format[r] == 'h')
k = S_SHORT;
if (k == 0)
*i = r - 1;
else
*i = r;
return (k);
}
