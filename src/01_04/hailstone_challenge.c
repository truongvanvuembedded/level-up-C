#include <stdio.h>
static void hailstone_Caculator(void)
{
  int counter;
  int hail;

  counter = 0;
  while (1)
  {
    printf("\nEntern the hailstone number: ");
    scanf("%d", &hail);

    if (hail <= 0)
    {
      printf("\nYou enter wrong hailstone number");
      continue;
    }
    break;
  }

  printf("\nThe sequence of hailstone number is: ");
  while (hail != 1)
  {
    if (hail % 2 == 0)
      hail /= 2;
    else
      hail = hail * 3 + 1;
    printf("%d, ", hail);
    counter++;
  }
  printf("\nThe sequence len: %d \n", counter);
}
int main()
{
  hailstone_Caculator();
  return (0);
}
