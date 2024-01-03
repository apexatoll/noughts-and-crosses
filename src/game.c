#include <stdlib.h>
#include "game.h"

Game *new_game() {
  Game *game = (Game*) malloc(sizeof(Game));

  game->board = new_board();
  game->player = new_player(CROSS);
  game->computer = new_player(NOUGHT);

  return game;
}
