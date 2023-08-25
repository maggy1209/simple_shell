#include "shell.h"

/**
 **_strncpy - clones string
 *@dest: the string to be copied to
 *@src: source string
 *@n: total number of chars copied
 *Return: concatenated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int k, j;
	char *s = dest;

	k = 0;
	while (src[k] != '\0' && k < n - 1)
	{
		dest[k] = src[k];
		k++;
	}
	if (k < n)
	{
		j = k;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - to concatenate two strings
 *@dest: First string
 *@src: Second string
 *@n: maximum number of bytes to use
 *Return: concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int k, j;
	char *s = dest;

	k = 0;
	j = 0;
	while (dest[k] != '\0')
		k++;
	while (src[j] != '\0' && j < n)
	{
		dest[k] = src[j];
		k++;
		j++;
	}
	if (j < n)
		dest[k] = '\0';
	return (s);
}

/**
 **_strchr - searches for a char in a string
 *@s: string to be parsed
 *@c: char to search for
 *Return: a pointer to the memory area s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
