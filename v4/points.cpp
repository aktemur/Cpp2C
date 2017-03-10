#include <stdio.h>

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

  void print() {
    printf("CP: %d, %d, %d\n", x, y, color);
  }
};

int main() {
  Point p(0, 0);
  p.print();
  p.move(5, 4);
  p.print();

  ColorPoint cp(6, 9, 255);
  cp.print();
  cp.move(-4, 7);
  cp.setColor(190);
  cp.print();

  return 0;
}
  
