#include <stdio.h>
#include <stdlib.h>

const int N = 8;
int length;

struct Node {
  int *board;
  int depth;
  int h;
  struct Node *parent;
};


// apparently most linkers don't link functions from math.h even if you include the header file,
// so I'm making bad sqrt for ints and ceiling functions to get around that
int sqrt(int n) {
  if (n == 0 || n == 1)
    return n;

  int i = 1, out = 1;
  while (out <= n) {
    i++;
    out = i*i;
  }
  
  return i - 1;
}

int ceil(double n) {
  if (n - (int) n > 0)
    return (int) n + 1;
  else
    return (int) n;
}


int heuristic(int *board) {
  int i, j, curx, counter = 0, dist = 0;

  for (i = 0; i < length; i++) {
    for (j = 0; j < length; j++) {
      if (board[counter] % 3 == 0)
	curx = 3;
      else
	curx = board[counter] % 3;
      
      if (board[counter] != 0)
	dist += abs(curx -(j + 1)) + abs(ceil((double) board[counter] / 3.0) - (i + 1));
      counter++;
    }
  }

  //printf("manhattan distance is: %d\n", dist);
  return dist;
}

int goal(struct Node node) {
  int i;

  for (i = 0; i < N; i++) {
    if (node.board[i] != i + 1)
      return 0;
  }

  return 1;
}

void aStarSearch(struct Node node) {  
  struct Node curNode = node;
  struct Node new, minNode;

  int i;

  while (1) {
    if (goal(minNode)) {
      printf("%d\n", minNode.depth);
      return;
    }
    
    //expand
    for (i = 0; i < (N + 1); i++) {
      if (curNode.board[i] == 0) {
	if (i % length != 0) {
	  //can expand left
	  new.board = shift(0, curNode.board);
	  new.depth = curNode.depth + 1;
	  new.h = heuristic(new.board);

	  if (new.depth + new.h < minNode.depth + minNode.h)
	    minNode = new;
	} else if ((i + 1) % length != 0) {
	  // can expand right
	  new.board = shift(1, curNode.board);
	  new.depth = curNode.depth + 1;
	  new.h = heuristic(new.board);

	  if (new.depth + new.h < minNode.depth + minNode.h)
	    minNode = new;
	}

	if (i / length != 0) {
	  // can expand up
	  new.board = shift(2, curNode.board);
	  new.depth = curNode.depth + 1;
	  new.h = heuristic(new.board);

	  if (new.depth + new.h < minNode.depth + minNode.h)
	    minNode = new;
	} else if (i / 3 != length - 1) {
	  // can expand down
	  new.board = shift(0, curNode.board);
	  new.depth = curNode.depth + 1;
	  new.h = heuristic(new.board);

	  if (new.depth + new.h < minNode.depth + minNode.h)
	    minNode = new;
	}


	break;
      }
    }

      //
  }
}

int main() {
  int i, j;
  length = sqrt(N + 1);  
  int *board = malloc((N + 1) * sizeof(int));

  //printf("printing input board:\n");

  for (i = 0; i < length * length; i++) {
    scanf("%d", &board[i]);
    /*
    if ((i + 1) % 3 == 0)
      printf("%d\n", board[i]);
    else
      printf("%d ", board[i]);
    */
  }

  
  struct Node root;
  root.board = board;
  root.depth = 0;
  root.h = heuristic(board);
  root.parent = NULL;
  
  aStarSearch(root);
}
