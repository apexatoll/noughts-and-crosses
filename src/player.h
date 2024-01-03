#ifndef PLAYER_H
#define PLAYER_H

#include "token.h"

typedef struct {
  Token token;
} Player;

Player *new_player(Token token);

#endif
