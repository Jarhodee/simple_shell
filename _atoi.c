#include "shell.h"

/**
 * interactive - if shell is in intaractive mode return true.
 * @info: address struct
 *
 * Return: if shell is in interactive mode return 1, otherwise 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - this function checks if character is a delimeter
 * @c: checks the char
 * @delim: the string of the delimeter
 * Return: return 1 if true, if false return 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - this function checks for alphabetic character
 * @c: The character to be inputed
 * Return: 1 will be returned if c is alphabetic, otherwise return 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - this function converts a string to an integer
 * @s: the string to be converted
 * Return: return 0 if no numbers in string, convert number otherwise
 */

int _atoi(char *s)
{
	int j, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (j = 0; s[j] != '\0' && flag != 2; j++)
	{
		if (s[j] == '-')
			sign *= -1;

		if (s[j] >= '0' && s[j] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
