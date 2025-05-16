#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

// state = 0 if hidden, 1 if discover
// if nbBomb = -1 | The tile is a bomb
typedef struct {
  int state;
  int nbBomb;

} Tile;

void displayBoard(Tile board[DIM][DIM], unsigned int dim)
{
  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
    {
      if (board[i][j].state == 0)
        printf(" ? ");
     
    }
    printf("\n");
  }
}

void buildBoard(Tile board[DIM][DIM], unsigned int dim)
{ 
  for (int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
    {
      board[i][j].state = 0;
    }
  }
}

int main(int argc, char argv[])
{
  Tile board[DIM][DIM];
  buildBoard(board, DIM);
  displayBoard(board, DIM);


  return 0;
}

