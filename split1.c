#include "shell.h"
/**
 * parseit - splits line command into arguments
 * @lineptr: the line command
 * @e: an array of environnement variables
 * @s: the previous status
 * Return: a pointer of pointers to arguments
 */
char **parseit(char *lineptr, char **e, int s)
{
	char **av;
	char *token = NULL, *copy;
	int nbrTokens = 0, i = 0, j;
	const char *delim = " \t\n";

	copy = malloc(sizeof(char) * (str_len(lineptr) + 1));
	if (copy == NULL)
		return (NULL);
	str_cpy(copy, lineptr);
	nbrTokens = count_token(copy, delim);
	av = malloc(sizeof(char *) * (nbrTokens + 1));
	if (!av)
		return (NULL);
	token = strtok(lineptr, delim);
	for (i = 0; token; i++)
	{
		av[i] = malloc(sizeof(char) * (str_len(token) + 1));
		if (av[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(av[j]);
			free(av);
			free(copy);
			return (NULL);
		}
		str_cpy(av[i], token);
		token = strtok(NULL, delim);
	}
	av[i] = NULL;
	replacevar(av, e, s);
	free(copy);
	return (av);
}
