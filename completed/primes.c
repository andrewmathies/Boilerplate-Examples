#include <stdio.h>
 
int isPrime(int k);
 
int main() {
  int n, k, count = 0;
 
  scanf("%d", &n);
 
  for (int i = 0; i < n; ++i) {
    scanf("%d", &k);
 
    if (isPrime(k))
      count++;
  }
 
  printf("%d\n", count);
 
  return 0;
}
 
int isPrime(int k) {
  if (k == 2) {
    return 1;
  } else if (k % 2 == 0){
    return 0;
  }
 
  for (int i = 3; i < k && i <= 10000; i+=2) {
    if (k % i == 0)
      return 0;
  }
  return 1;
}
