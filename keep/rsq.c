#include <stdio.h>

int main() {
  int n, q, i, j, command, x, y, sum;

  scanf("%d %d", &n, &q);

  int nums[n];
  memset(nums, 0, sizeof(nums));

  for (i = 0; i < q; i++) {
    scanf("%d %d %d", &command, &x, &y);
    if (command) {
      sum = 0;
      for (j = x - 1; j < y; j++)
	sum += nums[j];
      
      printf("%d\n", sum);
    } else {
      nums[x - 1] += y;
    }
  }
}
