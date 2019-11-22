#include<stdio.h>
#include<math.h>
 
typedef struct{
  double x;
  double y;
}point;
 
 
void koch (int d, point left, point right) {
  point s, t, u;
 
  if (d == 0) {
    printf("%lf %lf\n", left.x, left.y);
    return;
  }
 
  s.x = (2 * left.x + right.x) / 3;
  s.y = (2 * left.y + right.y) / 3;
  koch(d-1, left, s);
 
  t.x = (left.x + 2 * right.x) / 3;
  t.y = (left.y + 2 * right.y) / 3;
 
  u.x = ((t.x - s.x) - sqrt(3) * (t.y - s.y)) / 2 + s.x;
  u.y = ((t.y - s.y) + sqrt(3) * (t.x - s.x)) / 2 + s.y;
  
  koch(d-1, s, u);
  koch(d-1, u, t);
  koch(d-1, t, right);
 
  return;
}
 
 
int main() {
  int n;
  point start;
  point end;
  
  start.x = 0;
  start.y = 0;
 
  end.x = 100;
  end.y = 0;
  
  scanf("%d", &n);
 
  koch(n, start, end);
 
  printf("%lf %lf\n", end.x, end.y);
}
