#include <stdio.h>

char suits[100005];
int num[100005];

int partition(int A[], int p, int r) {
  int x = A[r];
  int i = p - 1;
  int j, temp;
  char tempLetter;

  for (j = p; j < r; j++) {
    if (num[A[j]] <= num[x]) {
      i++;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  
  i++;
  temp = A[i];
  A[i] = A[r];
  A[r] = temp;
  
  return i;
}

void quicksort(int A[], int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

int isStable(int A[], int n) {
  int i;
 
  for(i = 2; i <= n; ++i) {
    if(num[A[i-1]] == num[A[i]] && A[i-1] > A[i]) 
      return 0;
  }

  return 1;
}


int main() {
  int n, i;
  char dump;

  scanf("%d%c", &n, &dump);
  int C[100005];

  for (i = 1; i < n + 1; ++i) {
    scanf("%c%c%d%c", &suits[i], &dump, &num[i], &dump);
    C[i] = i;
  }

  quicksort(C, 1, n);
  
  if (isStable(C, n))
      printf("Stable\n");
  else
    printf("Not stable\n");

  for (i = 1; i < n + 1; ++i) {
    printf("%c %d\n", suits[C[i]], num[C[i]]);
  }
}
