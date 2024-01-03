#include <stdio.h>
#include <stdlib.h>
#include "board.h"

static void print_board_row(Board *self, int row);
static void print_separator();

Board *new_board() {
  Board *board = (Board*) malloc(sizeof(Board));

  reset_board(board);

  return board;
}

void print_board(Board *self) {
  printf("\n");
  print_board_row(self, 0);
  print_separator();
  print_board_row(self, 1);
  print_separator();
  print_board_row(self, 2);
  printf("\n\n");
}

void reset_board(Board *self) {
  for(int row = 0; row < 3; row++) {
    for(int column = 0; column < 3; column++) {
      set_board_state(self, row, column, EMPTY);
    }
  }
}

void set_board_state(Board *self, int row, int column, Token token) {
  self->state[row][column] = token;
}

bool board_complete(Board *self) {
  for(int row = 0; row < 3; row++) {
    for(int column = 0; column < 3; column++) {
      if(self->state[row][column] == EMPTY) {
        return false;
      }
    }
  }

  return true;
}

static void print_board_row(Board *self, int row) {
  printf(
    " %c | %c | %c ",
    token_to_char(self->state[row][0]),
    token_to_char(self->state[row][1]),
    token_to_char(self->state[row][2])
  );
}

static void print_separator() {
  printf("\n---|---|---\n");
}
