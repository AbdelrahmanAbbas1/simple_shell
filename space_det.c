#include "main.h"

/**
 * space_det - detect how many white spaces int eh string
 * @s: the string to be checked
 *
 * Return: the number of spaces in the string or -1 otherwise
 */
int space_det(char *s)
{
	int i, sp = 0;

	if (s == NULL)
		return (-1);

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			sp++;
	}
	return (sp);
}
