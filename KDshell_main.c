#include "KDshell_main.h"

/**
 * main - build a simple shell that takes in prompts
 * @argc: argument count to be used
 * @argv: argument array to be used
 * Return: 0 on success
 */

int main(int ac, char **argv)

{
	char *prompt = "(KDshell) $ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int token_num = 0;
	char *token;
	int king_size;

	/* the void variables is declared */
	(void)ac;

	/* creating a loop for the shell's prompt */
	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		
		/* checking if the getline function failed or reached EOF or the user used a CTRL + D command*/
		if (nchars_read == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		}

		/* this command allocate some space for a copy of the lineptr */
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		/* copying the lineptr to lineptr_copy */
		strcpy(lineptr_copy, lineptr);

		/********** split the string (lineptr) into an array of words ********/

		/* calculating the total number of tokens */
		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			token_num++;
			token = strtok(NULL, delim);
		}
		token_num++;

		/* allocating space to hold the array of strings */
		argv = malloc(sizeof(char *) * token_num);

		/* storing each token in the argv array */
		token = strtok(lineptr_copy, delim);

		for (king_size = 0; token != NULL; king_size)
		{
			argv[king_size] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[king_size], token);

			token = strtok(NULL, delim);
		}
		argv[king_size] = NULL;

		/* executing the command */
		execmd(argv);
	}

	/* freeing up an allocated memory */
	free(lineptr_copy);
	free(lineptr);

	return (0);
}
