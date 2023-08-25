#include "shell.h"

/**
 * get_environ - set to eturns the string array copy of our environ
 * @info: the structure contains arguments
 * Return: Always 0
 */

char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - delete an environ var
 * @info: the structure contains arguments
 *  Return: 1 if deleted, 0 if not
 * @var: string environ variable property
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t j = 0;
	char *k;

	if (!node || !var)
		return (0);

	while (node)
	{
		k = starts_with(node->str, var);
		if (k && *k == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), j);
			j = 0;
			node = info->env;
			continue;
		}
		node = node->next;
	j++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Set to initialize a new environ var
 * @info: the structure contains argument
 * @var: string environ variable property
 * @value: string environ variable value
 *  Return: Always 0
 */

int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *f;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		f = starts_with(node->str, var);
		if (f && *f == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
