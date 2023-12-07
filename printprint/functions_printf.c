#include "main.h"


/**
 *display_char - prints a character
 *@args: argument
 *
 *Return: 1, only one character printed
 */

int display_char(va_list args)
{
	/*fprintf(stderr,"display_char\n");*/
	_putchar ((char) va_arg(args, int));
	return (1);
}

/**
 *display_int - prints a integer
 *@args: argument
 *
 *Return: lenght of string printed character printed
 */

int display_int(va_list args)
{
	int value;
	unsigned int abs, a, ctr;
	unsigned int countn = 1;

	ctr = 0;

	value = va_arg(args, int);

	if (value < 0)
	{
		ctr = ctr + _putchar('-');
		abs = value * -1;
	}
	else
		abs = value;

	a = abs;
	while (a > 9)
	{
		a = a / 10;
		countn = countn * 10;
	}
	while (countn >= 1)
	{
		ctr = ctr + _putchar(((abs / countn) % 10) + '0');
		countn = countn / 10;
	}
	return (ctr);
}


/**
 *display_string - prints a string
 *@args: argument
 *
 *Return: length of string printed
 */

int display_string(va_list args)
{
	char *str = va_arg(args, char *);
	int ctr = 0;

	if (str == NULL)
		str = "(null)";
	while (*str != '\0')
	{
		_putchar (*str);
		str++;
		ctr++;
	}
	return (ctr);
}

/**
 *display_percent - prints character %
 *@args: argument
 *
 *Return: 1, only one character printed
 */

int display_percent(va_list args)
{
	(void)args;
	_putchar ('%');
	return (1);
}

/**
 *is_char_format - returns pointer to print function per format type
 *@carac: to help figure out if known character
 *
 *Return: pointer to print function
 */

int (*is_char_format(char carac)) (va_list)
{
	int i = 0;

	/*tableau de structures associé à la structure "tdisplay"*/
	tdisplay display[] = {
		{'c', display_char},
		{'s', display_string},
		{'%', display_percent},
		{'d', display_int},
		{'i', display_int},
		{'\0', NULL}
	};

	while (display[i].format_type != carac && display[i].format_type != '\0')
		i++;
	if (display[i].format_type != '\0')
		return (display[i].fdisplay);
	return (NULL);
}
