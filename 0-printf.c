#include "main.h"
#include <stdarg.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int string_len = 0;
	va_list args;
	const char *str;
	int num;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			string_len++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			switch (*format)
			{
			case 'c':
				num = va_arg(args, int);
				_putchar(num);
				string_len++;
				break;

			case 's':
				str = va_arg(args, const char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					_putchar(*str);
					str++;
					string_len++;
				}
				break;

			case '%':
				_putchar('%');
				string_len++;
				break;

			case 'd':
			case 'i':
				num = va_arg(args, int);
				print_number(num, &string_len);
				break;

			default:
				_putchar('%');
				_putchar(*format);
				string_len += 2;
			}
		}
		format++;
	}
	va_end(args);
	return (string_len);
}
