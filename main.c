#include "shell.h"

/**
 * main - entry points to the simple version of the shell
 * @argc: nbr of arguments
 * @argv: an array of pointers of arguments
 * Return:0 success
 */


int main(__attribute__((unused)) int argc, char **argv)
{
	ssize_t nbchar = 0;
	size_t n = 0;
	char *lineptr = NULL;
	char **e = environ, **av = NULL, **cmd = NULL;
	int len = 0, status = 0, i;
	int (*f)(char *exe, int ac, char **as, char **e, int st);

	signal(SIGINT, signee);
	while (1)
	{
		prmp();
		nbchar = getline(&lineptr, &n, stdin);
		if (nbchar <= 0)
		{
			free(lineptr);
			exit(0);
		}
		cmd = parseAllcmd(lineptr);
		for (i = 0; cmd[i]; i++)
		{
			av = parseit(cmd[i], e, status);
			len = array_len(av);
			if (len > 0)
			{
				f = callMyfunc(av[0]);
				if (f != NULL)
				{
					status = f(argv[0], len, av, e, status);
					if (status != 0)
						cmdexit(status, av, lineptr, cmd);
				}
				else
					status = execut(argv[0], av, e);
			}
			free_args(av);
		}
		free_args(cmd);

	}
	return (0);
}
