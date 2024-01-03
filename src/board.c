#include <stdlib.h>
#include "board.h"

Board *new_board() {
  Board *board = (Board*) malloc(sizeof(Board));

  reset_board(board);

  return board;
}

void reset_board(Board *self) {
  for(int row = 0; row < 3; row++) {
    for(int column = 0; column < 3; column++) {
      self->state[row][column] = EMPTY;
    }
  }
}
