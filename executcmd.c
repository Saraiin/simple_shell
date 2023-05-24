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
int (*callMyFunc(char *command))(int *x, int nb, char **args, char **env, int status)
{
	int i = 0;
	funcbuild_t b[] = {
		{"exit", exitt},
		{"env", printenv},
		{NULL, NULL}
	};
	while (i < 4)
	{
		if (!str_cmp(b[i].cmd, command))
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
	int len_cmd, len_path;
	struct stat buff;

	if (stat(cmd, &buff) == 0)
	{
		path = malloc(sizeof(char) * (str_len(cmd) + 1));
		str_cpy(path, cmd);
		return (path);
	}
	pathcpy = str_dup(pathenv);
	if (pathcpy == NULL)
		return (NULL);
	len_cmd = str_len(cmd);
	tokens = strtok(pathcpy, ":");
	while (tokens != NULL)
	{
		len_path = str_len(tokens);
		path = malloc(len_cmd + len_path + 2);
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
	free(tokens);
	return (NULL);

}
/**
 * exectcmd - execute the command
 * @ac: number of arguments
 * @av: array of args
 * @envpt: array of environnemet variable
 * @status: previous status
 * Return: status
 */
int exectcmd(char *xe, char **av, char ***envpt)
{
	int status;
	pid_t pidChild;
	char *command = NULL, *envpath = NULL;

	if (av != NULL)
	{
		path = get_env("PATH", e);
		command = getPath(av[0], path);
		if (cmd != NULL)
		{
			pid = fork();
			if (pidChild == -1)
			{
				perror("ERROR : Failure -> fork");
				return (1);
			}
			if (pid == 0)
			{
				if (execve(command, av, *envpt) == -1)
				{
					perror("ERROR : execve");
					exit(errno);
				}
			}
			wait(&status);
			free(path);
			free(cmd);
			return (WEXITSTATUS(status));
		}
			write(STDERR_FILENO, "command not found", 17);
			return (127);
	}
	return (0);
}
