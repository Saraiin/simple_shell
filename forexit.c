#include "shell.h"
/**
 * cmdexit - launch exit command
 * @status: the exit status
 * @av: an array of arguments
 * @cmd: an array of commands
 * @line: the line
 */

void cmdexit(int status, char **av, char *line, char **cmd)
{
	free_args(av);
	free(line);
	free_args(cmd);
	if (status == 200)
		exit(0);
	exit(status);
}

/**
 * exitit - exit the current process
 * @exe: executable name
 * @ac: number of arguments
 * @as: a pointer of pointers to arguments
 * @e: a pointer of environment variables
 * @s: the status of the previous command
 * Return: 0 success
 */
int exitit(char *exe, int ac, char **as, char **e, int s)
{
	int status = 200, i;
	char *error;

	(void)e;
	if (ac > 2)
	{
		showerror(exe, "Usage: exit status");
		return (1);
	}
	if (as[1] != NULL)
	{
		for (i = 0; as[1][i] != '\0'; i++)
		{
			if (i == 0 && as[1][i] == '-')
				continue;
			if (!is_digit(as[1][i]))
			{
				error = malloc(sizeof(char) * (str_len(as[1]) + 35));
				str_cpy(error, "exit: ");
				str_cat(error, as[1]);
				str_cat(error, ": numeric argument required");
				showerror(exe, error);
				free(error);
				return (2);
			}
		}
		status = atoii(as[1]);
	}
	else if (s != 0)
		status = s;
	return (status);
}

