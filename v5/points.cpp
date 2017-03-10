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

  void print() {
    printf("P.print: %d, %d\n", x, y);
  }
  
  // Virtual function, woohoo!
  virtual void vPrint() {
    printf("P.vPrint: %d, %d\n", x, y);
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

  void print() {
    printf("CP.print: %d, %d, %d\n", x, y, color);
  }

  virtual void vPrint() {
    printf("CP.vPrint: %d, %d, %d\n", x, y, color);
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
  p->print();     // static dispatch
  p->vPrint();    // dynamic dispatch
  p->move(5, 4);  // static dispatch
  p->print();     // static dispatch
  p->vPrint();    // dynamic dispatch

  return 0;
}
  
