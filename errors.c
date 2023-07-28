#include "kdshell.h"

/**
 * _eputs - This prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_eputchar(str[a]);
		a++;
	}
}

/**
 * _eputchar - This function writes the character c to stderr
 * @c: The character to be printed
 *
 * Return: On success return 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char f)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (f == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (f != BUF_FLUSH)
		buf[i++] = f;
	return (1);
}

/**
 * _putfd - This writes the character c to given fd
 * @c: The character to be print
 * @fd: The filedescriptor to be writen to
 *
 * Return: On success return 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char b, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (b == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (b != BUF_FLUSH)
		buf[j++] = b;
	return (1);
}

/**
 * _putsfd - This prints an input to string
 * @str: the string to be printed
 * @fd: the filedescriptor to be writen to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += _putfd(*str++, fd);
	}
	return (j);
}
