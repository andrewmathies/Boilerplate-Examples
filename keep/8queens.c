#include <stdio.h>

int board[8][8];
int rows[8], cols[8];
int positive[15], negative[15];

void print()
{
  int i,j;

  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (board[i][j] && rows[i] != j)
	return;
    }
  }

  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (rows[i] == j)
	printf("Q");
      else
	printf(".");
    }
    printf("\n");
  }
}

void solve(int cur) {
  int i;

  if (cur == 8) {
    print();
    return;
  }

  for (i = 0; i < 8; i++) {
    if (!cols[i] && !positive[cur + i] && !negative[cur - i + 7]) {
      rows[cur] = i;
      cols[i] = 1;
      positive[cur + i] = 1;
      negative[cur - i + 7] = 1;

      solve(cur + 1);

      rows[cur] = 0;
      cols[i] = 0;
      positive[cur + i] = 0;
      negative[cur - i + 7] = 0;
    }
  }
}

int main() {
  int k, i, j, r, c;

  memset(board, 0, sizeof(board));
  memset(rows, 0, sizeof(rows));
  memset(cols, 0, sizeof(cols));
  memset(positive, 0, sizeof(positive));
  memset(negative, 0, sizeof(negative));


  scanf("%d", &k);

  for (i = 0; i < k; i++) {
    scanf("%d %d", &r, &c);
    board[r][c] = 1;
  }

  solve(0);
  
  /* attempt 1
   for (i = 2; i < 10; i++) {
    for (j = 2; j < 10; j++) {
      if ((rows[i-2] || cols[j-2]) && board[i][j] != 1)
	board[i][j] = 2;
      else if (board[i+1][j+1] == 1 || board[i-1][j+1] == 1 || board[i+1][j-1] == 1 || board[i-1][j-1] == 1)
	board[i][j] = 2;
    }
  }
  */
}
