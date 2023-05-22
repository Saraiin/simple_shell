#include "shel.h"
char getPath(char *cmd)
{
	char *path, *pathcpy, tokens;
	int len_cmd, len_path;
	struct stat buff;

	if (stat(cmd, &buff) == 0)
		return (cmd);
	pathcpy = str_dup(pathenv);
	if (pathcpy == NULL)
		return (NULL);
	len_cmd = str_len(cmd);
	tokens = strtok(pathcpy, ":");
	while (tokens != NULL)
	{
		path_len = str_len(tokens);
		path = malloc(len_cmd + path_len + 2);
		if (!path)
		{
			perror("malloc path");
			free(tokens);
			return (NULL);
		}
		str_cpy(path, tokens);
		str_cat(path, "/");
		str_cat(path, cmd);
		str_cat(path, "\0");
		if (stat(path, &buff) == 0)
			return (path);
		tokens = strtok(NULL, ":");
	}
	free(pathcpy);
	free(token);
	return (NULL);

}
/*
 *
 */
void exectcmd(char **args)
{
	char *cmd = NULL;
	char *cmdpath = NULL;
	int test;
	if (args != NULL)
	{
		cmd = args[0];
		cmdpath = getPath(cmd);
		test = execve(cmdpath, args, NULL);
		if (test == -1)
			perror("Error path");
	}
}
