#include "shel.h"
/**
 * str_cmp - compare two string s1 & s2
 * @s1: first string
 * @s2: second string
 * Return: 0 if identic, > 0 if s1 > s2, <0 if s1 < s2
 */
int str_cmp(char *s1, const char *s2)
{
	int j = 0;
	int difference = 0;

	while (s1[j] && s2[j])
	{
		difference = s1[j] - s2[j];
		if (difference != 0)
			return (difference);
		j++;
	}
	difference = s1[j] - s2[j];
	return (difference);
}
/**
 * printenv - print the environnement vvariable
 * @ac: number of argument
 * @args: arguments
 * @ptenv: pointer to environnement variable
 * @status: status
 * Return: environnement variable
 */
int printenv(int ac, char **args, char ***ptenv, int status)
{
	char **envp = *ptenv;
	
	(void)args;
	(void)status;
	if (ac > 2)
	{
		write(STDERR_FILENO, "error : env", str_len("error : env"));
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	while (*envp != NULL)
	{
		write(STDOUT_FILENO, *envp, str_len(*envp));
		write(STDOUT_FILENO, "\n", 1);
		envp++;
	}
	return (0);
}
