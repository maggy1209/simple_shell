#include "shell.h"
/**
 * _memset - function of the constant byte filling
 * @s: the address pointer
 * @b: the filling pointer
 * @n: total bytes
 * Return: return a pointer to the memory area on success
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int k;

	for (k = 0; k < n; k++)
		s[k] = b;
	return (s);
}

/**
 * ffree - function to free string
 * @pp: the str
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
/**
 * _realloc - function to reallocate block memory
 * @ptr: previous malloc'ated block pointer
 * @old_size: previous block byte size
 * @new_size: new block bytesize
 * Return: return pointer to the block on success
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
