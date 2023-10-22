#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int _printf(const char *format, ...);
void _putchar(char c);
void print_number(unsigned int n, int *len);
void print_binary(unsigned int n, int *len);
void print_string(const char *str, int *len);

#endif
