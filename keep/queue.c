#include <stdio.h>
#include <stdlib.h>

struct Queue {
  int front, end, length, maxLength;
  int *arr
};

struct Queue *init(int maxLength) {
  struct Queue *new = malloc(sizeof(struct Queue));
  new->maxLength = maxLength;
  new->front = new->length = 0;
  new->end = maxLength - 1;
  new->arr = malloc(maxLength * sizeof(int));
  return new;
}

void enQ(struct Queue *q, int val) {
  if (q->maxLength == q->length) {
    printf("queue is full!\n");
    return;
  }
  
  q->end = (q->end + 1) % q->maxLength;
  q->arr[q->end] = val;
  //printf("enqueued %d\n", val);
  q->length++;
}

int deQ(struct Queue *q) {
  if (!q->length) {
    //printf("queue is empty!\n");
    return 0;
  }
  
  int val = q->arr[q->front];
  //printf("dequeued %d\n", val);
  q->front = (q->front + 1) % q->maxLength;
  q->length--;
  
  return val;
}

int main() {
  int n, quantum, i;

  scanf("%d %d", &n, &quantum);
  struct Queue *q = init(n + 1);
  
  int times[n + 1];
  char names[n + 1][10];

  for (i = 1; i < n + 1; i++) {
    scanf("%s %d", &names[i], &times[i]);
    enQ(q, i);
  }

  int curProcess, t = 0;

  while (1) {
    curProcess = deQ(q);

    if (!curProcess)
      break;

    if (times[curProcess] > 0) {
      for (i = 0; i < quantum; i++) {
	times[curProcess]--;
	t++;
	if (times[curProcess] <= 0) {
	  printf("%s %d\n", names[curProcess], t);
	  break;
	}
      }
      
      enQ(q, curProcess);
    }
  }
}
