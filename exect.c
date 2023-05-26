#include "shell.h"
/**
 * execmd - executes the giving command
 * @exe: executable name
 * @av: an array of arguments
 * @e: an array of environement variables
 * Return: status code
 */

int execut(char *exe, char **av, char **e)
{
	pid_t child;
	int st;
	char *path, *cmd;

	if (av)
	{
		path = _getenv("PATH", e);
		cmd = showpath(av[0], path);
		if (cmd)
		{
			child = fork();
			if (child == -1)
			{
				showerror(exe, "Fork fails");
				return (1);
			}
			else if (child == 0)
			{
				if (execve(cmd, av, e) == -1)
				{
					perror(exe);
					exit(errno);
				}
			}
			wait(&st);
			free(path);
			free(cmd);
			return (WEXITSTATUS(st));
		}
		free(path);
		free(cmd);
		return (notfound(exe, av));
	}
	return (0);
}
