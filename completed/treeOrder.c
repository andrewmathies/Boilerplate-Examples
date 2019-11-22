#include <stdio.h>

int search(int arr[], int val, int n)
{
  int i;

  for (i = 0; i < n; i++)
    if (arr[i] == val)
      return i;
  return -1;
}

int postorder[45];

int N;


void po(int inorder[], int preorder[], int n) {

  int rootIndex = search(inorder, preorder[0], n);

  if (rootIndex > 0)
    po(inorder, preorder + 1, rootIndex);

  if (rootIndex != n - 1)
    po(inorder + rootIndex + 1, preorder + rootIndex + 1, n - rootIndex - 1);

  if (n == N)
    printf("%d\n", preorder[0]);
  else
    printf("%d ", preorder[0]);
}

int main() {
  int i;

  scanf("%d", &N);

  int preorder[N];
  int inorder[N];

  for (i = 0; i < N; i++)
    scanf("%d", &preorder[i]);

  for (i = 0; i < N; i++)
    scanf("%d", &inorder[i]);

  po(inorder, preorder, N);
}
