#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>

int _printf(const char *format, ...);
int putchar(int c);

/* Function prototypes for helper functions */
void print_char(va_list args, int *printed_chars);
void print_string(va_list args, int *printed_chars);
void print_percent(int *printed_chars);
void print_int(va_list args, int *printed_chars);


#endif
