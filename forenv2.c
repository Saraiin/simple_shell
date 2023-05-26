#include "shell.h"
/**
 * showenv - print environment variables
 * @exe: executable name
 * @ac: number of arguments
 * @as: a pointer of pointers to arguments
 * @e: a pointer of environment variables
 * @s: the status of the previous command
 * Return: 0 success
 */

int showenv(char *exe, int ac, char **as, char **e, int s)
{
	char **envp = e;

	(void)as;
	(void)s;
	if (ac > 1)
	{
		showerror(exe, "Usage : env");
		return (1);
	}
	while (*envp)
	{
		write(STDOUT_FILENO, *envp, str_len(*envp));
		write(STDOUT_FILENO, "\n", 1);
		envp++;
	}
	return (0);
}

