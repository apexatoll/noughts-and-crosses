#include <stdlib.h>
#include "player.h"

Player *new_player(Token token) {
  Player *player = (Player*) malloc(sizeof(Player));

  player->token = token;

  return player;
}
