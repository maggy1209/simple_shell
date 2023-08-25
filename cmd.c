#include "shell.h"
/**
 * is_cmd - function to check if a file is executable
 * @info: structure of the information
 * @path: path to the file
 * Return: return 1 on success and 0 if it fails
 */

int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * dup_chars - function to duplicate chars
 * @pathstr: path to string
 * @start: index1
 * @stop: nth index
 * Return: return a pointer on success
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int j = 0, k = 0;

	for (k = 0, j = start; j < stop; j++)
		if (pathstr[j] != ':')
			buf[k++] = pathstr[j];
	buf[k] = 0;
	return (buf);
}
/**
 * find_path - function to check for command
 * @info: structure of the information
 * @pathstr: path to the string
 * @cmd: ommand
 * Return: return the command path on success
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int k = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[k] || pathstr[k] == ':')
		{
			path = dup_chars(pathstr, curr_pos, k);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[k])
				break;
			curr_pos = k;
		}
		k++;
	}
	return (NULL);
}
