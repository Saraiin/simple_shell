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
