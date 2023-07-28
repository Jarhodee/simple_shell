#include "kdshell.h"

/**
 **_strncpy - The function that copies a string
 *@dest: the destination string to be copied to
 *@src: the source of the string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, c;
	char *s = dent;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dent[i] = src[i];
		i++;
	}
	if (i < n)
	{
		c = i;
		while (c < n)
		{
			dent[c] = '\0';
			c++;
		}
	}
	return (s);
}

/**
 **_strncat - The function that concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dent, char *src, int n)
{
	int h, j;
	char *s = dent;

	h = 0;
	j = 0;
	while (dent[h] != '\0')
		h++;
	while (src[j] != '\0' && j < n)
	{
		dent[h] = src[j];
		h++;
		j++;
	}
	if (j < n)
		dent[h] = '\0';
	return (s);
}

/**
 **_strchr - This locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char a)
{
	do {
		if (*s == a)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
