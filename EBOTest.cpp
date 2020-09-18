#include <iostream>

class Empty {
};

class Test: public Empty {
private:
  int x;
};

int main() {
  std::cout << "class empty size is " <<sizeof(Empty) << std::endl;
  std::cout << "class Test size is " << sizeof(Test) << " compare with int(" << sizeof(int) << ")" << std::endl;
  return 0;
}
