#include "shel.h"
/**
 * get_env - get environnment variable
 * @envname: name of the environnement variable
 * Return: environnment variable value
 */
char *get_env(const char *envname)
{
	char **var;
	char **envp = environ;

	while (envp != NULL)
	{
		var = strtok(*envp, "=");
	if (var)
	{
		if (str_cmp(*var, envname) == 0)
			return (*(var + 1));
	}
	free(var);
	envp++;
	}
	free(envp);
	return (NULL);
}
/**
 * get_envar - get env variable
 * @envname: env variable's name
 * @arenv: array of environnement variable
 * Return: environnement variable value
 */
char *get_envar(const char *envname, char **arenv)
{
	char **envp = arenv;
	char *var;
	char *token;

	while (envp != NULL)
	{
		var = str_dup(*envp);
		if (!var)
			return (NULL);
		token = strtok(var, "=");
		if (token)
		{
			if (str_cmp(token, envname) == 0)
				return (strtok(NULL, "\0"));
		}
		envp++;
		free(var);
	}
	free(envp);
	return (NULL);
}
/**
 * callMyFunc - call the function needed
 * @command: command
 * Return: the function needed
 */
int (*callMyFunc(char *command))(int ac, char **args, char ***env, int status)
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
		return (cmd);
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
int exectcmd(int ac, char **av, char ***envpt, int status)
{
	int st;
	int (*myfunc)(int ac, char **args, char ***envpt, int st);
	pid_t pid;
	char *cmd = NULL, *envpath = NULL;
envpath = get_envar("PATH", *envpt);
	if (av != NULL)
	{
		myfunc = callMyFunc(av[1]);
		if (myfunc != NULL)
			return (myfunc(ac, av, envpt, status));
		cmd = getPath(av[1], envpath);
		if (cmd != NULL)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("ERROR : fork");
				return (1);
			}
			if (pid == 0)
			{
				if (execve(cmd, av + 1, *envpt) == -1)
				{
					free(cmd);
					perror("ERROR : execve");
					exit(errno);
				}
			}
			wait(&st);
			free(cmd);
			return (WEXITSTATUS(st));
		}
		else
		{
			write(STDERR_FILENO, "command not found", 17);
			return (127);
		}
	}
	return (0);
}
