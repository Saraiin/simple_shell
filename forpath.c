#include "shell.h"
/**
 * creatPath - build the command path
 * @dirPath: the giving directory path
 * @cmd: the giving command
 * @path: the command path
 */

void creatPath(char *dirPath, char *cmd, char *path)
{
	str_cpy(path, dirPath);
	str_cat(path, "/");
	str_cat(path, cmd);
	str_cat(path, "\0");
}
/**
 * _which - locate a command
 * @cmd: the giving command
 * @envPath: the value of PATH environnement variable
 * Return: the path of the command or NULL if that not exists
 */

char *showpath(char *cmd, char *envPath)
{
	char *path, *token = NULL, *copyPath;
	struct stat st;

	if (stat(cmd, &st) == 0)
	{
		path = malloc(sizeof(char) * (str_len(cmd) + 1));
		str_cpy(path, cmd);
		return (path);
	}
	copyPath = malloc(sizeof(char) * (str_len(envPath) + 1));
	if (!copyPath)
		return (NULL);
	str_cpy(copyPath, envPath);
	/* store the dir path in an array */
	token = strtok(copyPath, ":");
	while (token)
	{
		path = malloc(sizeof(char) * (str_len(token) +
					str_len(cmd) + 2));
		if (!path)
		{
			perror("malloc");
			free(copyPath);
			return (NULL);
		}
		creatPath(token, cmd, path);
		if (stat(path, &st) == 0)
		{
			free(copyPath);
			return (path);
		}
		token = strtok(NULL, ":");
		free(path);
	}
	free(copyPath);
	return (NULL);
}
