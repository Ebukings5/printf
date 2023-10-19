#include "main.h"

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
	unsigned int binary;

	va_start (args, format);
	while (format && *format)
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
			case 'b':
				binary = va_arg(args, unsigned int);
				print_binary(binary, &string_len);
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
<<<<<<< HEAD
/************************* PRINT INT *************************/
/**
 * print_number - Print an integer using _putchar
 * @n: The integer to print
 * @len: Pointer to the length counter
=======

/**
 * print_number - print an integar
 * @n: the int to print
 * @len: pointer to length 
 *
 * Return: 0
>>>>>>> ae578e4 (updated task 0 to meet the outcome of task 2)
 */
void print_number(int n, int *len)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
<<<<<<< HEAD
		*len += 1;
=======
		*len =+ 1;
>>>>>>> ae578e4 (updated task 0 to meet the outcome of task 2)
		num = -n;
	}
	else
	{
		num = n;
	}
<<<<<<< HEAD

	if (num / 10)
		print_number(num / 10, len);

	_putchar((num % 10) + '0');
	*len += 1;
}
=======
	if (num / 10)
		print_number(num / 10, len);
	_putchar((num % 10) + '0');
	*len += 1;
}
/**
 * print_binary - print an unsigned int in binary
 * @n: the unsigned int to print
 * @len: pointer to length
 */
void print_binary(unsigned int n, int *len)
{
	if (n / 2)
		print_binary(n / 2, len);
	_putchar((n % 2) + '0');
	*len += 1;
}
/**
 * main - function main
 */
int main(void)
{
	return (0);
}
>>>>>>> ae578e4 (updated task 0 to meet the outcome of task 2)
