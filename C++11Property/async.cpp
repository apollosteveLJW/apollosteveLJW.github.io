#include <iostream>
#include <string>
#include<future>
#include <type_traits>
#include <vector>
#include <mutex>
#include <algorithm>
#include <numeric>

std::mutex m;
class X {
public:
  void foo(int i, const std::string& str) {
    std::lock_guard<std::mutex> lk(m);
    std::cout << str << ' ' << i << '\n';
  }
  void bar(const std::string& str){
    std::lock_guard<std::mutex> lk(m);
    std::cout << str << '\n';
  }
  int operator()(int i){
    std::lock_guard<std::mutex> lk(m);
    std::cout << i << '\n';
	return i + 10;
  }
};

template<typename RandomIt>
int paraller_sum(RandomIt beg, RandomIt end){
  auto len = end -beg;
  if(len < 1000) {
    return std::accumulate(beg,end,0);
  }
  RandomIt mid = beg + len/2;
  auto handle = std::async(std::launch::async,paraller_sum<RandomIt>,mid, end);
  int sum = paraller_sum(beg,mid);
  return sum + handle.get();
}

int main(){
  std::vector<int> v(10000,1);
  std::cout << "the sum is " << paraller_sum(v.begin(), v.end()) << std::endl;
  X x;
  auto a1 = std::async(&X::foo, &x, 42, "hello");
  auto a2 = std::async(std::launch::deferred, &X::bar, x, "world!!");
  auto a3 = std::async(std::launch::async, X(), 43);
  a2.wait();
  std::cout << a3.get() << std::endl;
}

