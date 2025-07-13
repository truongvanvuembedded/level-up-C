#include <stdio.h>
static void convertDollar_to_minCoin(float amount)
{
  // Quarter  = 1/4   dollar (25 cent)
  // Dime     = 1/10  dollar (10 cent)
  // Nickel   = 1/20  dollar (5 cent)
  // Penny    = 1/100 dollar (1 cent)
  int Quarter, Dime, Nickel, Penny, cent;

  cent = (int)(amount * 100);

  Quarter = cent / 25;
  cent %= 25;

  Dime = cent / 10;
  cent %= 10;

  Nickel = cent / 5;
  cent %= 5;

  Penny = cent;

  printf("Amount: $%.2f\n", amount);
  printf("Q: %d, D: %d, N: %d, P: %d\n", Quarter, Dime, Nickel, Penny);
}

int main()
{
  float amount[] = {
      0.49, 1.27, 0.75, 1.31, 0.83};
  for (int i = 0; i < (sizeof(amount) / sizeof(amount[0])); i++)
  {
    convertDollar_to_minCoin(amount[i]);
  }

  return (0);
}
