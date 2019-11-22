#include <stdio.h>

int main() {
  int n;

  scanf("%d", &n);

  int i, sum = 0;

  for (i = 1; i <= n; i++) {
    sum += i;
  }

  if (sum % 2 == 0)
    printf("black\n");
  else
    printf("grimy\n");
}
