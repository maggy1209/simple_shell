#include "shell.h"

/**
 * _erratoi - changes a string to integer
 * @m: string to convert
 * Return: 1 for no numbers in string
 */

int _erratoi(char *m)
{
	int k = 0;
	unsigned long int result = 0;

	if (*m == '+')
		m++;  /* TODO: why does this make main return 255? */
	for (k = 0;  m[k] != '\0'; k++)
	{
		if (m[k] >= '0' && m[k] <= '9')
		{
			result *= 10;
			result += (m[k] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - displays an error ms
 * @info: parameter & return info struct
 * @estr: the string which contains a specific type of error
 * Return: 0 if string has no number
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
 * print_d - displays a decimal integer (base 10)
 * @input:  input
 * @fd: filedescriptor to write to
 * Return: total number of chars printed
 */

int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int k, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (k = 1000000000; k > 1; k /= 10)
	{
		if (_abs_ / k)
		{
			__putchar('0' + current / k);
			count++;
		}
		current %= k;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - a converter func, a replica of itoa
 * @num: the number
 * @base: the base
 * @flags: the argument flags
 * Return: the string
 */

char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - func changes first instance of '#' with '\0'
 * @buf: the address of string to edit
 * Return: 0
 */

void remove_comments(char *buf)
{
	int k;

	for (k = 0; buf[k] != '\0'; k++)
		if (buf[k] == '#' && (!k || buf[k - 1] == ' '))
		{
			buf[k] = '\0';
			break;
		}
}
