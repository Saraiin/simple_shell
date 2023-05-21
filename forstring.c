#include "shel.h"
/**
 * str_len - return length of a string
 * @s: string to check
 * Return: length of string
 */
int str_len(char *s)
{
	int i = 0, length = 0;

	while (s[i++])
		length++;
	return (length);
}
/**
 * str_dup - return pointer to duplicated string
 * @s: string to duplicate
 * Return: pointer to the new string
 */
char *str_dup(char *s)
{
	char *duplicatedS;
	int len = 0, i;

	if (s == NULL)
		return (NULL);
	len = str_len(s);
	duplicatedS = malloc(sizeof(char) * (len + 1));
	if (duplicatedS == NULL)
	{
		perror("Error Malloc");
		return (NULL);
	}
	for (i = 0; i < len; i++)
		duplicatedS[i] = s[i];
	duplicatedS[i] = '\0';
	return (duplicatedS);
}
