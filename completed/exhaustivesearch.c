#include <stdio.h>

int n;
int arr[25];

int solve(int n1, int n2) {
  if (n2 == 0)
    return 1;
  if (n1 == n)
    return 0;

  return solve(n1 + 1, n2) + solve(n1 + 1, n2 - arr[n1]);
}

int main() {
  int i, nQ;

  scanf("%d", &n);

  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  scanf("%d", &nQ);

  int queries[nQ];

  for (i = 0; i < nQ; i++)
    scanf("%d", &queries[i]);

  for (i = 0; i < nQ; i++) {
    if (solve(0, queries[i]))
      printf("yes\n");
    else
      printf("no\n");
  }
}
