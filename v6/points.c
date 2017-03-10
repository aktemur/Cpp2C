#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct PointVTable;

typedef struct Point {
  struct PointVTable *vtable;
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

void Point_bar(Point *self, int k) {
  self->x = self->x / k;
  self->y = self->y / k;
}

int Point_hey(Point *self) {
  return 42;
}

typedef struct PointVTable {
  void (*print)(Point *self);
  void (*bar)(Point *self, int k);  
  int (*hey)(Point *self);  
} PointVTable;

PointVTable pointVTable; // a single vtable for the Point class

void Point_init(Point *self, int x, int y) {
  self->vtable = &pointVTable;
  self->x = x;
  self->y = y;
}

void initPointClass() {
  pointVTable.print = &Point_print;
  pointVTable.bar = &Point_bar;
  pointVTable.hey = &Point_hey;
}

////////////////////////////////////////////

struct ColorPointVTable;

typedef struct ColorPoint {
  struct ColorPointVTable *vtable;
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

void ColorPoint_bar(ColorPoint *self, int k) {
  Point_bar((Point *)self, k); // super function call
  self->color = self->color / k;
}

int ColorPoint_foo(ColorPoint *self) {
  return self->x + self->y + self->color;
}

typedef struct ColorPointVTable {
  // Virtual methods of the parent first
  void (*print)(ColorPoint *self);
  void (*bar)(ColorPoint *self, int k);  
  int (*hey)(Point *self);
  // Extra virtual methods
  int (*foo)(ColorPoint *self);
} ColorPointVTable;

ColorPointVTable colorPointVTable; // a single vtable for the ColorPoint class

void ColorPoint_init(ColorPoint *self, int x,
                     int y, int color) {
  Point_init((Point *)self, x, y); // Casting works like magic
  self->color = color;
  self->vtable = &colorPointVTable;
}

void initColorPointClass() {
  colorPointVTable.print = &ColorPoint_print;
  colorPointVTable.bar = &ColorPoint_bar;
  colorPointVTable.hey = &Point_hey; // inheriting from the parent
  colorPointVTable.foo = &ColorPoint_foo;
}

int main() {
  // Initialize vtables. A one-time task at the beginning.
  initPointClass();
  initColorPointClass();
  
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

  p->vtable->print(p); // dynamic dispatch
  Point_move(p, 5, 4); // static dispatch
  p->vtable->print(p);         // dynamic dispatch
  p->vtable->bar(p, 2);
  p->vtable->print(p);
  
  return 0;
}
