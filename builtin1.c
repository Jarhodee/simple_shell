#include "kdshell.h"

/**
 * _myhistory - The function that displays the history list, one command by line, preceded
 * with line numbers, starting at 0.
 * @info: The structure containing potential arguments used to maintain
 * constant function prototype.
 * Return: Alway return 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - This function sets alias to string
 * @info: the parameter struct
 * @str: string alias
 *
 * Return: Return 0 Always on success, and 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, b;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	b = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
	get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = b;
	return (ret);
}

/**
 * set_alias - The function that sets alias to string
 * @info: The parameter struct
 * @str: string alias
 *
 * Return: Alway return 0 on success, and 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - The function that prints an alias string
 * @node: alias node
 *
 * Return: Always return 0 on success, and 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - This function mimics the alias builtin (man alias)
 * @info: the structure containing potential arguments used in maintaining
 * constant function prototype.
 *  Return: Alway return 0
 */
int _myalias(info_t *info)
{
	int j = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (j = 1; info->argv[j]; j++)
	{
		p = _strchr(info->argv[j], '=');
		if (p)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[j], '='));
	}

	return (0);
}
