#include <stdio.h>
#include <limits.h>

int n;
int mins[262143];

void update(int arrIndex, int val) {
  mins[arrIndex] = val;

  while (arrIndex > 1) {
    arrIndex /= 2;
    mins[arrIndex] = min(mins[arrIndex * 2], mins[arrIndex * 2 + 1]);
  }
}

int min(int n1, int n2) {
  return n1 < n2 ? n1 : n2;
}

int find(int node, int l, int r, int i, int j) {
  if (r < i || l > j)
    return INT_MAX;
  else if (l >= i && r <= j)
    return mins[node];
  else {
    int lValue = find(2*node, l, (l + r) / 2, i, j);
    int rValue = find((2*node)+1, (l + r) / 2 + 1, r, i, j);

    return lValue < rValue ? lValue : rValue;
  }
}

int main() {
  int q, i, j, query, counter, cur, powerOf2[18], lengthOfBottomRow;

  scanf("%d %d", &n, &q);

  for (i = 0; i < 19; i++) {
    cur = 2;

    for (j = 0; j < i; j++)
      cur *= 2;

    powerOf2[i] = cur;

    if (i) {
      if (powerOf2[i-1] <= 2 * n && powerOf2[i] >= 2 * n) {
	lengthOfBottomRow = powerOf2[i-1];
	break;
      }
    }
  }

  for (counter = 1; counter < lengthOfBottomRow * 2; counter++)
    mins[counter] = INT_MAX;

  for (counter = 0; counter < q; counter++) {
    scanf("%d %d %d", &query, &i, &j);

    if (query)
      printf("%d\n", find(1, lengthOfBottomRow, (lengthOfBottomRow * 2) - 1, i + lengthOfBottomRow, j + lengthOfBottomRow));
    else {
      update(i + lengthOfBottomRow, j);
    }
  }
}
