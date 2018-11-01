#include <stdio.h>
#include <stdlib.h>

int *r, *c;
int cache[105][105];

int main() {
  int n, i;

  scanf("%d", &n);

  r = (int *) malloc(sizeof(int)*n);
  c = (int *) malloc(sizeof(int)*n);
  memset(cache, -1, sizeof(cache));

  for(i = 0; i < n; i++) {
    scanf("%d %d", &r[i], &c[i]);
  }

  printf("%d\n", cost(0, n-1));

  free(r);
  free(c);

  return 0;
}

int cost(int a, int b) {
  if (a == b) {
    return 0;
  }
  if (cache[a][b] == -1) {
    int total, m;
    cache[a][b] = 100000000;

    for(m = a; m < b; m++) {
      total = cost(a, m) + cost(m+1, b) + r[a]*c[m]*c[b];
      if (total < cache[a][b])
	cache[a][b] = total;
    }
  }
  return cache[a][b];
}
