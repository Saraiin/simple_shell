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

/**
 * numberOfToken - calculate number of tokes in line
 * @line: line to check
 * @separator: delim that separete tokens
 */
int numberOfToken(char *line, const char *separator)
{
	int nb = 0;
	char *token;

	token = strtok(line, separator);
	while (token)
	{
		nb++;
		token = strtok(NULL, separator);
	}
	return (nb);
}
/**
 * str_cpy - copy string
 * @dest: printer to destination where to copy
 * @src: printer to the original string
 */
char *str_cpy(char *dest, char *src)
{
	int i, srcln = 0;

	srcln = str_len(src);
	for (i = 0; i <= srcln; i++)
		dest[i] = src[i];
	return (dest);
}
