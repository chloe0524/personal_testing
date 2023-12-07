#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct tdisplay - Format specifier and associated display function
 *
 * @format_type: Format specifier string.
 * @fdisplay: Pointer to the function for displaying the format.
 *
 */
typedef struct tdisplay
{
	char format_type;
	int (*fdisplay)(va_list);
} tdisplay;

/*Prototype de fonctions*/
int _printf(const char *format, ...);

int _putchar(char c);

int display_string(va_list args);
int display_char(va_list args);
int display_percent(va_list args);
int (*is_char_format(char carac)) (va_list args);

#endif

