#include "shell.h"

/**
 * _myenv - shows the current working environ
 * @info: Structure contains arguments. Used to maintain
 *          function prototype constant.
 * Return: return 0 always
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - collects the value of an environ var
 * @info: the structure contains arguments. Used to maintain
 * @name: env var name
 *
 * Return: return value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *t;

	while (node)
	{
		t = starts_with(node->str, name);
		if (t && *t)
			return (t);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Int a new environ var,
 *             or edits existing ones
 * @info: the structure contains arguments. Used to maintain
 *        function prototype constant.
 *  Return: return 0 always
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - deletes an environ var
 * @info: the structure contain arguments. Used to maintain
 *        function prototype constant
 * Return: return 0 always
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - To populate environ linked list
 * @info: the structure contains arguments. Used to maintain
 *          function prototype constant
 * Return: Return 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
