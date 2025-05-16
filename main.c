#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DIM 10
#define NBBOMBS 10

// state = 0 if hidden, 1 if discover
// if nbBomb = -1 | The tile is a bomb
typedef struct {
  int state;
  int nbNearBombs;

} Tile;

void displayBoard(Tile board[DIM][DIM], unsigned int dim)
{

  printf("   ");
  for (int i = 0; i < dim; i++)
  {
    printf(" %d ", i);
  }

  printf("\n");
  for (int i = 0; i < dim; i++)
  {
    printf(" %d ", i);
    for (int j = 0; j < dim; j++)
    {

      if (board[i][j].state == 0)
        printf(" ? ");
      else
      {
        if (board[i][j].nbNearBombs != -1)
          printf(" %d ", board[i][j].nbNearBombs);
        else
          printf(" X ");
      }
    }
    printf("\n");
  }
}

void displayNbBomb(Tile board[DIM][DIM], unsigned int dim)
{
  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
    {
      if (board[i][j].nbNearBombs != -1)
        printf(" %d ", board[i][j].nbNearBombs);
      else
         printf(" X ");
     
    }
    printf("\n");
  }
}

int getNbNearBombs(Tile board[DIM][DIM], unsigned int dim, int x, int y)
{
  if (board[x][y].nbNearBombs == -1)
    return -1;

  int nbNearBombs = 0;
  
  // Axes
  if (x != 0)
  {
    if (board[x - 1][y].nbNearBombs == -1)
      nbNearBombs++;
  }
  if (x != dim - 1)
  {
    if (board[x + 1][y].nbNearBombs == -1)
      nbNearBombs++;
  }
  if (y != 0)
  {
    if (board[x][y - 1].nbNearBombs == -1)
      nbNearBombs++;
  }
  if (y != dim - 1)
  {
    if (board[x][y + 1].nbNearBombs == -1)
      nbNearBombs++;
  }

  // Diagonales
  if (x != 0 && y != 0)
  {
    if (board[x - 1][y - 1].nbNearBombs == -1)
      nbNearBombs++;
  }
  if (x != 0 && y != dim - 1)
  {
    if (board[x - 1][y + 1].nbNearBombs == -1)
      nbNearBombs++;
  }
  if (x != dim - 1 && y != 0)
  {
    if (board[x + 1][y - 1].nbNearBombs == -1)
      nbNearBombs++;
  }
  if (x != dim - 1 && y != dim - 1)
  {
    if (board[x + 1][y + 1].nbNearBombs == -1)
      nbNearBombs++;
  }

  return nbNearBombs;
}

void buildBoard(Tile board[DIM][DIM], unsigned int dim, const int nbBombs)
{ 
  // Plant all the bombs at random location.
  for (int i = 0; i < nbBombs; i++)
  {
    board[rand() % dim][rand() % dim].nbNearBombs = -1;
  }
  
  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
    {
      board[i][j].state = 0;
      board[i][j].nbNearBombs = getNbNearBombs(board, dim, i, j);

    }
  }
}

int main(int argc, char argv[])
{
  // Generate random seed
  srand(time(NULL));

  Tile board[DIM][DIM];
  buildBoard(board, DIM, NBBOMBS);

  while (1)
  {
    system("clear");
    displayBoard(board, DIM);
    sleep(0.1);

    char position[4];
    printf("X Y: ");
    fgets(position, 4, stdin);
    fgetc(stdin);

    int X = (int)position[0] - '0';
    int X = (int)position[2] - '0';
    board[X][Y].state = 1;

  }

  return 0;
}

