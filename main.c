#include "shell.h"
/**
 * main - main function of the program
 * @ac: the counter to the argument
 * @av: the vector to the argument
 * Return: return 0 on success or 1 if an error
 */

int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int k = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (k)
			: "r" (k));

	if (ac == 2)
	{
		k = open(av[1], O_RDONLY);
		if (k == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = k;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
