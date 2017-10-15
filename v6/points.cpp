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

  virtual void bar(int k) {
    x = x/k;
    y = y/k;
  }

  virtual int hey() {
    return 42;
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

  virtual void bar(int k) {
    Point::bar(k); // super function call
    color = color/k;
  }

  // An extra method that does not exist in the parent
  virtual int foo() {
    return x + y + color;
  }

  // Virtual method "hey" is not overridden.
};

int main() {
  srand(time(NULL));
  int r = rand();

  Point p(0, 0);
  ColorPoint cp(6, 9, 255);
  Point *pp;

  if (r % 2 == 0) {
    pp = &p;
  } else {
    pp = &cp;
  }
  pp->print();
  pp->move(5, 4);
  pp->print();
  pp->bar(2);
  pp->print();
  
  return 0;
}
  
