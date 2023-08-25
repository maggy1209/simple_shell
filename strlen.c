#include "shell.h"
/**
 * _strlen - function to find the str length
 * @s: str to be checked
 * Return: the strlength on success
 */

int _strlen(char *s)
{
	int k = 0;

	if (!s)
		return (0);

	while (*s++)
		k++;
	return (k);
}
/**
 * _strcmp - function to compare strs.
 * @s1: str1
 * @s2: str2
 * Return: 0 on success
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * starts_with - function to determine a haystack at the starting
 * @haystack: searched string
 * @needle: str1
 * Return: 0 on success
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * _strcat - function to string concatenates
 * @dest: buffer end
 * @src: buffer start
 * Return: 0 on success
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
