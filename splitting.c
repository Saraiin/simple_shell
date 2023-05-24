#include "shel.h"
/**
 * splitline - split line into argument
 * @line:line to split
 * @linecpy: copy of line
 * Return: array of argument
 */
char **splitline(char *line, char *envpt, int st)
{
	char *token = NULL;
	int i = 0, num_Tokens = 0, k;
	const char *separator = " \t\n";
	char **args, *linecpy;

	linecpy = malloc(sizeof(char) * (str_len(line) + 1));
	if (linecpy == NULL)
		return (NULL);
	strcpy(linecpy, line);
	num_Tokens = numberOfTokens(linecpy, separator);
	args = malloc(sizeof(char *) * (num_Tokens + 1));
	if (args == NULL)
		return (NULL);
	token = strtok(line, separator);
	for (i = 0; token; i++)
	{
		args[i] = malloc(sizeof(char) * (str_len(token) + 1));
		if (args[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(args[j]);
			free(args);
			free(linecpy);
			return (NULL);
		}
		str_cpy(args[i], token);
		token = strtok(NULL, delim);
	}
	args[i] = NULL;
	changeVar(args, envpt, st);
	free(linecpy);
	return (args);
}

/**
 * getAllCmd - split line with ;
 * @line: line to split
 * Return: array of pointers (success) or NULL (fails)
 */
char **getAllCmd(char *line)
{
	char *linecpy, *token = NULL, **commands;
	int nbTokens = 0, i = 0, k;
	const char *sp = ";";
	
	cmtignore(line);
	linecpy = malloc(sizeof(char) * (str_len(line) + 1));
	if (!linecpy)
		return (NULL);
	str_cpy(linecpy, line);
	nbTokens = numberOfToken(line, sp);
	commands = malloc(sizeof(char *) * (nbTokens + 1));
	if (commands == NULL)
		return (NULL);
	token = strtok(line, sp);
	for (i = 0; token != NULL; i++)
	{
		commands[i] = malloc(sizeof(char) * (str_len(token) + 1));
		if (commands[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(cmds[k]);
			free(commands);
			free(linecpy);
			return (NULL);
		}
		str_cpy(commands[i], token);
		token = strtok(NULL, sp);
	}
	commands[i] = NULL;
	free(linecpy);
	return (commands);
}
/**
 * changeVar - handle variables
 * @args: an array of pointers to arguments
 * @e: an array of environment variables
 * @st: the previous status
 * Return: 0 Success
 */

int changeVar(char **args, char **e, int st)
{
	int k;
	char *newv;

	for (k = 0; args[k] != NULL; k++)
	{
		if (args[k][0] == '$' && args[k][1] == '\0')
			continue;
		else if (str_cmp(args[k], "$?") == 0)
		{
			free(args[k]);
			args[k] = str_dup(convertnum(st, 10, 0));
			continue;
		}
		else if (str_cmp(args[k], "$$") == 0)
		{
			free(args[k]);
			args[k] = str_dup(convertnum(getpid(), 10, 0));
			continue;
		}
		else if (args[k][0] == '$')
		{
			newv = get_env(&args[k][1], e);
			free(args[k]);
			if (newv)
			{
				args[k] = str_dup(newv);
				free(newv);
				continue;
			}
			args[k] = str_dup("");
		}
	}
	return (0);
}
/**
 * convertnum - converts an integer to a specific base
 * @n: the giving integer
 * @base: the base to be converted to
 * @checkcasse: indicates if output upper or lower case
 * Return: the conversion string
 */

char *convertnum(int n, int base, int checkcasse)
{
	char *convert;
	static char *digitsb;
	static char buff[50];
	

	digitsb = checkcasse ? "0123456789ABCDEF" :
			"0123456789abcdef";

	convert = &buffer[49];
	*convert = '\0';

	do {
		*--convert = digitsb[n % base];
		n /= base;
	} while (n != 0);
	return (convert);
}
/**
 * cmtignore - ignore the comments
 * @line : the giving string
 */

void cmtignore(char *line)
{
	int k;

	for (k = 0; line[k] != '\0'; k++)
	{
		if (line[k] == '#' && (i == 0 || line[k - 1] == ' '))
		{
			line[k] = '\0';
			return;
		}
	}
}
