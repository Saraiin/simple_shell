#include "shel.h"
/**
 * get_env - get environnment variable
 * @envname: name of the environnement variable
 * @arenv: arrat of environnemet variable
 * Return: environnment variable value
 */
char *get_env(const char *envname, char **arenv)
{
	char **envpt = arenv;
	char *var, *tokens = NULL, *path;

	while (*envpt)
	{
		var = malloc(sizeof(char) * (str_len(*envpt) + 1));
		if (var == NULL)
			return (NULL);
		str_cpy(var, *envpt);
		tokens = strtok(var, "=");
		if (tokens != NULL && str_cmp(tokens, envname) == 0)
		{
			tokens = strtok(NULL, "\0");
			path = malloc(sizeof(char) * (str_len(tokens) + 1));
			if (path == NULL)
				return (NULL);
			str_cpy(path, tokens);
			free(var);
			return (path);
		}
		envpt++;
		free(var);
	}
	return (NULL);
}
/**
 * callMyFunc - call the function needed
 * @command: command
 * Return: the function needed
 */
int (*callMyFunc(char *cd))(char *x, int nb, char **args, char **env, int s)
{
	int i = 0;
	funcbuild_t b[] = {
		{"exit", exitt},
		{"env", printenv},
		{NULL, NULL}
	};
	while (i < 2)
	{
		if (!str_cmp(b[i].cmd, cd))
			return (b[i].func);
		i++;
	}
	return (NULL);
}


/**
 * getPath - give path of giving command
 * @cmd: command
 * @pathenv: value of path environnement variable
 * Return: path of command or null
 */
char *getPath(char *cmd, char *pathenv)
{
	char *path, *pathcpy, *tokens = NULL;
	struct stat buff;

	if (stat(cmd, &buff) == 0)
	{
		path = malloc(sizeof(char) * (str_len(cmd) + 1));
		str_cpy(path, cmd);
		return (path);
	}
	pathcpy = malloc(sizeof(char) * (str_len(pathenv) + 1));
	if (pathcpy == NULL)
		return (NULL);
	str_cpy(pathcpy, pathenv);
	tokens = strtok(pathcpy, ":");
	while (tokens != NULL)
	{
		path = malloc(sizeof(char) * (str_len(tokens) + str_len(cmd) + 2));
		if (!path)
		{
			perror("malloc path");
			free(pathcpy);
			return (NULL);
		}
		str_cpy(path, tokens);
		str_cat(path, "/");
		str_cat(path, cmd);
		str_cat(path, "\0");
		if (stat(path, &buff) == 0)
		{
			free(pathcpy);
			return (path);
		}
		tokens = strtok(NULL, ":");
		free(path);
	}
	free(pathcpy);
	return (NULL);

}
/**
 * exectcmd - execute the command²
 * @av: array of args
 * @envpt: array of environnemet variable
 * @xe: name of executable
 * Return: status
 */
int exectcmd(char *xe, char **av, char **envpt)
{
	int status;
	pid_t pidChild;
	char *command = NULL, *envpath = NULL;

	if (av != NULL)
	{
		envpath = get_env("PATH", envpt);
		command = getPath(av[0], envpath);
		if (command != NULL)
		{
			pidChild = fork();
			if (pidChild == -1)
			{
				showerrors(xe, "Fork error");
				return (1);
			}
			else if (pidChild == 0)
			{
				if (execve(command, av, envpt) == -1)
				{
					perror(xe);
					exit(errno);
				}
			}
			wait(&status);
			free(envpath);
			free(command);
			return (WEXITSTATUS(status));
		}
		free(envpath);
		free(command);
		return (cmdnotfound(xe, av));
	}
	return (0);
}
