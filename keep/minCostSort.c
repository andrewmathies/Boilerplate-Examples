#include <stdio.h>
#include <stdlib.h>

int input[1005], copy[1005], visible[1005];
int counts[10005];

int min(int n1, int n2) {
  return n1 < n2 ? n1 : n2;
}

int minCost(int n) {
  int i, cur, temp1, temp2, check, output = 0, max = 10001;
  
  for (i = 0; i < n; i++) {
    if (visible[i])
      continue;

    cur = i;
    temp1 = 0;
    temp2 = 0;
    max = 10001;

    while (!visible[cur]) {
      visible[cur] = 1;
      temp1++;
      check = input[cur];

      if (check < max)
	max = check;

      temp2 += check;
      cur = counts[check];
    }

    output += min(temp2 + (temp1 - 2) * max, max + temp2 + (temp1 + 1) * copy[0]); 
  } 

  return output;
}

int qsAscendHelper(const void *v1, const void *v2) {
  int n1 = *(int *) v1;
  int n2 = *(int *) v2;

  if (n1 < n2)
    return -1;

  else if (n1 > n2)
    return 1;

  return 0;
}

int main() {
  int n, i;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &input[i]);
    copy[i] = input[i];   
  }
  
  memset(visible, 0, sizeof(visible));
  memset(counts, 0, sizeof(counts));

  qsort(copy, n, sizeof(int), qsAscendHelper);
  
  for (i = 0; i < n; i++)
    counts[input[i]] = i;

  printf("%d\n", minCost(n));
}
