#include "shel.h"
/**
 * showerrors - print error message
 * @exe: executable name
 * @msg: error message
 */

void showerrors(char *exe, char *msg)
{
	char *error;

	error = malloc(sizeof(char) * (str_len(exe) + str_len(msg) + 5));
	if (error == NULL)
	{
		write(STDERR_FILENO, "No space", 8);
		return;
	}
	str_cpy(error, exe);
	str_cat(error, ": ");
	str_cat(error, msg);
	str_cat(error, "\n\0");
	write(STDERR_FILENO, error, str_len(error));
	free(error);
}
/**
 * cmdnotfound - prints command not found error
 * @exe: executable name
 * @av: an array of pointers to arguments
 * Return: 127
 */
int cmdnotfound(char *exe, char **av)
{
	char *error;

	error = malloc(sizeof(char) * (str_len(exe) + str_len(av[0]) + 24));
	if (error == NULL)
	{
		write(STDERR_FILENO, "No space", 8);
		return (1);
	}
	str_cpy(error, exe);
	str_cat(error, ": ");
	str_cat(error, av[0]);
	str_cat(error, ": ");
	str_cat(error, "command not found");
	str_cat(error, "\n\0");
	write(STDERR_FILENO, error, str_len(error));
	free(error);
	return (127);
}
