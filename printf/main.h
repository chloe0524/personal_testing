#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

/*structure*/
typedef struct
{
	char format_type;
	int (*fdisplay)(va_list);
} tdisplay;

/*Prototype de fonctions*/
int _printf(const char *format, ...);

int _putchar(char c);


int display_string(va_list args);
int display_char(va_list args);
int display_double(va_list args);
int display_int(va_list args );
int display_percent();

int (*isCharFormat(char carac, tdisplay * display)) (va_list);

#endif
