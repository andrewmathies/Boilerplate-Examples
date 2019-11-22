#include <stdio.h>
#include <string.h>

int cur, heap[2000000];
 
void maxHeapify (int in) {
  int left, right, max, temp;
  left = 2 * in;
  right = (2 * in) + 1;
 
  if (left <= cur && heap[left] > heap[in])
    max = left;
  else
    max = in;
  
  if (right <= cur && heap[right] > heap[max])
    max = right;
 
  if (max != in) {
    temp = heap[in];
    heap[in] = heap[max];
    heap[max] = temp;
    maxHeapify(max);
  }
}

int extract() {
  int maxVal;
  
  if(cur < 1)
    return -1;
  
  maxVal = heap[1];
  heap[1] = heap[cur--];
  maxHeapify(1);
  
  return maxVal;
}

void increaseVal(int i, int val) {
  int temp;
  
  if(val < heap[i])
    return;
  
  heap[i] = val;
  
  while (i > 1 && heap[i/2] < heap[i]) {
    temp = heap[i];
    heap[i] = heap[i/2];
    heap[i/2] = temp;
    i = i/2;
  }
}

void insert(int val) {
  heap[++cur] = -1;
  increaseVal(cur, val);
}

int main() {
  int val;
  char command[20];

  scanf("%s", command);

  while (strcmp(command, "end")) {
    if (!strcmp(command, "insert")) {
      scanf("%d", &val);
      insert(val);
    } else
      printf("%d\n", extract());
    
    scanf("%s", command);
  }
}
