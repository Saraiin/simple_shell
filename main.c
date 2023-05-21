#include "lshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 * main - function main
 * @ac: number of arg
 * @av: array
 * Return: 0
 */
int main(int ac, char **av)
{
	int totalchar, totalofarg = 0;
	char *delim = " ";
	char *token, *buffLine;
	size_t length;

	while (1)
	{
		write(1, "little_shell:)", 14);
		totalchar = getline(&buffLine, &length, stdin);
		if (totalchar == -1)
		{
			free(buffer);
			printf("exiting little shell\n");
			return (-1);
		}
		
	}
	free(buffLine);
	return (0);
}
