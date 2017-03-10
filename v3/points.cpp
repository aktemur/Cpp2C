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
};

int main() {
  Point p(0, 0);
  printf("P: %d, %d\n", p.x, p.y);
  p.move(5, 4);
  printf("P: %d, %d\n", p.x, p.y);


  ColorPoint cp(6, 9, 255);
  printf("CP: %d, %d, %d\n", cp.x, cp.y, cp.color);
  cp.move(-4, 7);
  cp.setColor(190);
  printf("CP: %d, %d, %d\n", cp.x, cp.y, cp.color);

  return 0;
}
  
