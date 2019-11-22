#include <stdio.h>

int times[100001];

void add(int start, int end, int num) {
  int i;

  for (i = start; i < end; i++)
    times[i] += num;
}

int main() {
  int n, T, arrive, leave, i, out = 0;

  scanf("%d %d", &n, &T);
  scanf("%d %d", &arrive, &leave);

  if (50000 > leave - arrive) {
    memset(times, 0, sizeof(times));
    add(arrive, leave, 1);

    for (i = 1; i < n; i++) {
      scanf("%d %d", &arrive, &leave);
      add(arrive, leave, 1);
    }
  } else {
    for (i = 0; i < T; i++)
      times[i] = n;

    add(0, arrive, -1);
    add(leave, T, -1);
    
    for (i = 1; i < n; i++) {
      scanf("%d%d", &arrive, &leave);
      add(0, arrive, -1);
      add(leave, T, -1);
    }
  }
  
  for (i = 0; i < T; i++) {
    if (out < times[i])
      out = times[i];
  }
  
  printf("%d\n", out);
}
