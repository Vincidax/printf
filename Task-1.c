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
				case 'd': /* d specifier */
				case 'i': /* i specifier */
					print_int(args, &printed_chars);
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
 * print_int - Helper function to print integer specifier
 * @args: va_list of arguments
 * @printed_chars: pointer to number of characters printed
 */
void print_int(va_list args, int *printed_chars)
{
	int num = va_arg(args, int);

	printf("%d", num);
	(*printed_chars) += num_digits(num);
}

/**
 * num_digits - Helper function to count the number of digits in an integer
 * @num: integer to count digits of
 *
 * Return: Number of digits in num
 */
int num_digits(int num)
{
	int digits = 0;

	if (num == 0)
		return (1);

	while (num != 0)
	{
		num /= 10;
		digits++;
	}

	return (digits);
}

