#include <stdio.h>

int coordinates[1005][1005];

int main() {
  int n, i, j, out = 0;
  int x1, x2, y1, y2;
  int xMin = 1000, xMax = 0, yMin = 0, yMax = 1000;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    coordinates[x1][y1]++;
    coordinates[x2][y2]++;
    coordinates[x1][y2]--;
    coordinates[x2][y1]--;

    if (x1 < xMin)
      xMin = x1;
    if (x2 > xMax)
      xMax = x2;
    if (y1 < yMin)
      yMin = y1;
    if (y2 > yMax)
      yMax = y2;
  }
  
  for (i = xMin; i < xMax + 1; i++) {
    for (j = yMin; j < yMax + 1; j++) {
      if (i)
	coordinates[i][j] += coordinates[i - 1][j];
      if (j)
	coordinates[i][j] += coordinates[i][j - 1];

      if (i && j)
	coordinates[i][j] -= coordinates[i - 1][j - 1];

      if (coordinates[i][j] > out)
	out = coordinates[i][j];
    }
  }

  printf("%d\n", out);
}
