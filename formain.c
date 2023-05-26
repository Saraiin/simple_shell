#include "shell.h"
/**
 * prmp - prints the prompt string
 */
void prmp(void)
{
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "$ ", 2);
}
/**
 * signee - prints a new line when a signal SIGINT is sent
 * @signal: the sent signal
 */

void signee(int signal)
{
	if (signal == SIGINT)
		write(STDIN_FILENO, "\n$ ", 3);
}


/**
 * callMyfunc - get build in function
 * @c: the giving command
 * Return: the associated function
 */

int (*callMyfunc(char *c))(char *x, int n, char **a, char **e, int s)
{
	buildin_t b[] = {
		{"exit", exitit},
		{"env", showenv},
		{NULL, NULL}
	};
	int i;

	i = 0;

	while (i < 2)
	{
		if (!str_cmp(b[i].cmd, c))
			return (b[i].func);
		i++;
	}
	return (NULL);
}
