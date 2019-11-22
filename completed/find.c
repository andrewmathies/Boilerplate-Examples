#include <stdio.h>
#include <string.h>

int main() {
  char word[11];
  char current[20];

  scanf("%s", &word);

  int n = 0, i, wordNum = 0;

  while (1) {
    scanf("%s", &current);
    
    if (!strcmp(current, "END_OF_TEXT"))
      break;

    for (i = 0; i < strlen(word); i++) {
      if (word[i] != current[i] && word[i] + 32 != current[i] && word[i] - 32 != current[i])
	break;
      if (i == strlen(word) - 1 && strlen(word) == strlen(current)) {
	n++;
      }
    }
    wordNum++;
  }

  printf("%d\n", n);

  return 0;
}
