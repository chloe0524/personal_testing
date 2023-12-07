#include "main.h"

int display_char(va_list args)
{
	_putchar((char) va_arg(args, int));
	return(1);
}

void print_number(int num, int *ctr)
{
	unsigned int number;

	if (num < 0)
	{
		number = -num;
		_putchar('-');
		*ctr=(*ctr)+1;
	}
	else
	{
		number = num;
	}

	if (number / 10)
	{
		print_number(number / 10,ctr);
	}
	_putchar('0' + (number % 10));
	*ctr=(*ctr)+1;
}

int display_int(va_list args)
{
	int ctr = 0;
	print_number (va_arg(args, int), &ctr);
	return(ctr);
}

int display_string(va_list args)
{
	char * str = va_arg(args, char *);
	int ctr=0;
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		ctr++;
	}
	return(ctr);
}

int display_double(va_list args)
{
	char *pb;
	int ctr = 0;

	char *dynamicBuffer = (char *)malloc(50 * sizeof(char));

	if (dynamicBuffer == NULL) {
		return -1;
	}

	pb = gcvt(va_arg(args, double), 10, dynamicBuffer);

	while (*pb)
	{
		_putchar(*pb++);
		ctr++;
	}

	free(dynamicBuffer);

	return ctr;
}

int display_percent()
{
	_putchar('%');
	return(1);
}

int (*isCharFormat(char carac, tdisplay * display)) (va_list)
{
	int i=0;

	while (display[i].format_type!=carac && display[i].format_type != '\0')
		i++;
	if (display[i].format_type != '\0')
		return (display[i].fdisplay);

	return NULL;
}
