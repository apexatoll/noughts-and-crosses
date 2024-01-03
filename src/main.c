#include <stdio.h>
#include "game.h"

int main() {
  printf("Noughts and Crosses\n");

  Game *game = new_game();

  play_game(game);
}
