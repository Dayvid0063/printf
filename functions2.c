#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Func prints ptr
 * @types: Types
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
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
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[u], BUFF_SIZE - u - 1));*/
	return (write_pointer(buffer, ind, length,
				width, flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Func print non printable char
 * @types: Types
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Sizer
 * Return: Num of chars
 */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int u = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[u] != '\0')
	{
		if (is_printable(str[u]))
			buffer[u + offset] = str[u];
		else
			offset += append_hexa_code(str[u], buffer, u + offset);

		u++;
	}

	buffer[u + offset] = '\0';

	return (write(1, buffer, u + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Func print rev str
 * @types: Types
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */

int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int u, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (u = 0; str[u]; u++)
		;

	for (u = u - 1; u >= 0; u--)
	{
		char z = str[u];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Func prints rot13
 * @types: Types
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int u, v;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (u = 0; str[u]; u++)
	{
		for (v = 0; in[v]; v++)
		{
			if (in[v] == str[u])
			{
				x = out[v];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[v])
		{
			x = str[u];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
