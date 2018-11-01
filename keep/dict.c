#include<stdio.h>
#include<string.h>

#define M 1000005
#define L 14

char H[M][L]; /* Hash Table */

int getChar(char ch) {
  if (ch == 'A') 
    return 1;
  else if (ch == 'C') 
    return 2;
  else if (ch == 'G') 
    return 3;
  else if (ch == 'T') 
    return 4;
}

// hash function
long long getKey(char str[]) {
  long long sum = 0, p = 1, i;

  for (i = 0; i < strlen(str); i++) {
    sum += p * (getChar(str[i]));
    p *= 5;
  }

  return sum;
}

int h1(int key) { 
  return key % M; 
}

int h2(int key) { 
  return 1 + (key % (M - 1)); 
}

int find(char str[]) {
  long long cur, key, counter = 0;

  key = getKey(str);

  while (1) {
    cur = (h1(key) + counter * h2(key)) % M;
    
    if (!strcmp(str, H[cur]))
      return 1;
    if (!strlen(H[cur]))
      return 0;

    counter++;
  }
}

void insert(char str[]) {
  long long cur, key, counter = 0;

  key = getKey(str);

  while (1) {
    cur = (h1(key) + counter * h2(key)) % M;
    
    if (!strcmp(str, H[cur]))
      return;
    if (!strlen(H[cur])) {
      strcpy(H[cur], str);
      return;
    }
    
    counter++;
  }
}

int main() {
  int i, n, h;
  char str[L], com[9];

  for (i = 0; i < M; i++)
    H[i][0] = '\0';
    
  scanf("%d", &n);
    
  for (i = 0; i < n; i++ ) {
    scanf("%s %s", com, str);
    
    if (!strcmp(com, "insert")) {
      insert(str);
    } else {
      if (find(str))
	printf("yes\n");
      else
	printf("no\n");
    }
  }
}


/*
----------------------------------------------
I used the provided template to start this one
----------------------------------------------
*/
