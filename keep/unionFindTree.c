#include <stdio.h>

int nums[100005];

int parent(int cur) {
  if (nums[cur] == cur)
    return cur;
  else {
    nums[cur] = parent(nums[cur]);
    return nums[cur];
  }
}

int same(int n1, int n2) {
  if (parent(n1) == parent(n2))
    printf("1\n");
  else
    printf("0\n");
}

void unite(int n1, int n2) {
  nums[parent(n1)] = parent(n2);
}

int main() {
  int n, q, i, command, x, y;

  scanf("%d %d", &n, &q);

  for (i = 0; i < n; i++)
    nums[i] = i;

  for (i = 0; i < q; i++) {
    scanf("%d %d %d", &command, &x, &y);
    
    if (command) {
      same(x, y);
    } else {
      unite(x, y);
    }
  }
}
