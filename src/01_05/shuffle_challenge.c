#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void perfectShuffle_returnNumIterations(char *original)
{
  int len = strlen(original);
  int counter = 0;
  char temp;
  char *newString;
  char *oldstring;

  printf("%d", strlen(original));
  if (len % 2)
  {
    // Odd number
    printf("\nYou enter the input is odd not implement the prefect shuffle");
    return;
  }
  printf("\nOriginal desk: %s", original);
  newString = (char *)(malloc(sizeof(char) * (len + 1)));
  oldstring = (char *)(malloc(sizeof(char) * (len + 1)));
  if (newString == NULL || oldstring == NULL)
  {
    printf("\nMalloc failed");
    return;
  }
  strcpy(oldstring, original);
  oldstring[len] = '\0';
  printf("\n oldstring desk: %s", oldstring);
  while (1)
  {
    counter++;
    for (int i = 0; i < len; i++)
    {
      if (i % 2 == 0)
        temp = oldstring[i / 2];
      else
        temp = oldstring[i / 2 + len / 2];
      newString[i] = temp;
    }
    newString[len] = '\0';
    printf("\n%d: %s", counter, newString);
    if (strncmp(newString, original, strlen(original)) == 0)
    {
      break;
    }

    strcpy(oldstring, newString);
    oldstring[len] = '\0';
  }
  free(newString);
  printf("\nDeck restored after %d iterations", counter);
}
int main()
{
  char original[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  perfectShuffle_returnNumIterations(original);
  return 0;
}