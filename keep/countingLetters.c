#include <stdio.h>

int main() {
  char current;
  int letters[26];
  memset(letters, 0, sizeof(letters));

  while (1) {
    if (scanf("%c", &current) == EOF)
      break;

    if (current == 44 || current == 46)
      continue;

    if (current > 96)
      letters[current - 97]++;
    else
      letters[current - 65]++;
  }

  int i;

  for (i = 0; i < 26; i++) {
    printf("%c : %d\n", i + 97, letters[i]);
  }

  return 0;
}
