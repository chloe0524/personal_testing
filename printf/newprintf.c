#include "main.h"


int _printf(const char *format, ...)
{
	va_list list;
	int i = 0;
	int ctr = 0;

	int (* pDisplay)(va_list va);


	/*tableau de structures associé à la structure "tdisplay"*/
	tdisplay display[]={
		{'c', display_char},
		{'s', display_string},
		{'d', display_double},
		{'i', display_int},
		{'%', display_percent},
		{'\0', NULL}
	};

	va_start(list, format);

	while (format && format[i])
	{
		pDisplay=isCharFormat(format[i],display);
		if (pDisplay != NULL)   /* This is a known format character */
			ctr += pDisplay (list);
		i++;
	}

	va_end(list);
	return (ctr);
}

