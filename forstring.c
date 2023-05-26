#include "shell.h"

/**
 * str_len - returns the length of string
 * @str: the giving string
 * Return: the length of the string
 */

int str_len(char *str)
{
	int len = 0, i = 0;

	while (str[i++])
		len++;
	return (len);
}
/**
 * str_dup - returns a pointer to duplicated string
 * @str: the giving string
 * Return: a pointer to the duplicated string or NULL if it fails
 */
char *str_dup(char *str)
{
	char *dupString;
	int length = 0, i;

	if (!str)
		return (NULL);
	length = str_len(str);
	/* Allocate space for the duplicate string */
	dupString = malloc(sizeof(char) * (length + 1));
	/* Check if the allocation it fails or not */
	if (!dupString)
	{
		perror("Error : malloc");
		return (NULL);
	}
	/* copy the string */
	for (i = 0; i < length; i++)
		dupString[i] = str[i];
	/* Add the end of string character */
	dupString[i] = '\0';
	return (dupString);
}
/**
 * str_cpy - copies a string to a buffer
 * @src: a pointer to the source string
 * @dest: a pointer to the destination string
 * Return: pointer to the destination buffer
 */

char *str_cpy(char *dest, char *src)
{
	int srclen = 0, i;

	srclen = str_len(src);

	for (i = 0; i <= srclen; i++)
		dest[i] = src[i];
	return (dest);
}
/**
 * str_cat - concatenates two strings
 * @str1: the first string
 * @str2: the second string
 * Return: the concatenate string
 */
char *str_cat(char *str1, char *str2)
{
	int len1 = 0, len2 = 0, i, j;

	len1 = str_len(str1);
	len2 = str_len(str2);

	for (i = 0, j = len1; i < len2; i++, j++)
		str1[j] = str2[i];
	str1[j] = '\0';
	return (str1);
}
/**
 * str_cmp - compares two strings
 * @str1: the first String
 * @str2: the second String
 * Return: 0 (if str1 and str2 equal), integer < 0 (if str1 less than str2)
 * integer > 0 (if str1 greater than str2)
 */
int str_cmp(char *str1, const char *str2)
{
	int i = 0, diff = 0;

	while (str1[i] && str2[i])
	{
		diff = str1[i] - str2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	diff = str1[i] - str2[i];
	return (diff);
}
