#include <stdio.h>

int neighbors[105][105];
int nSucc[105];

int main() {
  int n, curQ = 0, d, i, j, dump, index;
  memset(neighbors, 0, sizeof(neighbors));
  memset(nSucc, 0, sizeof(nSucc));

  scanf("%d", &n);

  for (i = 1; i < n+1; i++) {
    scanf("%d %d", &dump, &nSucc[i]);
    for (j = 0; j < nSucc[i]; j++) {
      scanf("%d", &neighbors[i][j]);
    }
  }

  int qlen[2];
  int q[2][105];
  
  memset(qlen, 0, sizeof(qlen));

  q[0][0] = 1;
  qlen[0]++;

  int mind[105];
  for (i = 0; i < 105; i++) {
    mind[i] = 10000;
  }
  mind[1] = 0;

  for (d = 1; qlen[curQ] > 0; d++) {
    for (i = 0; i < qlen[curQ]; i++) {
      index = q[curQ][i];
      for (j = 0; j < nSucc[index]; j++) {
	if (d < mind[neighbors[index][j]]) {
	  mind[neighbors[index][j]] = d;
	  q[1-curQ][qlen[1-curQ]++] = neighbors[index][j];
	}
      }
    }
    qlen[curQ] = 0;
    curQ = 1 - curQ;
  }

  for (i = 1; i < n+1; i++) {
    if (mind[i] == 10000)
      printf("%d %d\n", i, -1);
    else
      printf("%d %d\n", i, mind[i]);
  }
}
