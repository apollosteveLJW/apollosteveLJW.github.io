#include <iostream>
#include <vector>

using namespace std;
class Person {
public:
  int age_;
  Person(int age):age_(age) {
    std::cout << "Consturct a person" << std::endl;
  }
  Person(const Person& person):age_(person.age_) {
    std::cout << "copy constuct" << std::endl;
  }
  Person(const Person&& person):age_(person.age_) {
    std::cout << "move construct" << std::endl;
  }
};



int main() {
    vector<Person> person;
    auto p = Person(1); // >: Construct a person.1
//#ifdef TEST_EMPLACE_BACK
    // std::cout << "emplace_back" << std::endl;
    // person.emplace_back(move(p)); // >: Move-Construct1
    // std::cout << "left value" << std::endl;
    // person.emplace_back(p);
    // std::cout << "temp" << std::endl;
    // person.emplace_back(2);
    // std::cout << "person size " << person.size() << std::endl;
   
    /**
     * >: Construct a person.2  // 构建一个新的元素
     * >: Move-Construct1       // 拷贝之前的元素过来，这个时候用的是 Person(const Person &&p)
     */
//#endif
//#ifdef TEST_PUSH_BACK
    std::cout << "push back:" << std::endl;
    person.push_back(move(p));
    std::cout << "left value" << std::endl;
    person.push_back(p);
    std::cout << "temp" << std::endl;
    person.push_back(2);
    std::cout << "person size " << person.size() << std::endl;
    /**
     * >: Copy-Construct1 因为容器扩容，需要把前面的元素重新添加进来，因此需要拷贝
     */
//#endif
}
