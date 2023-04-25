#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - A function that produces output according to format
 * @format: The format specifier string
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
            case 'd': /* d specifier */
            case 'i': /* i specifier */
                print_int(args, &printed_chars);
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
 * print_int - Helper function to print signed integer specifier
 * @args: va_list of arguments
 * @printed_chars: pointer to number of characters printed
 */
void print_int(va_list args, int *printed_chars)
{
    int n = va_arg(args, int);
    int sign = 1;
    int digits[10];
    int i;

    if (n < 0)
    {
        sign = -1;
        n = -n;
    }

    for (i = 0; n > 0; i++)
    {
        digits[i] = n % 10;
        n /= 10;
    }

    if (sign == -1)
    {
        putchar('-');
        (*printed_chars)++;
    }

    for (i = i - 1; i >= 0; i--)
    {
        putchar(digits[i] + '0');
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
