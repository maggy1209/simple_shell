#include "shell.h"
/**
 * list_len - function that finds the linked list len
 * @h: header node pointer
 * Return: return the length of the linked list on success
 */

size_t list_len(const list_t *h)
{
	size_t k = 0;

	while (h)
	{
		h = h->next;
		k++;
	}
	return (k);
}
/**
 * print_list - function that outputs elements of the linked list
 * @h: header node pointer
 * Return: return the length of linked list on successdul execution
 */

size_t print_list(const list_t *h)
{
	size_t k = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		k++;
	}
	return (k);
}
/**
 * list_to_strings - function that outputs array of strings
 * @head: header node pointer
 * Return: return an array of strings on success
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t k = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !k)
		return (NULL);
	strs = malloc(sizeof(char *) * (k + 1));
	if (!strs)
		return (NULL);
	for (k = 0; node; node = node->next, k++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < k; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[k] = str;
	}
	strs[k] = NULL;
	return (strs);
}
/**
 * get_node_index - function to output the node index
 * @head: header pointer
 * @node: node pointer
 * Return: return 0 on success
 **/

size_t get_node_index(list_t *head, list_t *node)
{
	size_t k = 0;

	while (head)
	{
		if (head == node)
			return (k);
		head = head->next;
		k++;
	}
	return (-1);
}
/**
 * node_starts_with - function to print a node with a prefix
 * @node: header pinter
 * @prefix: the match string
 * @c: after preffix character match
 * Return: return 0 on success
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
