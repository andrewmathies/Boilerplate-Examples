#include <stdio.h>

int n, k, max = 0;
int weights[100005];

/*
int try(int num) {
  int i, curSum = 0, trucks = 0;  

  for (i = 0; i < n; i++) {
    if (curSum == num) {
      curSum = 0;
      trucks++;
    }

    curSum += weights[i];

    printf("i: %d, curSum: %d, trucks: %d\n", i, curSum, trucks);
    
    if (i == n - 2) {
      if (curSum + weights[i + 1] > num)
	trucks += 2;
      else
	trucks++;
      
      break;
    }

    if (curSum + weights[i+1] > num) {
      trucks++;
      curSum = 0;
    }
  }

  printf("final trucks: %d\n", trucks);

  if (trucks > k)
    return 0;
  else
    return 1;
}
*/

int try(int num) {
  int i, ans = 1, cur = num;

  if (num < max)
    return 0;

  for (i = 0; i < n; i++) {
    if (cur >= weights[i])
      cur -= weights[i];
    else {
      ans++;
      cur = num - weights[i];
    }
  }

  if (ans <= k)
    return 1;
  
  return 0;
}

int main() {
  int i, left = 0, right = 1000000000, middle;//sum = 0;

  scanf("%d %d", &n, &k);

  for (i = 0; i < n; i++) {
    scanf("%d", &weights[i]);
    if (weights[i] > max)
      max = weights[i];
    //sum += weights[i];
  }

  //minOut = sum / k;
  //printf("starting value %d\n", minOut);

  while (right > left + 1) {
    middle = (left + right) / 2;
    if (try(middle))
      right = middle;
    else
      left = middle;
  }
  
  printf("%d\n", right);
}
