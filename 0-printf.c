#include "main.h"

int _printf(const char *format, ...);

/**
 * _putchar - Placeholder for your character output function.
 * You should implement this function.
 */
void _putchar(char c)
{
    putchar(c);
}

/**
 * print_number - print an integer as unsigned decimal
 * @n: the int to print
 * @len: pointer to length
 */
void print_number(unsigned int n, int *len)
{
    if (n / 10)
        print_number(n / 10, len);
    _putchar((n % 10) + '0');
    *len += 1;
}

int _printf(const char *format, ...)
{
    int string_len = 0;
    va_list args;

    va_start(args, format);
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
                    _putchar(va_arg(args, int));
                    string_len++;
                    break;

                case 's':
                     print_string(va_arg(args, const char *), &string_len);
                    break;

                case '%':
                    _putchar('%');
                    string_len++;
                    break;

                case 'd':
                case 'i':
                    print_number(va_arg(args, int), &string_len);
                    break;

		case 'b':
		     print_binary(va_arg(args, unsigned int), &string_len);
                     break;

                case 'u':
                case 'o':
                case 'x':
                case 'X':
                    print_number(va_arg(args, unsigned int), &string_len);
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
    return string_len;
}
