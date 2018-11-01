#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  int x, a, b;
  char s[100];

  int stack[200];
  int current = 0;

  while(scanf("%s", &s) != EOF) {
    if ( s[0] == '+' ){
      a = stack[--current];
      b = stack[--current];
      stack[current++] = a + b;
    } else if ( s[0] == '-' ){
      a = stack[--current];
      b = stack[--current];
      stack[current++] = b - a;
    } else if ( s[0] == '*' ){
      a = stack[--current];
      b = stack[--current];
      stack[current++] = a * b;
    } else {
      x = atoi(s);
      stack[current++] = x;
    }
    //printf("current top of stack is %d\n", stack[current - 1]);
  }

  printf("%d\n", stack[0]);
}
