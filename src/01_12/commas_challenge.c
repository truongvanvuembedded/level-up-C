#include <stdio.h>
#include <string.h>

void commify(char *pstring, int values)
{
	char string[15];
	sprintf(string, "%d", values);
	int len = strlen(string);
	int counterForpString = 0;
	int counternewString = 0;
	while (string[counternewString] != '\0')
	{
		if (len % 3 == 0)
		{
			if (counterForpString != 0)
			{
				pstring[counterForpString] = ',';
				counterForpString++;
			}
		}
		pstring[counterForpString] = string[counternewString];
		counterForpString++;
		counternewString++;
		len--;
	}
	pstring[counterForpString] = '\0';
}
int main()
{
	char stringReturn[15];
	int values[10] = {
			123, 1899, 48266, 123456, 9876543,
			10100100, 5, 500000, 99000111, 83};
	for (int i = 0; i < 15; i++)
	{
		commify(stringReturn, values[i]);
		printf("\n%s", stringReturn);
	}
	return (0);
}
