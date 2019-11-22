#include<stdio.h>

long long nums1[270000], nums2[270000], leaves;

void help(int node, int left, int right) {
  if (nums2[node] == 0)
    return;

  nums1[node] += nums2[node] * (right - left);
  
  if (right - left > 1) {
    nums2[node * 2] += nums2[node];
    nums2[node * 2 + 1] += nums2[node];
  }

  nums2[node] = 0;
}

void add(int nl, int nr, int val, int node, int left, int right) {
  help(node, left, right);

  if (right <= nl || left >= nr)
    return;
  else if (left >= nl && right <= nr) {
    nums2[node] += val;
    help(node, left, right);
  } else {
    add(nl, nr, val, node * 2, left, (left + right) / 2);
    add(nl, nr, val, node * 2 + 1, (left + right) / 2, right);
    nums1[node] = nums1[node * 2] + nums1[node * 2 + 1];
  }
}

long long get(int nl, int nr, int node, int left, int right) {
  help(node, left, right);
  
  if (left >= nr || right <= nl)
    return 0;
  else if (left >= nl && right <= nr)
    return nums1[node];
  else
    return get(nl, nr, node * 2, left, (left + right) / 2) + get(nl, nr, node * 2 + 1, (left + right) / 2, right);
}

int main() {
  int n, q, i, x, y, z, command, d[100010] = {};
  
  scanf("%d %d", &n, &q);

  for(leaves = 1; leaves < n; leaves *= 2);

  for(i = 0; i < leaves; i++) {
    if (i < n)
      nums1[leaves + i] = d[i];
    else
      nums1[leaves + i] = 0;
  }

  for (i = leaves - 1; i; i--)
    nums1[i] = nums1[i * 2] + nums1[i * 2 + 1];

  for(i = 0; i < q; i++) {
    scanf("%d %d %d", &command, &x, &y);
    
    if (command)
      printf("%lld\n", get(x - 1, y, 1, 0, leaves));
    else {
      scanf("%d", &z);
      add(x - 1, y, z, 1, 0, leaves);
    }
  }
}
