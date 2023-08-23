#include "shell.h"

/**
 * free_grid - frees a 2 dimensional grid for pointers
 * @grid: char double pointer to be freed
 * @height: height of the 2D array to be passed
 * Return: void
 */

void free_grid(char **grid, int height)
{
	int k;

	for (k = 0; k < height; k++)
		free(grid[k]);

	free(grid);
}

/**
 * no_nl - removes new line with NULL
 * @l: line to be removed
 * Return: void
 */
void no_nl(char *l)
{
	int i = 0;

	while (l[i])
	{
		if (l[i] == '\n')
		{
			l[i] = '\0';
			return;
		}
		i++;
	}
}

/**
 * special_char - ctrl D exits the shell
 *                handles TAB pressing error
 * @bytes: number of bytes read from input
 * @buffer: the buffer
 * @ex_st: exit status
 *
 * Return: always (0) for success
 */
int special_char(char *buffer, ssize_t bytes, int *ex_st)
{
	int i = 0;

	if (bytes == EOF && isatty(STDIN_FILENO) == 1)
	{
		_putchar('\n');
		free(buffer);
		exit(*ex_st);
	}

	if (bytes == EOF && isatty(STDIN_FILENO) == 0)
	{
		free(buffer);
		exit(*ex_st);
	}

	if (_strcmp(buffer, "\n") == 0)
	{
		*ex_st = 0;
		return (127);
	}

	while (buffer[i] != '\n')
	{
		if (buffer[i] != ' ' && buffer[i] != '\t')
			return (0);

		++i;
	}

	*ex_st = 0;
	return (127);
}
