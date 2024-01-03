#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include "board.h"
#include "token.h"

typedef struct {
  Token token;
} Player;

Player *new_player(Token token);

bool player_won(Player *self, Board *board);

#endif
