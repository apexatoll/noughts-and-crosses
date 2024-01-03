#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

typedef struct {
  Board *board;
  Player *player;
  Player *computer;
} Game;

Game *new_game();

void play_game(Game *self);

#endif
