#include "main.h"
		
#include <stdlib.h>
		
#include <stdio.h>
		

		
#define ERR_MSG "Error"
		

		
/**
		
 * is_digit - checks if a string contains a non-digit char
		
 * @s: string to be evaluated
		
 *
		
 * Return: 0 if a non-digit is found, 1 otherwise
		
 */
		
int is_digit(char *s)
		
{
		
	int i = 0;
		

		
	while (s[i])
		
	{
		
		if (s[i] < '0' || s[i] > '9')
		
			return (0);
		
		i++;
		
	}
		
	return (1);
		
}
		

		
/**
		
 * _strlen - returns the length of a string
		
 * @s: string to evaluate
		
 *
		
 * Return: the length of the string
		
 */
		
int _strlen(char *s)
		
{
		
	int i = 0;
		

		
	while (s[i] != '\0')
		
	{
		
		i++;
		
	}
		
	return (i);
		
}
		

		
/**
		
 * errors - handles errors for main
		
 */
		
void errors(void)
		
{
		
	printf("Error\n");
		
	exit(98);
		
}
		

		
/**
		
 * main - multiplies two positive numbers
		
 * @argc: number of arguments
		
 * @argv: array of arguments
		
 *
		
 * Return: always 0 (Success)
		
 */
		
OBOBOBOBint main(int argc, char *argv[])
OBOB		
OBOB{
OB		
OBOB	char *s1, *s2;
		
OBOB	int len1, len2, len, i, carry, digit1, digit2, *result, a = 0;
OB		
OBOB
OB		
	s1 = argv[1], s2 = argv[2];
OB		
OB	if (argc != 3 || !is_digit(s1) || !is_digit(s2))
OB		
		errors();
OB		
	len1 = _strlen(s1);
		
	len2 = _strlen(s2);
		
	len = len1 + len2 + 1;
		
OB	result = malloc(sizeof(int) * len);
		
	if (!result)
		
		return (1);
		
	for (i = 0; i <= len1 + len2; i++)
		
		result[i] = 0;
		
	for (len1 = len1 - 1; len1 >= 0; len1--)
		
	{
		
		digit1 = s1[len1] - '0';
		
OBOBOB		carry = 0;
OB		
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
OBOB		
OB		{
OB		
			digit2 = s2[len2] - '0';
OB		
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
OB		
			result[len1 + len2 + 1] = carry % 10;
		
			carry /= 10;
		
		}
OB		
		if (carry > 0)
OB		
			result[len1 + len2 + 1] += carry;
OB		
	}
		
	for (i = 0; i < len - 1; i++)
		
	{
		
		if (result[i])
		
			a = 1;
		
		if (a)
		
			_putchar(result[i] + '0');
		
	}
		
	if (!a)
		
		_putchar('0');
		
	_putchar('\n');
		
	free(result);
		
	return (0);
		
}

