#include <iostream>
#include <math.h>
using namespace std;

int main() {
  const int BOARD_SIZE = 8;
  char board[BOARD_SIZE][BOARD_SIZE];
  char c;
  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      cin >> c;
      switch (c) {
        case 'B':
        case 'W':
          board[i][j] = c;
          break;
        case '.':
        default:
          board[i][j] = 0;
          break;
      }
    }
  }

  int minA = BOARD_SIZE;
  int maxB = 0;
  int blocked;

  for (int j = 0; j < BOARD_SIZE; ++j) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
      char p = board[i][j];
      if (p == 'W') {  // Player A
        blocked = false;
        for (int k = i - 1; k >= 0; k--) {
          if (board[k][j] == 'B') {
            blocked = true;
            break;
          }
        }
        if (!blocked) {
          minA = min(minA, i);
        }
      }
      else if (p == 'B') { // Player B
        blocked = false;
        for (int k = i + 1; k < BOARD_SIZE; k++) {
          if (board[k][j] == 'W') {
            blocked = true;
            break;
          }
        }
        if (!blocked) {
          maxB = max(maxB, i);
        }
      }
    }
  }

  if (minA <= (BOARD_SIZE - maxB - 1)) cout << "A" << endl;
  else cout << "B" << endl;

  return 0;
}