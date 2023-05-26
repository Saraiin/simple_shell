#include "shell.h"
/**
 * free_list - free an array of string
 * @ptr: the giving array to be freed
 * @i: the last index of the array
 */
void free_list(char **ptr, int i)
{
	while (i > 0)
		free(ptr[--i]);
	free(ptr);
}
/**
 * delimck - check if a character is delimiter
 * @c: the giving character
 * @delim: a string of delimiter characters
 * Return: 1 (if c is delimiter), 0 otherwize
 */
int delimck(char c, const char *delim)
{
	int i = 0;

	while (delim[i])
	{
		if (delim[i] == c)
			return (1);
		i++;
	}
	return (0);
}
/**
 * free_args - free an array of string
 * @av: an array of strings
 */

void free_args(char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	free(av);
}
