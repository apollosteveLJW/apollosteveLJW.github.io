#include <iostream>
#include <string>

template <typename T>
class NamedObject {
public:
  NamedObject(std::string& name, const T& value):nameValue(name),objectValue(value){}

private:
  std::string& nameValue;
  const T objectValue;
};
int main() {
std::string newObject("first");
std::string oldObject("second");

NamedObject<int> p(newObject, 2);
NamedObject<int> s(oldObject, 36);
p = s;

return 0;
}
