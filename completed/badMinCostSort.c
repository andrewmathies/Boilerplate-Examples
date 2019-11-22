#include <stdio.h>

int main() {
  int i,j;
  int n, swapTotal = 0;

  scanf("%d", &n);

  int a[n];

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (j = 0; j < n-1; j++)  {
    int min = j;

    for (i = j+1; i < n; i++) {
      if (a[i] < a[min]) {
	min = i;
      }
    }
    
    if (min != j) {
      swapTotal += a[j] + a[min];
      int temp = a[j];
      a[j] = a[min];
      a[min] = temp;
    }
  }

  printf("%d\n", swapTotal);
}
