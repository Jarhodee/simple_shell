#include "kdshell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 * */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t jk = *p;

	if (buf[jk] == '|' && buf[jk + 1] == '|')
	{
		buf[jk] = 0;
		jk++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[jk] == '&' && buf[jk + 1] == '&')
	{
		buf[jk] = 0;
		jk++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[jk] == ';') /* found end of this command */
	{
		buf[jk] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = jk;
	return (1);
}

void check_chain(info_t *info, char *buf, size_t *p, size_t ix, size_t len)
{
	size_t jk = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[ix] = 0;
			jk = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[ix] = 0;
			jk = len;
		}
	}

	*p = jk;
}

int replace_alias(info_t *info)
{
	int ix;
	list_t *node;
	char *p;

	for (ix = 0; ix < 10; ix++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

int replace_vars(info_t *info)
{
	int ix = 0;
	list_t *node;

	for (ix = 0; info->argv[ix]; ix++)
	{
		if (info->argv[ix][0] != '$' || !info->argv[ix][1])
			continue;

		if (!_strcmp(info->argv[ix], "$?"))
		{
				replace_string(&(info->argv[ix]),
						_strdup(convert_number(info->status, 10, 0)));
				continue;
		}
		if (!_strcmp(info->argv[ix], "$$"))
		{
			replace_string(&(info->argv[ix]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[ix][1], '=');
		if (node)
		{
			replace_string(&(info->argv[ix]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[ix], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 * */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}




