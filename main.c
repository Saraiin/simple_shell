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
	char *token, *buffer;
	size_t length;

	while (1)
	{
		printf("little_shell :)");
		totalchar = getline(&buffer, &length, stdin);
		if (totalchar == -1)
		{
			free(buffer);
			printf("exiting little shell\n");
			return (-1);
		}
		token = strtok(buffer, delim);
		while (token != NULL)
		{
			totalofarg++;
			printf("args: %s\n",token);
			token = strtok(NULL, delim);
		}
		printf("number of args : %d\n", totalofarg);
	}
	return (0);
}
