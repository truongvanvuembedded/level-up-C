#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* the structure proves to be more flexible than
   creating a two-dimensional array. Arrays in C
   are all single dimension anyhow, with the compiler
   doing the math for any dimensions specified.
   This approach allows the matrix to be dynamic
   and keeps all the details in a single package */
struct matrix
{
  int rows;
  int cols;
  char *cells;
};

static void create_fill_matrix(struct matrix *st_grid)
{
  char *grid = (char *)malloc(st_grid->cols * st_grid->rows * sizeof(char));
  if (grid == NULL)
  {
    printf("Malloc failed");
    exit(1);
  }
  for (int row = 0; row < st_grid->rows; row++)
  {
    for (int collumn = 0; collumn < st_grid->cols; collumn++)
    {
      grid[row * st_grid->cols + collumn] = rand() % 26 + 'a';
    }
  }
  st_grid->cells = grid;
}

static void rorate_matrix(struct matrix *pst_grid)
{
  int src_row, src_col;
  struct matrix *newGrid = (struct matrix *)malloc(sizeof(struct matrix));
  if (newGrid == NULL)
  {
    printf("Malloc failed");
    exit(1);
  }
  newGrid->rows = pst_grid->cols;
  newGrid->cols = pst_grid->rows;
  newGrid->cells = (char *)malloc(sizeof(char) * newGrid->rows * newGrid->cols);
  if (newGrid->cells == NULL)
  {
    printf("Malloc failed");
    exit(1);
  }
  for (int row = 0; row < newGrid->rows; row++)
  {
    for (int col = 0; col < newGrid->cols; col++)
    {
      // Tính vị trí tương ứng trong pst_grid
      // odd col = 3 row = 8
      // Aft col = 8 row = 3

      src_row = pst_grid->rows - 1 - col;
      src_col = row;

      newGrid->cells[row * newGrid->cols + col] =
          pst_grid->cells[src_row * pst_grid->cols + src_col];
    }
  }
  pst_grid->rows = newGrid->rows;
  pst_grid->cols = newGrid->cols;
  for (int i = 0; i < newGrid->rows * newGrid->cols; i++)
    pst_grid->cells[i] = newGrid->cells[i];
  free(newGrid->cells);
  free(newGrid);
}

static void printf_matrix(struct matrix *st_grid)
{
  for (int row = 0; row < st_grid->rows; row++)
  {
    for (int collumn = 0; collumn < st_grid->cols; collumn++)
    {
      printf("  %c", st_grid->cells[row * st_grid->cols + collumn]);
    }
    printf("\n");
  }
}

int main()
{
  /* using NULL pointers allows me to provide the
     basic data without specifying a variable-size
     character buffer */
  struct matrix grid[3] = {
      {8, 3, NULL},
      {5, 5, NULL},
      {4, 6, NULL}};
  int x;

  /* initialize the randomizer */
  srand((unsigned)time(NULL));

  for (int i = 0; i < 3; i++)
  {
    printf("Array %d \n", i);
    printf("Original\n");
    create_fill_matrix(&grid[i]);
    printf_matrix(&grid[i]);
    rorate_matrix(&grid[i]);
    printf("\nAfter Rotate \n");
    printf_matrix(&grid[i]);
  }

  return (0);
}
