#include "shell.h"
void showerror(char *exe, char *desc)
{
	char *error;

	error = malloc(sizeof(char) * (str_len(exe) + str_len(desc) + 5));
	if (error == NULL)
	{
		write(STDERR_FILENO, "Not enough space", 16);
		return;
	}
	str_cpy(error, exe);
	str_cat(error, ": ");
	str_cat(error, desc);
	str_cat(error, "\n\0");
	write(STDERR_FILENO, error, str_len(error));
	free(error);
}


/**
 * notfound - prints command not found error
 * @exe: executable name
 * @av: an array of pointers to arguments
 * Return: 127
 */

int notfound(char *exe, char **av)
{
	char *error;

	error = malloc(sizeof(char) * (str_len(exe) + str_len(av[0]) + 24));
	if (error == NULL)
	{
		write(STDERR_FILENO, "Not enough space", 16);
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
