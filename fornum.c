#include "shell.h"
/**
 * atoii - convert a string to an integer
 * @s: string to convert
 * Return: int found or 0
 */

int atoii(char *s)
{
	unsigned int result = 0;
	int i = 0, len = 0, signe = 1;

	len = str_len(s);

	for (i = 0; i < len; i++)
	{
		if (s[i] == '-')
			signe = -(signe);
		else if (s[i] >= 48 && s[i] <= 57)
			result = 10 * result + (s[i] - '0');
		else if (result != 0)
			break;
	}
	return (signe * result);
}

/**
 * is_digit - checks for a digit
 * @c: character to check
 * Return: 1 (if c is digit) 0 otherwize
 */
int is_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/**
 * convertnum - converts an integer to a specific base
 * @n: the giving integer
 * @base: the base to be converted to
 * @upper_o_n: indicates if output upper od lower case
 * Return: the conversion string
 */

char *convertnum(int n, int base, int upper_o_n)
{
	static char *base_digits;
	static char buffer[50];
	char *p_convert;

	base_digits = upper_o_n ? "0123456789ABCDEF" :
			"0123456789abcdef";

	p_convert = &buffer[49];
	*p_convert = '\0';

	do {
		*--p_convert = base_digits[n % base];
		n /= base;
	} while (n != 0);
	return (p_convert);
}
/**
 * replacevar - handle variables
 * @args: an array of pointers to arguments
 * @e: an array of environment variables
 * @s: the previous status
 * Return: 0 Success
 */

int replacevar(char **args, char **e, int s)
{
	int i;
	char *value;

	for (i = 0; args[i] != NULL; i++)
	{
		if (args[i][0] == '$' && args[i][1] == '\0')
			continue;
		else if (str_cmp(args[i], "$?") == 0)
		{
			free(args[i]);
			args[i] = str_dup(convertnum(s, 10, 0));
			continue;
		}
		else if (str_cmp(args[i], "$$") == 0)
		{
			free(args[i]);
			args[i] = str_dup(convertnum(getpid(), 10, 0));
			continue;
		}
		else if (args[i][0] == '$')
		{
			value = _getenv(&args[i][1], e);
			free(args[i]);
			if (value)
			{
				args[i] = str_dup(value);
				free(value);
				continue;
			}
			args[i] = str_dup("");
		}
	}
	return (0);
}

