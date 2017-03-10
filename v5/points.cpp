#include <stdio.h>
#include <time.h>
#include <stdlib.h>

class Point {
public:
  int x;
  int y;

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
  
  void move(int dx, int dy) {
    x += dx;
    y += dy;
  }

  // Virtual function, woohoo!
  virtual void print() {
    printf("P: %d, %d\n", x, y);
  }
};

class ColorPoint: public Point {
public:
  int color;

  ColorPoint(int x, int y, int color): Point(x,y) {
    this->color = color;
  }

  void setColor(int c) {
    color = c;
  }

  virtual void print() {
    printf("CP: %d, %d, %d\n", x, y, color);
  }
};

int main() {
  srand(time(NULL));
  int r = rand();

  Point *p;

  if (r % 2 == 0) {
    p = new Point(0, 0);
  } else {
    p = new ColorPoint(6, 9, 255);
  }
  // It's not possible to know statically
  // which print function will be called here.
  p->print();    // dynamic dispatch
  p->move(5, 4); // static dispatch
  p->print();    // dynamic dispatch

  return 0;
}
  
