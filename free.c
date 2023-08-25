#include "shell.h"
/**
 * bfree - function to free pointer
 * @ptr: the pointers address
 * Return: return 1 on success, 0 on failure
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
