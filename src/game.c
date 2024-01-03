#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "game.h"

static bool game_complete(Game *self);
static void game_player_turn(Game *self);
static void game_computer_turn(Game *self);
static void print_game_result(Game *self);
static int random_selection();

Game *new_game() {
  Game *game = (Game*) malloc(sizeof(Game));

  game->board = new_board();
  game->player = new_player(CROSS);
  game->computer = new_player(NOUGHT);

  return game;
}

void play_game(Game *self) {
  srand(time(NULL));

  print_board(self->board);

  while(!game_complete(self)) {
    printf("Player's turn:\n\n");
    game_player_turn(self);
    print_board(self->board);

    if(!game_complete(self)) {
      printf("Computer's turn:\n");
      game_computer_turn(self);
      print_board(self->board);
    }
  }

  print_game_result(self);
}

static bool game_complete(Game *self) {
  return board_complete(self->board) ||
         player_won(self->player, self->board) ||
         player_won(self->computer, self->board);
}

static void game_player_turn(Game *self) {
  int row, column;

  printf("Enter row [1-3]:\n> ");
  scanf("%d", &row);

  printf("Enter column [1-3]:\n> ");
  scanf("%d", &column);

  row--;
  column--;

  if(!board_space_free(self->board, row, column)) {
    printf("That space is already taken!\n\n");
    game_player_turn(self);
  } else {
    set_board_state(self->board, row, column, self->player->token);
  }
}

static void game_computer_turn(Game *self) {
  int row = random_selection();
  int column = random_selection();

  if(!board_space_free(self->board, row, column)) {
    game_computer_turn(self);
  } else {
    sleep(1);
    set_board_state(self->board, row, column, self->computer->token);
  }
}

static int random_selection() {
  return rand() % 3;
}

static void print_game_result(Game *self) {
  if(player_won(self->player, self->board)) {
    printf("Player wins!\n");
  } else if(player_won(self->computer, self->board)) {
    printf("Computer wins!\n");
  } else {
    printf("It's a draw!\n");
  }
}
