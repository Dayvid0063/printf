#include "main.h"
/**
 * get_flags - Flags avaliable
 * @format: Fmtted str
 * @i: A parameter
 * Return: The flags
 */
int get_flags(const char *format, int *i)
{
/* - + 0 # ' ' */
/* 1 2 4 8  16 */
int o, curr_i;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
for (o = 0; FLAGS_CH[o] != '\0'; o++)
{
if (format[curr_i] == FLAGS_CH[o])
{
flags |= FLAGS_ARR[o];
break;
}
}

if (FLAGS_CH[o] == 0)
{
break;
}
}

*i = curr_i - 1;

return (flags);
}
