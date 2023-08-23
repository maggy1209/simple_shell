#include "shell.h"

/**
 * printenv - prints environment variable
 * @env: environment variable
 * @ex_st: axit status
 *
 * Return: always 0 for success
 */
int printenv(char **env, int *ex_st)
{
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		print_str(env[i]);
		_putchar('\n');
		i++;
	}
	*ex_st = 0;

	return (EXIT_SUCCESS);
}
