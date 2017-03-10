#include <stdio.h>

typedef struct Point {
  int x;
  int y;
} Point;

void move(Point *self, int dx, int dy) {
  self->x += dx;
  self->y += dy;
}

void Point_init(Point *self, int x, int y) {
  self->x = x;
  self->y = y;
}

int main() {
  Point p1;
  Point_init(&p1, 0, 0);
  Point p2;
  Point_init(&p2, 3, 8);

  printf("P1: %d, %d\n", p1.x, p1.y);
  printf("P2: %d, %d\n", p2.x, p2.y);
  
  move(&p1, 5, 4);
  move(&p2, -4, 9);
  printf("P1: %d, %d\n", p1.x, p1.y);
  printf("P2: %d, %d\n", p2.x, p2.y);
  
  return 0;
}
