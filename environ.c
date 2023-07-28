#include "shell.h"

/**
 * _myenv - pThe function taht prints the current environment
 * @info: The structure containing potential arguments used to maintain
 * constant function prototype.
 * Return: Alway return 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - this function gets the value of an environ variable
 * @info: The structure containing potential arguments used in maintaining
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - The function that initializes a new environment variable,
 * or modify an existing one
 * @info: The structure containing potential arguments used in maintaining
 * constant function prototype.
 *  Return: Always return 0
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
 * _myunsetenv - The function that removes an environment variable
 * @info: The structure containing potential arguments used to maintain
 * constant function prototype.
 * Return: Alway return 0
 */
int _myunsetenv(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		_unsetenv(info, info->argv[j]);

	return (0);
}

/**
 * populate_env_list - The function that populates env linked list
 * @info: The structure containing potential arguments used to maintain
 * constant function prototype.
 * Return: Always return 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
	add_node_end(&node, environ[a], 0);
	info->env = node;
	return (0);
}
