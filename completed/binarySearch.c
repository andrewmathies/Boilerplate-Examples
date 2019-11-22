#include <stdio.h>

int arr1[100005];
int arr2[50005];

int main() {
  int n, i, q, cur, index, num, total = 0;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &arr1[i]);
  }

  scanf("%d", &q);

  for (i = 0; i < q; i++) {
    scanf("%d", &arr2[i]);
  }

  int left, right;
  int counter = 0;

  for (i = 0; i < q; i++) {
    cur = arr2[i];
    left = 0;
    right = n - 1;

    while (left <= right) {
      index = (left + right) / 2;
      num = arr1[index];

      //printf("S num: %d, T num: %d, index: %d\n", num, cur, index);

      if (num == cur) {
	total++;
	break;
      }

      if (cur > num)
	left = index + 1;
      else
	right = index - 1;

      if (index <= 0) {
	if (cur == arr1[0])
	  total++;
	break;
      }

      if (index >= n - 1) {
	if (cur == arr1[n - 1])
	  total++;
	break;
      }
    }
  }

  printf("%d\n", total);
}
