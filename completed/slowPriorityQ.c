#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  struct node *next;
  int val;
};

typedef struct node *Node;

Node head;

void insert(int num) {
  if (head->val == -1) {
    head->val = num;
    return;
  }

  Node temp;
  Node new = malloc(sizeof(struct node));
  new->val = num;
  new->next = NULL;

  if (num >= head->val) {
    temp = head;
    head = new;
    new->next = temp;
  }

  Node cur = head;
  
  while (1) {
    if (cur->next == NULL) {
      cur->next = new;
      break;
    } else if (num >= cur->next->val) {
      temp = cur->next;
      cur->next = new;
      new->next = temp;
      break;
    }

    cur = cur->next;
  }
}

void extract() {
  printf("%d\n", head->val);

  if (head->next != NULL) {
    Node temp = head->next;
    free(head);
    head = temp;
  }
}

int main() {
  head = malloc(sizeof(struct node));
  head->next = NULL;
  head->val = -1;
  
  char command[20];
  scanf("%s", command);

  while (strcmp(command, "end")) {
    if (!strcmp(command, "insert")) {
	int val;
	scanf("%d", &val);
	insert(val);
    } else {
      extract();
    }

    scanf("%s", command);
  }
}
