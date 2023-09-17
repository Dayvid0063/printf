#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Func print char
 * @types: Type
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width
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
/************************* PRINT A STRING *************************/
/**
 * print_string - Func prints str
 * @types: Type
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, u;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (u = width - length; u > 0; u--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (u = width - length; u > 0; u--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
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
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int u = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[u--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[u--] = (num % 10) + '0';
		num /= 10;
	}

	u++;

	return (write_number(is_negative, u, buffer, flags, width, precision, size));
}
/************************* PRINT BINARY *************************/
/**
 * print_binary - Func print binary
 * @types: Types
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Num of char
 */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, u, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (u = 1; u < 32; u++)
	{
		m /= 2;
		a[u] = (n / m) % 2;
	}
	for (u = 0, sum = 0, count = 0; u < 32; u++)
	{
		sum += a[u];
		if (sum || u == 31)
		{
			char z = '0' + a[u];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
