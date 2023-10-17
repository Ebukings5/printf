#include "main.h"

/**
 * buffer_print - helper function to print the buffer
 * @buffer: the buffer to print
 * @buff_ind: a pointer to the buffer index
 */
void buffer_print(char buffer[], int *buff_ind) {
    write(1, buffer, *buff_ind);
    *buff_ind = 0;
}

/**
 * _printf - function that produces output according to a format
 * @format: argument output
 * ...: variable argument continuation
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    int i;
    va_list args_statement;
    int buff_ind = 0;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(args_statement, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
	{
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                buffer_print(buffer, &buff_ind);
            count++;
        }
	else
	{
            if (format[i + 1] == 'c')
	    {
                char c = va_arg(args_statement, int);
                buffer[buff_ind++] = c;
                if (buff_ind == BUFF_SIZE)
                    buffer_print(buffer, &buff_ind);
                count++;
                i++;
            }
        }
    }
    buffer_print(buffer, &buff_ind);
    va_end(args_statement);
    return (count);
}
