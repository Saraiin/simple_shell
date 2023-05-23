#include "shel.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 * main - function main
 * @ac: number of arg
 * @argv: array
 * Return: 0
 */
int main(int ac, char **argv)
{
	int totalchar, i, len = 2;
	char **e = environ;
	char *buffLine, *buffLinecpy, **av;
	size_t length;

	while (1)
	{
		write(1, "little_shell:)", 14);
		totalchar = getline(&buffLine, &length, stdin);
		if (totalchar == -1)
		{
			free(buffLine);
			printf("exiting little shell\n");
			return (-1);
		}
		buffLinecpy = malloc(sizeof(char) * totalchar);
		if (buffLinecpy == NULL)
		{
			perror("ALLOCATE MEMORY ERROR!");
			return (-1);
		}
		buffLinecpy = str_dup(buffLine);
		av = splitline(buffLine, buffLinecpy);
		status = exectcmd(n, av, &e, status);
	}
	free(buffLinecpy);
	free(buffLine);
	return (0);
}
