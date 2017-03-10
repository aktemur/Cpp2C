#include <stdio.h>

typedef struct Point {
  int x;
  int y;
} Point;

void move(Point *self, int dx, int dy) {
  self->x += dx;
  self->y += dy;
}

int main() {
  Point p1;
  Point p2;

  p1.x = 0;
  p1.y = 0;
  p2.x = 3;
  p2.y = 8;
  printf("P1: %d, %d\n", p1.x, p1.y);
  printf("P2: %d, %d\n", p2.x, p2.y);
  
  move(&p1, 5, 4);
  move(&p2, -4, 9);
  printf("P1: %d, %d\n", p1.x, p1.y);
  printf("P2: %d, %d\n", p2.x, p2.y);
  
  return 0;
}
