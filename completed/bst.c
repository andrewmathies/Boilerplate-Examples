#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  struct node *right;
  struct node *left;
  struct node *parent;
  int val;
};

typedef struct node Node;

Node *root;

void insert(Node *cur, int curVal) {
  if (cur->val == -1) {
    cur->val = curVal;
  }
  else if (curVal < cur->val) {
    if(cur->left == NULL) {
      Node *new = malloc(sizeof(Node));
      new->val = -1;
      new->parent = cur;
      new->left = NULL;
      new->right = NULL;
      //      printf("allocated a node\n");
      cur->left = new;
    }
    insert(cur->left, curVal);
  } else {
    if(cur->right == NULL) {
      Node *new = malloc(sizeof(Node));
      new->val = -1;
      new->parent = cur;
      new->left = NULL;
      new->right = NULL;
      //printf("allocated a node\n");
      cur->right = new;
    }  
    insert(cur->right, curVal);
  }
}

void inorder(Node *cur){
  if (cur == NULL)
    return;
  
  inorder(cur->left);
  printf(" %d", cur->val);
  inorder(cur->right);
}

void preorder(Node *cur){
  if (cur == NULL)
    return;
  
  printf(" %d", cur->val);
  preorder(cur->left);
  preorder(cur->right);
}

Node *find(Node *cur, int search) {
  //  printf("searching for %d\n", search);

  if (cur->val == search) {
    //    printf("yes\n");
    return cur;
  }
  
  if (cur == NULL) {
    printf("no\n");
    return NULL;
  }

  if (cur->val < search) {
    if (cur->right == NULL) {
      printf("no\n");
      return NULL;
    }
    find(cur->right, search);
  } else {
    if (cur->left == NULL) {
      printf("no\n");
      return NULL;
    }
    find(cur->left, search);
  }
}

/* attempt 1
void delete(Node *cur, int val) {
  if (cur->val == val && cur->parent != NULL) {
    int compare = cur->parent->val;

    if (cur->left == NULL && cur->right == NULL) {
      if (compare > val)
	cur->parent->left = NULL;
      else
	cur->parent->right = NULL;
    } 
    else if (cur->left == NULL) {
      if (compare > val)
	cur->parent->left = cur->right;
      else
	cur->parent->right = cur->right;
    }
    else if (cur->right == NULL) {
      if (compare > val)
	cur->parent->left = cur->left;
      else
	cur->parent->right = cur->left;
    } 
    else {
      // cur has two children  
    }
    free(cur);
  } else if (cur->val == val) {
    // we are deleting root
  }
  
  if (cur->val < val)
    delete(cur->right, val);
  else if (cur->val > val)
    delete(cur->left, val);
}
*/

Node *treeMinimum(Node *cur) {
  while (cur->left != NULL)
    cur = cur->left;

  return cur;
}

void swap(Node *node1, Node *node2){
  if (node1->parent == NULL)
    root = node2;
  
  else if (node1 == node1->parent->left)
    node1->parent->left = node2;
  
  else
    node1->parent->right = node2;
  
  if(node2 != NULL)
    node2->parent = node1->parent;
}

void delete(Node *cur) {
  Node *y;
  if (cur->left == NULL)
    swap(cur, cur->right);
  
  else if (cur->right == NULL)
    swap(cur, cur->left);
  
  else {
    y = treeMinimum(cur->right);
    
    if (y->parent != cur) {
      swap(y, y->right);
      y->right = cur->right;
      y->right->parent = y;
    }
  
    swap(cur, y);
    y->left = cur->left;
    y->left->parent = y;
  }
}

int main() {
  int commands, i, num;
  char com[20];

  root = malloc(sizeof(Node));
  root->val = -1;
  root->parent = NULL;
  root->left = NULL;
  root->right = NULL;

  scanf("%d", &commands);

  for (i = 0; i < commands; i++) {
    scanf("%s", &com);
    if (!strcmp(com, "insert")) {
      scanf("%d", &num);
      insert(root, num);
      //printf("inserted!\n");
    } else if (!strcmp(com, "print")) {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    } else if (!strcmp(com, "find")) {
      scanf("%d", &num);
      if (find(root, num))
	printf("yes\n");
    } else if (!strcmp(com, "delete")) {
      scanf("%d", &num);
      delete(find(root, num));
    }
  }
}
