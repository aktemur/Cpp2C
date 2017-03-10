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

typedef struct ColorPoint {
  int x;
  int y;
  int color;
} ColorPoint;

// The definition above is essentially the same as
// struct ColorPoint {
//   struct Point super;
//   int color;
// };

void setColor(ColorPoint *self, int c) {
  self->color = c;
}

void ColorPoint_init(ColorPoint *self, int x,
                     int y, int color) {
  Point_init((Point *)self, x, y); // Casting works like magic
  self->color = color;
}


int main() {
  Point p;
  Point_init(&p, 0, 0);
  printf("P: %d, %d\n", p.x, p.y);
  move(&p, 5, 4);
  printf("P: %d, %d\n", p.x, p.y);

  ColorPoint cp;
  ColorPoint_init(&cp, 6, 9, 255);
  printf("CP: %d, %d, %d\n", cp.x, cp.y, cp.color);
  move((Point *)&cp, -4, 7); // Note the cast
  setColor(&cp, 190);
  printf("CP: %d, %d, %d\n", cp.x, cp.y, cp.color);
  
  return 0;
}
