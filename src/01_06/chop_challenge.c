#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *left(char *s, int len)
{
	char *str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
	{
		printf("Malloc failed");
		return '\0';
	}

	for (int i = 0; i < len; i++)
	{
		str[i] = s[i];
	}
	return str;
}

char *right(char *s, int len)
{
	char *str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
	{
		printf("Malloc failed");
		return '\0';
	}
	int LenStr = strlen(s);
	char *newStr;
	newStr = &s[LenStr - len];
	for (int i = 0; i < len; i++)
	{
		str[i] = newStr[i];
	}
	return str;
}

char *mid(char *s, int offset, int len)
{
	char *str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
	{
		printf("Malloc failed");
		return '\0';
	}
	char *pNewString;
	pNewString = &s[offset - 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = pNewString[i];
	}
	return str;
}

int main()
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: %s\n", string);
	printf("Left %d characters: %s\n", 16, left(string, 16));
	printf("Right %d characters: %s\n", 18, right(string, 18));
	printf("Middle %d characters: %s\n", 11, mid(string, 13, 11));

	return (0);
}
