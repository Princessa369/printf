#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 * @list: list of arguments
 * Return: width
 */

int get_width(const char *format, int *i, va_list list)
{
	int prn_i;
	int width = 0;

	for (prn_i = *i + 1; format[prn_i] != '\0'; prn_i++)
	{
	if (is_digit(format[prn_i]))
	{
		width *= 10;
		width += format[prn_i] - '0';
	}
	else if (format[prn_i] == '*')
	{
		prn_i++;
		width = va_arg(list, int);
			break;
	}
		else
			break;
	}

	*i = prn_i - 1;

	return (width);
}
