#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - A function that produce output according to format
 * format: specifier
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...);
{
	va_list args;
	int printed_chars;

	if (format == NULL)
		return (-1);

	va_starts(args, format);

	printed_chars = _vprintf(format, args);

	ve_end(args);

	return(printed_chars);
}
