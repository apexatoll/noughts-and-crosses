#ifndef BOARD_H
#define BOARD_H

#include "token.h"

typedef struct {
  Token state[3][3];
} Board;

Board *new_board();

void reset_board(Board *self);

#endif