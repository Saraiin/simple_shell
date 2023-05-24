#include "shel.h"
/**
 *checkdegit - checks if the character is degit
 * @n: character to check
 * Return: 1 (if n is digit), else 0
 */
int checkdegit(int n)
{
	if (n >= 48 && n <= 57)
		return (1);
	return (0);
}
/**
 * atoii - convert  a string to integer
 * @str: string to convert
 * Return: convert
 */
int atoii(char *str)
{
	int len = 0, i = 0, signe = 1;
	unsigned int convert = 0;

	len = str_len(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] == '-')
			signe = -(signe);
		else if (str[i] >= 48 && str[i] <= 57)
			convert = 10 * convert + (str[i] - '0');
		else if (convert != 0)
			break;
	}
	return (signe * convert);
}
/**
 * exitt - to exit the current process
 * @ac: number of argument
 * @exe: name of executable
 * @args: pointer to array of pointer to arguments
 * @envpt: pointer of environnement variables
 * @st: status of the previous command
 * Return: 0 success
 */
int exitt(char *exe, int ac, char **args, char **envpt, int st)
{
	int j, status = 200;

	(void)envpt;
	if (ac > 2)
	{
		write(STDERR_FILENO, "exit statuts error", 18);
		return (1);
	}
	if (args[1] != NULL)
	{
		for (j = 0; args[1][j] != '\0'; j++)
		{
			if (j == 0 && as[1][j] == '-')
				continue;
			if (!checkdegit(args[1][j]))
			{
				write(STDERR_FILENO, "exit: numeric argument needed", 29);
				return (2);
			}
		}
		status = atoi(args[1]);
	}
	else if (st != 0)
		status = st;
	return (status);
}
