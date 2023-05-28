#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 * @list: list of arguments
 * Return: Precision
 */

int get_precision(const char *format, int *i, va_list list)
{
	int prn_i = *i + 1;
	int precision = -1;

	if (format[prn_i] != '.')
		return (precision);

	precision = 0;

	for (prn_i += 1; format[prn_i] != '\0'; prn_i++)
	{
	if (is_digit(format[prn_i]))
	{
		precision *= 10;
		precision += format[prn_i] - '0';
	}
	else if (format[prn_i] == '*')
	{
		prn_i++;
		precision = va_arg(list, int);
			break;
	}
		else
			break;
	}

	*i = prn_i - 1;

	return (precision);
}
