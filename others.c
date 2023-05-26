#include "shell.h"
/**
 * tokenCnt - counts the number of token in a string
 * @str: the giving string
 * @delim: a string of delimiters
 * Return: the number of tokens
 */
int tokenCnt(char *str, const char *delim)
{
	int count = 0, i, isNewWord = 1;

	for (i = 0; str[i]; i++)
	{
		if (delimck(str[i], delim))
			isNewWord = 1;
		else if (isNewWord == 1)
		{
			count++;
			isNewWord = 0;
		}
	}
	return (count);
}
/**
 * array_len - returns the length of an array of pointers
 * @args: a pointer of pointers to arguments
 * Return: the number of arguments
 */
int array_len(char **args)
{
	int len = 0;

	while (*args != NULL)
	{
		len++;
		args++;
	}
	return (len);
}

