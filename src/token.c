#include "token.h"

char token_to_char(Token token) {
  switch(token) {
    case EMPTY:
      return ' ';
    case NOUGHT:
      return 'O';
    case CROSS:
      return 'X';
  }
}
