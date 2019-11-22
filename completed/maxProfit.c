#include <stdio.h>
 
int main() {
  int n, maxProfit, cur, min, minI = 0, temp;
 
  scanf("%d", &n);
 
  for (int i = 0; i < n; ++i) {
    scanf("%d", &cur);
 
    if (i == 0)
      min = cur;
    else
      temp = cur - min;
 
    if (cur < min) {
      min = cur;
      minI = i;
    }
 
    if (i == 1)
      maxProfit = temp;
    else {
      if (temp > maxProfit && i != 0)
	maxProfit = temp;
    }
  }
 
  printf("%d\n", maxProfit);
  return 0;
}
