#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * int_printf - Custom printf function that handles %d and %i specifiers only.
 * @format: The format string to be printed.
 * @...: Variable number of arguments to be printed.
 *
 * Return: Number of characters printed.
 */

int int_printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' */

			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				printed_chars += printf("%d", num);
			}
			else
			{
				/* Invalid specifier, print as is */
				putchar('%');
				putchar(*format);
				printed_chars += 2;
			}
		}
		else
		{
			putchar(*format);
			printed_chars++;
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}
