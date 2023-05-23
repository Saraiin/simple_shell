#include "shel.c"
/**
 *checkdegit - checks if the character is degit
 * @n: character to check
 * Return: 1 (if n is digit), else 0
 */
int checkdegit(int n)
{
	if (n >= 48 && c <= 57)
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
		else if (str[i] >= 48 && s[i] <= 57)
			convert = 10 * convert + (s[i] - '0');
		else if (convert != 0)
			break;
	}
	return (signe * convert);
}
/**
 * exitt - to exit the current process
 * @ac: number of argument
 * @args: pointer to array of pointer to arguments
 * @ptenv: pointer of environnement variables
 * @prstatus: status of the previous command
 * Return: 0 success
 */
int exitt(int ac, char **args, char ***ptenv, int prstatus)
{
	int i, status = 0;

	if (ac > 3)
	{
		write(STDERR_FILENO, "exit statuts error", 18);
		return (1);
	}
	if (args[2] != NULL)
	{
		for (i = 0; args[2][i] != '\0'; i++)
		{
			if (i == 0 && args[2][i] == '-')
				continue;
			if (!checkdigit(args[2][i]))
				write(STDERR_FILENO, "exit: numeric argument needed", 29);
			return (2);
		}
		status = atoii(args[2]);
	}
	else
		status = prstatus;
	exit(status);
}
