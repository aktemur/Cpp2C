#include <stdio.h>

class Point {
public:
  int x;
  int y;

  void move(int dx, int dy) {
    x += dx;
    y += dy;
  }
};

int main() {
  Point p1;
  Point p2;
  
  p1.x = 0;
  p1.y = 0;
  p2.x = 3;
  p2.y = 8;
  printf("P1: %d, %d\n", p1.x, p1.y);
  printf("P2: %d, %d\n", p2.x, p2.y);
  
  p1.move(5, 4);
  p2.move(-4, 9);
  printf("P1: %d, %d\n", p1.x, p1.y);
  printf("P2: %d, %d\n", p2.x, p2.y);

  return 0;
}
  
