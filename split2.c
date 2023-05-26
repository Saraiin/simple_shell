#include "shell.h"
/**
 * parseAllcmd - parse line with ;
 * @lineptr: the giving string
 * Return: an array of pointers or NULL
 */
char **parseAllcmd(char *lineptr)
{
	char *copyline, *token = NULL;
	int nbrTokens = 0, i = 0, j;
	const char *delim = ";";
	char **cmds;

	ignore_comments(lineptr);
	copyline = malloc(sizeof(char) * (str_len(lineptr) + 1));
	if (!copyline)
		return (NULL);
	str_cpy(copyline, lineptr);
	nbrTokens = count_token(copyline, delim);
	cmds = malloc(sizeof(char *) * (nbrTokens + 1));
	if (!cmds)
		return (NULL);
	token = strtok(lineptr, delim);
	for (i = 0; token != NULL; i++)
	{
		cmds[i] = malloc(sizeof(char) * (str_len(token) + 1));
		if (cmds[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(cmds[j]);
			free(cmds);
			free(copyline);
			return (NULL);
		}
		str_cpy(cmds[i], token);
		token = strtok(NULL, delim);
	}
	cmds[i] = NULL;
	free(copyline);
	return (cmds);
}
