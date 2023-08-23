#include "shell.h"

/**
 * _execute - executes in the shell
 * @status: the status of the path
 * @args: parsed arguments
 * @ex_st: exit status
 * @tal: tally of commands that were run
 * Return: void
 */

void _execute(int status, char **args, int *ex_st, int *tal)
{
	if (status == 2)
	{
		if (access(args[0], X_OK) == 0)
		{
			if (fork() == 0)
				execve(args[0], args, NULL);

			else
				wait(NULL);
			*ex_st = 0;
		}
		else if (access(args[0], F_OK) != 0)
		{
			print_str("sh: ");
			print_int(tal);
			print_str(": ");
			perror(args[0]);
			*ex_st = 127;
		}
		else if (access(args[0], F_OK) == 0 &&
			 access(args[0], X_OK) != 0)
		{
			print_str("sh: ");
			print_int(tal);
			print_str(": ");
			perror(args[0]);
			*ex_st = 126;
		}
	}

	free(args);
}
