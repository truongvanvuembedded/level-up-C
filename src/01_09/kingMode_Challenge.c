#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GSIZE 8
typedef struct
{
  int row;
  int collumn;
} ST_KING_LOCATION;

static void draw_Grid(int turnNumber, ST_KING_LOCATION st_KingLocation)
{
  printf("Turning step: %d\n", turnNumber);
  for (int row = 0; row < GSIZE; row++)
  {
    for (int collumn = 0; collumn < GSIZE; collumn++)
    {
      if ((row == st_KingLocation.row) && (collumn == st_KingLocation.collumn))
        printf("  k");
      else
        printf("  .");
    }
    printf("\n");
  }
}

static int crateStep(void)
{
  int r;

  r = (rand() % 3) - 1; // Value possiple is 0 1 -1
  return (r);
}

int escaped(ST_KING_LOCATION k)
{
  enum
  {
    FALSE,
    TRUE
  };

  if (k.row < 0)
    return (TRUE);
  if (k.row >= GSIZE)
    return (TRUE);
  if (k.collumn < 0)
    return (TRUE);
  if (k.collumn >= GSIZE)
    return (TRUE);
  return (FALSE);
}

/* main program */
int main()
{
  int turn = 0;
  ST_KING_LOCATION king = {3, 4}; /* fourth row, fifth column */

  /* Init randomizer */
  srand((unsigned)time(NULL));

  /* the loop terminates when the king wanders out */
  while (1)
  {
    /* show the grid */
    turn++;
    draw_Grid(turn, king);
    /* move the king */
    king.row += crateStep();
    king.collumn += crateStep();
    if (escaped(king))
    {
      break;
    }
  }
  printf("The king wandered off the grid after %d turns\n", turn);

  return (0);
}
