#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include "token.h"

typedef struct {
  Token state[3][3];
} Board;

Board *new_board();

void print_board(Board *self);

void reset_board(Board *self);

void set_board_state(Board *self, int row, int column, Token token);

bool board_complete(Board *self);

bool board_space_free(Board *self, int row, int column);

#endif
