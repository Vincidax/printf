#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - A function that produces output according to format
 * @format: specifier
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			/* Check for specifier character */
			switch (*format)
			{
				case 'c': /* c specifier */
					print_char(args, &printed_chars);
					break;
				case 's': /* s specifier */
					print_string(args, &printed_chars);
					break;
				case '%': /* % specifier */
					print_percent(&printed_chars);
					break;
				default:
					putchar('%');
					printed_chars++;
					break;
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

/**
 * print_char - Helper function to print character specifier
 * @args: va_list of arguments
 * @printed_chars: pointer to number of characters printed
 */
void print_char(va_list args, int *printed_chars)
{
	int c = va_arg(args, int);

	putchar(c);
	(*printed_chars)++;
}

/**
 * print_string - Helper function to print string specifier
 * @args: va_list of arguments
 * @printed_chars: pointer to number of characters printed
 */
void print_string(va_list args, int *printed_chars)
{
	const char *s = va_arg(args, const char *);

	while (*s != '\0')
	{
		putchar(*s);
		s++;
		(*printed_chars)++;
	}
}

/**
 * print_percent - Helper function to print percent specifier
 * @printed_chars: pointer to number of characters printed
 */
void print_percent(int *printed_chars)
{
	putchar('%');
	(*printed_chars)++;
}
