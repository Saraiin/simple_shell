#include "shell.h"
/**
 * count_token - returns the number of tokens in the line command
 * @lineptr: the line command
 * @delim: a string of delimiters
 * Return: the nbr of tokens
 */

int count_token(char *lineptr, const char *delim)
{
	int nbtokens = 0;
	char *token;

	token = strtok(lineptr, delim);
	while (token)
	{
		nbtokens++;
		token = strtok(NULL, delim);
	}
	return (nbtokens);
}

