#include <stdio.h>
#include <ctype.h>

void sortColors(int[]);
int combination(int, int);

int main(void)
{
  int i = 0;
  int k;
  char holder;
  int colors[26] = {};
  while (1)
    {
      scanf("%c", &holder);
      if (!isalpha(holder))
	break;
      colors[holder - 'a']++;
    }
  scanf("%d", &k);
  sortColors(colors);
  int endvalue = colors[k-1], comboN = 0, sum = 0, comboK = 0;
  for (i = 0; i < 26; i++)
    if (i < k)
      {
	sum += colors[i];
	if (colors[i] == endvalue)
	  {
	    comboK++;
	    comboN++;
	  }
      }
    else
      {
	if (endvalue == colors[i])
	  comboN++;
	else
	  break;
      }
  printf("%d %d\n", sum, endvalue ? combination(comboN, comboK) : 1);
}

void sortColors(int original[])
{
  int i, j, holder;
  for (i = 0; i < 26; i++)
    for (j = 25; j > i; j--)
      if (original[j] > original[j-1])
	{
	  holder = original[j];
	  original[j] = original[j-1];
	  original[j-1] = holder;
	}
}

int combination(int n, int k)
{
  int i, output = 1;
  if (k > n/2)
    k = n-k;
  for (i = 1; i <= k; i++)
    {
      output *= n-i+1;
      output /= i;
    }
  return output;
}

