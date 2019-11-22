#include <stdio.h>
#include <string.h>

int alliance[55][55];
int emp[55][55];
int visited[55][55];
int n, m;

void fill(int x, int y, int curAlliance, int empire);

int main() {
  int i, j, p;

  memset(alliance, 0, sizeof(alliance));

  scanf("%d %d ", &n, &m);
  char line[50];
  int c;
  int num;

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      c = getchar();
      alliance[i][j] = c - '0';
    }
    scanf(" ", &c);
  }

  memset(emp, 0, sizeof(emp));
  memset(visited, 0, sizeof(visited));

  int brazico = 1, mexil = 2;

  emp[n-1][0] = brazico;
  emp[0][m-1] = mexil;

  fill(0, n-1, alliance[n-1][0], brazico);
  memset(visited, 0, sizeof(visited));
  fill(m-1, 0, alliance[0][m-1], mexil);
  memset(visited, 0, sizeof(visited));  
  
  int l, cur;
  scanf("%d", &l);

  for (i = 0; i < l; i++) {
    scanf("%d", &cur);
    if (i % 2 == 0) {
      fill(0, n-1, cur, brazico);
      memset(visited, 0, sizeof(visited));
    } else {
      fill(m-1, 0, cur, mexil);
      memset(visited, 0, sizeof(visited));
    }  
  }

  int brazicoCount = 0, mexilCount = 0;

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (emp[i][j] == brazico)
	brazicoCount++;
      else if (emp[i][j] == mexil)
	mexilCount++;
    }
  }

  printf("%d\n%d\n", brazicoCount, mexilCount);
}

void fill(int x, int y, int curAlliance, int empire) {
  if (x < 0 || y < 0 || x >= m || y >= n || visited[y][x])
    return;

  visited[y][x] = 1;

  int enemy = 3 - empire;

  if (emp[y][x] == enemy)
    return;

  if (alliance[y][x] == curAlliance) {
    emp[y][x] = empire;
  }

  if (emp[y][x] == empire) {
    fill(x+1, y, curAlliance, empire);
    fill(x-1, y, curAlliance, empire);
    fill(x, y-1, curAlliance, empire);
    fill(x, y+1, curAlliance, empire);
  }  
}
