#include <iostream>
#include <vector>
using namespace std;
class Point {
  public:
    int x;
    int y;
    Point(int, int);
};
int main(int argc, char *argv[]) {
  int x, y, n = 2, at;
  bool b1, b2;
  vector<Point> b(n), v(n);
  cin >> b.at(0).x >> b.at(0).y >> b.at(1).x >> b.at(1).y;
  cin >> v.at(0).x >> v.at(0).y >> v.at(1).x >> v.at(1).y;
  if (b1 || b2) {
    
  }
  return 0;
}
Point::Point(int x, int y) {
  this->x = x;
  this->y = y;
}

/*
x1 y1  x2  y2
1  1 - 6   6
3  3 - 8   8
#1 case: (x1 >= x3 && y1 >= y3) && (x1 <= x4 && y1 <= y4)

x1 y1  x2 y2
1  4 - 8  8
4  1 - 12 6

x1 y1  x2  y2
1  1 - 8   8
3  3 - 5   5

x1 y1  x2 y2
1  1 - 4  4
5  1 - 9  4
 */