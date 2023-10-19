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

/**
 * print_number - print an integer
 * @n: the int to print
 * @len: pointer to length
 */
void print_number(int n, int *len)
{
    unsigned int num;

    if (n < 0)
    {
        _putchar('-');
        *len += 1;
        num = -n;
    }
    else
    {
        num = n;
    }
    if (num / 10)
        print_number(num / 10, len);
    _putchar((num % 10) + '0');
    *len += 1;
}
/**
 * main - main function
 */
int main(void)
{
	return (0);
}
