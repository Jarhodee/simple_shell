#include "shell.h"

char *_strcpy(char *dest, char *src)
{
	int ix = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[ix])
	{
		dest[ix] = src[ix];
		ix++;
	}
	dest[ix] = 0;
	return (dest);
}

char *_strdup(const char *str)
{
	int width = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		width++;
	ret = malloc(sizeof(char) * (width + 1));
	if (!ret)
		return (NULL);
	for (width++; width--;)
		ret[width] = *--str;
	return (ret);
}

void _puts(char *str)
{
	int ix = 0;

	if (!str)
		return;
	while (str[ix] != '\0')
	{
		_putchar(str[ix]);
		ix++;
	}
}

int _putchar(char c)
{
	static int ix;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || ix >= WRITE_BUF_SIZE)
	{
		write(1, buf, ix);
		ix = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}


