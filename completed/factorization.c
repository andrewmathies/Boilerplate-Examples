#include <stdio.h>
#include <math.h>

int main() {
  int i, j;
  long long n;
  scanf("%lld", &n);

  int counter = 0;
  int bound = n / (int) pow(2, 19);
  //printf("bound is: %d\n", bound);
  
  for (i = 2; i < bound + 1; i++) {
    if (isPrime(i)) {
      while (n % i == 0) {
	//printf("i is: %d\n", i);
	n /= i;
	counter++;
      } 
    } 
  }

  if (counter == 20)
    printf("Yes\n");
  else
    printf("No\n");
}

int isPrime(int a) {
  int i; 
  if (a == 2)
    return 1;
  if ((a % 2) == 0)
    return 0;
  
  for (i = 3; i*i <= a; i += 2)
    {
      if ((a % i) == 0) 
	return 0;
    };
  
  return 1;
}
