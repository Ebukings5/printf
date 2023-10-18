#include "main.h"

/**
 * _printf - function that prints values to the stdout
 * @format: The format specifier
 * Return: values count
 */
int _printf(const char *format, ...)
{
	int string_len = 0;
	va_list elements;
	va_start(elements, format);

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
			{
				break;
			}
			switch (*format)
			{
				case 'c':
				{
					char character = va_arg(elements, int);
					_putchar(character);
					string_len++;
					break;
				}
				case 's':
				{
					const char *str = va_arg(elements, const char *);

					if (str == NULL)
					{
						str = "(null)";
					}
					while (*str)
					{
						_putchar(*str);
						str++;
						string_len++;
					}
					break;
				}
				case '%':
				{
					_putchar('%');
					string_len++;
					break;
				}
				default:
					_putchar('%');
					_putchar(*format);
					string_len += 2;
					break;
			}
		}
		format++;
	}
	va_end(elements);
	return string_len;
}
