#include "iter.hpp"



template<typename T>
void print(T const &x) {
  cout << x << endl;
  return;
}


template<typename T>
void square(T const &x) {
  cout << x*x << endl;
  return;
}

int main() {
  int tab[] = {0,1,2,3,4};
  iter( tab, 5, print<int> );
  iter(tab, 5, square<int>);
  return 0;
}
