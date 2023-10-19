#include "shell.h"

/**
 * Auth: Alice Agyemang
 *   Benjamin Kwame Oduro
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 * -1 on error
 */
int _erratoi(char *s)
{
int i = 0;
long result = 0;

if (*s == '+')
s++;

for (i = 0; s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
result *= 10;
result += (s[i] - '0');
if (result > INT_MAX || result < INT_MIN)
return (-1);
}
else
return (-1);
}

return ((int)result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 *
 * Return: void
 */
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
int count = 0;
unsigned int abs_input = (input < 0) ? -input : input;

if (input < 0)
{
_putfd('-', fd);
count++;
}

if (abs_input == 0)
{
_putfd('0', fd);
count++;
}
else
{
char buffer[20];
int i = 0;

while (abs_input > 0)
{
buffer[i++] = (abs_input % 10) + '0';
abs_input /= 10;
}

for (i--; i >= 0; i--)
{
_putfd(buffer[i], fd);
count++;
}
}

return (count);
}

/**
 * convert_number - converter function to convert a number to a string
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
static char buffer[50];
char *ptr = &buffer[49];
char array[] =
	(flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
unsigned long n = (num < 0 && !(flags & CONVERT_UNSIGNED)) ? -num : num;
char sign = (num < 0 && !(flags & CONVERT_UNSIGNED)) ? '-' : '\0';

*ptr = '\0';

do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;

return (ptr);
}

/**
 * remove_comments - replaces the first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: void
 */
void remove_comments(char *buf)
{
for (int i = 0; buf[i] != '\0'; i++)
{
if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
{
buf[i] = '\0';
break;
}
}
}
