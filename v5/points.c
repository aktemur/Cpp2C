#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Point {
  void (*print)(struct Point *);
  int x;
  int y;
} Point;

void Point_move(Point *self, int dx, int dy) {
  self->x += dx;
  self->y += dy;
}

void Point_print(Point *self) {
  printf("P: %d, %d\n", self->x, self->y);
}

void Point_init(Point *self, int x, int y) {
  self->x = x;
  self->y = y;
  self->print = &Point_print;
}

typedef struct ColorPoint {
  void (*print)(struct ColorPoint *);
  int x;
  int y;
  int color;
} ColorPoint;

void ColorPoint_setColor(ColorPoint *self, int c) {
  self->color = c;
}

void ColorPoint_print(ColorPoint *self) {
  printf("CP: %d, %d, %d\n", self->x, self->y, self->color);
}

void ColorPoint_init(ColorPoint *self, int x,
                     int y, int color) {
  Point_init((Point *)self, x, y); // Casting works like magic
  self->color = color;
  self->print = &ColorPoint_print;
}

int main() {
  srand(time(NULL));
  int r = rand();

  Point *p;
  if (r % 2 == 0) {
    Point *temp = (Point *)malloc(sizeof(Point));
    Point_init(temp, 0, 0);
    p = (Point *)temp;
  } else {
    ColorPoint *temp = (ColorPoint *)malloc(sizeof(ColorPoint));
    ColorPoint_init(temp, 6, 9, 255);
    p = (Point *)temp;
  }

  p->print(p);         // dynamic dispatch
  Point_move(p, 5, 4); // static dispatch
  p->print(p);         // dynamic dispatch
  
  return 0;
}
