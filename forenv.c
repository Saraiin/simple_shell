#include "shell.h"
/**
 * _getenv - gets an environment variable
 * @name: the environment variable name
 * @e: an array of environment variables
 * Return: the environment variable value
 */

char *_getenv(const char *name, char **e)
{
	char *variable, *token, *path;
	char **envp = e;

	while (*envp)
	{
		variable = malloc(sizeof(char) * (str_len(*envp) + 1));
		if (variable == NULL)
			return (NULL);
		str_cpy(variable, *envp);
		token = strtok(variable, "=");
		if (token != NULL && str_cmp(token, name) == 0)
		{
			token = strtok(NULL, "\0");
			path = malloc(sizeof(char) * (str_len(token) + 1));
			if (path == NULL)
				return (NULL);
			str_cpy(path, token);
			free(variable);
			return (path);
		}
		envp++;
		free(variable);
	}
	return (NULL);
}

