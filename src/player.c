#include <stdlib.h>
#include "player.h"

static bool player_won_vertically(Player *self, Board *board);
static bool player_won_horizontally(Player *self, Board *board);
static bool player_won_diagonally(Player *self, Board *board);

Player *new_player(Token token) {
  Player *player = (Player*) malloc(sizeof(Player));

  player->token = token;

  return player;
}

bool player_won(Player *self, Board *board) {
  return player_won_vertically(self, board) ||
         player_won_horizontally(self, board) ||
         player_won_diagonally(self, board);
}

static bool player_won_vertically(Player *self, Board *board) {
  for(int column = 0; column < 3; column++) {
    if(board->state[0][column] != self->token) continue;
    if(board->state[1][column] != self->token) continue;
    if(board->state[2][column] == self->token) return true;
  }

  return false;
}

static bool player_won_horizontally(Player *self, Board *board) {
  for(int row = 0; row < 3; row++) {
    if(board->state[row][0] != self->token) continue;
    if(board->state[row][1] != self->token) continue;
    if(board->state[row][2] == self->token) return true;
  }

  return false;
}

static bool player_won_diagonally(Player *self, Board *board) {
  if(board->state[1][1] != self->token) return false;

  if(board->state[0][0] == self->token &&
     board->state[2][2] == self->token) return true;

  if(board->state[0][2] == self->token &&
     board->state[2][0] == self->token) return true;

  return false;
}
