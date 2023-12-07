#include "main.h"

/**
 *_printf - prints to output according to format
 *@format: character string containing format specification
 *
 *Return: number of characters printed or -1 if format NULL
 */

int _printf(const char *format, ...)
{
	va_list list;
	int i = 0;
	int ctr = 0; /* counter */
	int (*p_display)(va_list list);

	va_start(list, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar (format[i]);
			i++;
			ctr++;
			continue;
		}
		i++;
		p_display = is_char_format(format[i]); /* get format specifier function */
		if (p_display != NULL)
			ctr += p_display(list); /* call function and update the counter */
		else
		{
			if (format[i] == '\0')
				return (-1);
			if (format[i] == '%')
				ctr += _putchar('%');
			else
			{
				_putchar('%');
				_putchar(format[i]);
				ctr += 2;
			}
		}
		i++;
	}
	va_end(list);
	return (ctr);
}
