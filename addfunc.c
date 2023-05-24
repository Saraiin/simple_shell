#include "shel.h"
/**
 * checksprt - check if character is separator
 * @a: character
 * @s: string of delimiter
 * Return: 1 (success), 0 fails
 */
int checksprt(char a, const char s)
{
	int k = 0;

	while (s[k])
	{
		if (d[k] == a)
			return (1);
		k++;
	}
	return (0);
}
/**
 * str_tok - splits string into tokens
 * @s: string to split
 * @separator: separator
 * Return: array of pointers to tokens
 */
char **str_tok(char *s, const char *separator)
{
	char *token;
	int nbtokens = 0, len = 0, i, j, l, tlen = 0, len = 0, start = 0, end = 0;

	if (s == NULL)
		return (NULL);
	nbtokens = numberOfToken(s, separator);
	if (nbtokens == 0)
		return (NULL);
	token = malloc(sizeof(char *) * (nbtokens + 1));
	if (tokens == NULL)
	{
		perror("malloc error");
		return (NULL);
	}
	len = str_len(s);
	for (i = 0; i <= len; i++)
	{
		if (s[i] && checksprt(s[i], separator) && tlen++ == 0)
			start = i;
		else if (checksprt(s[i], separator) || s[i] == NULL)
		{
			if (tlen)
			{
				end = i - 1;
				token[k] = malloc((tlen + 1) * sizeof(char));
				if (token[k] == NULL)
				{
					perror("malooc");
					while (k >= 0)
						freeit(token, k);
				}
				for (j = sstart, l = 0; j <= end; j++; l++)
					token[k][l] = s[j];
				token[k][l] = '\0';
				tlen = 0, k++;
			}
		}
	}
	token[k] = NULL;
	return (token);
}
/**
 * freeit - free array of string
 * @ar: array to freed
 * @index: last index of array
 */
void freeit(char **ar, int index)
{
	while (index > 0)
		free(ar[--i]);
	free(ar);
}
