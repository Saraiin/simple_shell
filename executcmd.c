#include "shel.h"
/**
 *
 *
 */
char * get_env(const char *envname)
{
	char **var, **envp = environ;

	while (envp != NULL)
	{
		var = strtok(*envp, "=");
	if (variable)
	{
		if(str_cmp(*var, envname) == 0)
			return (*(var + 1 ));
	}
	free(var);
	envp++;
	}
	free(envp);
	return (NULL);
}
/**
 *
 *
 *
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
			if(str_cmp(token, envname) == 0)
				return (strtok(NULL, "\0"));
		}
		envp++;
		free(var);
	}
	free(envp);
	return (NULL);
}
/**
 *
 *
 */
int (*callMyFunc(char *))(int ac, char **args, char ***env, int status)
{
	int i = 0;
	funcbuild_t b[] = {
		{"exit", exitt},
		{"env", printenv},
		{"cd", cdd},
		{NULL, NULL}
	};
	while (i < 4)
	{
		if (!str_cmp(b[i].cmd, c))
			return (b[i].func);
		i++;
	}
	return (NULL);
}


/**
 *
 *
 * 
 */
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
void exectcmd(int ac, char **av, char ***envpt, int status)
{
	int st;
	int (*myfunc)(int ac, char **args, char ***envpt, int st);
	pid_t pid;
	char *cmd = NULL, *envpath = NULL;
	
	envpath = get_envar("PATH", *envpt)
	if (av != NULL)
	{
		myfunc = callMyFunc(av[1]);
		if (myfunc != NULL)
			return (myfunc(ac, av, envpt, status));
		cmd = getPath(argv[1], envpath);
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
			return (WEEXITSTATUS(st));
		}
		else
		{
			write(STDERR_FILENO, "command not found", 17);
			return (127);
		}
		return (0);
}
