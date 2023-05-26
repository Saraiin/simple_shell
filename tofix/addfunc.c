#include "shel.h"
/**
 * checksprt - check if character is separator
 * @a: character
 * @s: string of delimiter
 * Return: 1 (success), 0 fails
 */
int checksprt(char a, const char *s)
{
	int k = 0;

	while (s[k])
	{
		if (s[k] == a)
			return (1);
		k++;
	}
	return (0);
}
/**
 * freeit - free an array of string
 * @ar: an array of strings
 */

void freeit(char **ar)
{
	int i = 0;

	while (ar[i] != NULL)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}
/**
 * freelist - free an array of string
 * @ar: the giving array to be freed
 * @i: the last index of the array
 */
void freelist(char **ar, int i)
{
	while (i > 0)
		free(ar[--i]);
	free(ar);
}

/**
 * prtsignal - prints a new line when a signal SIGINT is sent
 * @sg: the sent signal
 */

void prtsignal(int sg)
{
	if (sg == SIGINT)
		write(STDIN_FILENO, "\n$ ", 3);
}
/**
 * getArlen - get length of array of pointers
 * @args: pointer of pointer to arguments
 * Return: number of args
 */
int getArlen(char **args)
{
        int n = 0;

        while (args)
        {
                n++;
                args++;
        }
        return (n);
}
/**
 * exitcmd - exit command
 * @status: exit status
 * @av: array of arguments
 * @line: line
 * @c: command
 */
void exitcmd(int status, char **av, char *line, char **c)
{
        freeit(av);
        free(line);
        freeit(c);
        if (status == 200)
                exit(0);
        exit(status);
}
