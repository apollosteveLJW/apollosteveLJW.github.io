#ifndef RAS_RECTANGLE_H_
#define ARS_RECTANGLE_H_

#include <iostream>
#include <vector>

namespace RSA {

struct point {
  double x;
  double y;
};

class Rectangle {
public:
  Rectangle(const point& ul, const point& ur, const point& ll, const point& lr):upper_left(ul), upper_right(ur), lower_left(ll), lower_right(lr){}
  bool isSame(const Rectangle& rec);
  bool intersection(const Rectangle& rec);
  double area(const Rectangle& rec);
  int backgroundMesh();
private:
  point upper_left;
  point upper_right;
  point lower_left;
  point lower_right;
};

}
#endif //RSA_RECTANGLE_H
