#include <stdio.h>

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  int verticalValues[n];
  int horizontalValues[m];

  int i;

  for (i = 0; i < n; i++) {
    scanf("%d", &verticalValues[i]);
  }

  for (i = 0; i < m; i++) {
    scanf("%d", &horizontalValues[i]);
  }

  int currentVert = 0, currentHor = 0;
  int ans;
 
  ans = min(verticalValues[0], horizontalValues[m-1]);
  ans = max(ans, min(verticalValues[n-1], horizontalValues[0]));  
  
  for (i = 1 ; i < m - 1; i++) {
    int check = min(verticalValues[0], verticalValues[n-1]);
    ans = max(ans, min(check, horizontalValues[i]));
  }

  for (i = 1; i < n - 1; i++) {
    int check = min(horizontalValues[0], horizontalValues[m-1]);
    ans = max(ans, min(check, verticalValues[i]));
  }

  printf("%d\n", ans);
}

int max(int a, int b) {
  return a > b ? a : b;
}

int min(int a, int b) {
  return a < b ? a : b;
}
