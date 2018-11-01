#include <stdio.h>

int neighbors[105][105];
int times[105][2];
int n;

int dfs(int curTime, int node) {
  int i, j;

  times[node][0] = curTime;
  neighbors[node][0] = 0;

  for (i = 1; i < n + 1; i++) {
    if (neighbors[node][i] && neighbors[i][0]) {
      for (j = 0; j < n; j++)
	neighbors[j][i] = 0;
      curTime = dfs(curTime + 1, i);
    }
  }

  times[node][1] = ++curTime;
  return curTime;
}


int main() {
  int i, u, k, j, num, timestamp = 0;

  memset(neighbors, 0, sizeof(neighbors));
  memset(times, 0, sizeof(times));
  
  scanf("%d", &n);

  for (i = 1; i < n + 1; i++) {
    neighbors[i][0] = 1;
  }


  for (i = 1; i < n + 1; i++) {
    scanf("%d %d", &u, &k);

    for (j = 0; j < k; j++) {
      scanf("%d", &num);
      neighbors[i][num] = 1;
    }
  }

  for (i = 1; i < n + 1; i++) {
    if (neighbors[i][0])
      timestamp = dfs(timestamp + 1, i);
  }

  for (i = 1; i < n + 1; i++)
    printf("%d %d %d\n", i, times[i][0], times[i][1]);
}

