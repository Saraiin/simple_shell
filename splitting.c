#include "shel.h"

char **splitline(char *line, char *linecpy)
{
	char *token = NULL;
	int i, num_Tokens = 0;
	const char *separator = " \n";
	char **args;

	num_Tokens = numberOfToken(line);
	args = malloc(sizeof(char *) * num_Tokens);
	if (args == NULL)
	{
		free(linecpy);
		return (NULL);
	}
	token = strtok(linecpy, separator);
	for (i = 0; token != NULL; i++)
	{
		args[i] = malloc(sizeof(char) * str_len(token));
		args[i] = str_dup(token);
		token = strtok(NULL, separator);
	}
	args[i] = NULL;
	free(linecpy);
	return (args);
}