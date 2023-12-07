#include "main.h"

/**
 * print_decim - prints decimal
 * @args: the argument decimal
 *
 * Return: counter
 */

int print_decim(va_list args)
{
	int value;
	unsigned int abs_value, a, len;
	unsigned int ctr = 1;

	len = 0;

	value = va_arg(args, int);

	if (value < 0)
	{
		len = len + _putchar('-');
		abs_value = value * -1;
	}
	else
		abs_value = value;

	a = abs_value;
	while (a > 9)
	{
		a = a / 10;
		ctr = ctr * 10;
	}
	while (ctr >= 1)
	{
		len = len + _putchar(((abs_value / ctr) % 10) + '0');
		ctr = ctr / 10;
	}
	return (len);
}

