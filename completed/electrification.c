#include <stdio.h>

int main() {
  int n, powered, i, j;
  scanf("%d", &n);
  scanf("%d", &powered);

  int power[n];
  memset(power, 0, sizeof(power));

  int val;

  for (i = 0; i < powered; i++) {
    scanf("%d", &val);
    power[val - 1] = 1;
  }

  int edges[n][n];

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &edges[i][j]);
    }
    //    if (power[i])
    //printf("%d city is powered\n", i + 1);
  }

  int ans = 0, minN, k;

  for (i = 0; i < n - powered; i++) {
    int minEdge = 10000000;
    for (j = 0; j < n; j++) {
      if (!power[j])
	continue;
      for (k = 0; k < n; k++) {
	if (edges[j][k] < minEdge && !power[k]) {
	  minEdge = edges[j][k];
	  minN = k;
	}
      }
    }

    power[minN] = 1;
    //printf("powering %d\n", minN+1);
    ans += minEdge;
  }

  printf("%d\n", ans);
  return 0;
}
