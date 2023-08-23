#include "shell.h"

/**
 * builtins - implement the exit and printenv builtins
 * @line: buffer
 * @args: parsed arguments
 * @env: environment
 * @ex_st: exit status
 * Return: Null
 */

void builtins(char *line, char **args, char **env, int *ex_st)
{

	if (_strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(line);
		exit(*ex_st);
	}

	if (_strcmp(args[0], "env") == 0)
		printenv(env, ex_st);
}
