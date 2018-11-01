#include <stdio.h>

#define N 9

int board[N];
int rows = 3, cols = 3, zeroIndex;

// for previousMove: 0 is down, 1 is up, 2 is left, 3 is right
int blindSearch(int x, int y, int moves, int previousMove) {
  int i, foundAnswer;

  // answer is less than manhattan distance, not possible
  if (moves < (x + y))
    return 0;

  if (!moves) {
    for (i = 0; i < N - 1; i++) {
      if (board[i] != i + 1)
        return 0;
    }

    return 1;
  }

  if (x > 0 && previousMove != 1) {
    // can expand down
    board[zeroIndex] = board[zeroIndex + rows];
    zeroIndex += rows;

    foundAnswer = blindSearch(x - 1, y, moves - 1, 0);
    if (foundAnswer)
      return 1;

    board[zeroIndex] = board[zeroIndex - rows];
    zeroIndex -= rows;
  }

  if (y > 0 && previousMove != 3) {
    // right
    board[zeroIndex] = board[zeroIndex + 1];
    zeroIndex++;

    foundAnswer = blindSearch(x, y - 1, moves - 1, 2);
    if (foundAnswer)
      return 1;

    board[zeroIndex] = board[zeroIndex - 1];
    zeroIndex--;
  }

  if (y < rows - 1 && previousMove != 2) {
    // left
    board[zeroIndex] = board[zeroIndex - 1];
    zeroIndex--;

    foundAnswer = blindSearch(x, y + 1, moves - 1, 3);
    if (foundAnswer)
      return 1;

    board[zeroIndex] = board[zeroIndex + 1];
    zeroIndex++;
  }

  if (x < cols - 1 && previousMove != 0) {
    // up
    board[zeroIndex] = board[zeroIndex - rows];
    zeroIndex -= rows;

    foundAnswer = blindSearch(x + 1, y, moves - 1, 1);
    if (foundAnswer)
      return 1;

    board[zeroIndex] = board[zeroIndex + rows];
    zeroIndex += rows;
  }

  return 0;
}

int main() {
  int i, x, y, current;

  for (i = 0; i < N; i++) {
    scanf("%d", &board[i]);
    if (!board[i])
      zeroIndex = i;
  }

  x = cols - (zeroIndex / rows) - 1;
  y = rows - (zeroIndex % cols) - 1;

  for (current = 0; current < 50; current++) {
    if (blindSearch(x, y, current, -1)) {
      printf("%d\n", current);
      return 0;
    }
  }
}
