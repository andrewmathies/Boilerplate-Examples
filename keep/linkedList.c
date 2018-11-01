#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int val;
  struct Node *prev;
  struct Node *next;
};

struct Node *root = NULL;
struct Node *tail = NULL;

void insert(struct Node **head, int val) {
  struct Node *new = malloc(sizeof(struct Node));

  new->val = val;
  new->next = *head;
  new->prev = NULL;

  if (*head != NULL)
    (*head)->prev = new;
  else {
    root = new;
    tail = new;
  }

  *head = new;
}

void delete(struct Node **head, struct Node *node) {
  if (*head == NULL || node == NULL)
    return;

  if (*head == node)
    *head = node->next;

  if (node->next != NULL)
    node->next->prev = node->prev;
  else
    tail = node->prev;

  if (node->prev != NULL)
    node->prev->next = node->next;

  free(node);

  return; 
}

struct Node *find(struct Node **head, int val) {
  if (*head == NULL)
    return NULL;

  struct Node *cur = *head;

  while (cur != NULL) {
    if (cur->val == val)
      return cur;
    cur = cur->next;
  }

  return NULL;
}

void deleteFirst(struct Node **head) {
  if (*head == NULL)
    return;

  delete(head, find(head, (*head)->val));
}

void deleteLast() {
  if (root == NULL || tail == NULL)
    return;
  
  struct Node *node = tail;
  
  if (node->prev != NULL) {
    node->prev->next = NULL;
    tail = node->prev;
  } else {
    root = NULL;
  }

  free(node);
}

void printList() {
  if (root == NULL)
    return;

  struct Node *cur = root;

  // print everything in list
  while (cur->next != NULL) {
    printf("%d ", cur->val);
    cur = cur->next;
  }

  if (cur != NULL)
    printf("%d\n", cur->val);
}

int main() {
  int n, i, element;
  char command[15];

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%s", &command);

    if (!strcmp(command, "insert")) {
      scanf("%d", &element);
      insert(&root, element);
    } else if (!strcmp(command, "deleteFirst")) {
      deleteFirst(&root);
    } else if (!strcmp(command, "deleteLast")) {
      deleteLast(&root);
    } else if (!strcmp(command, "delete")) {
      scanf("%d", &element);
      delete(&root, find(&root, element));
    }
  }

  printList();
}
