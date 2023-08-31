#include <iostream>
using namespace std;

template <int n>
struct sum {
  constexpr static int value = n + sum<n - 1>::value;
};

template <>
struct sum<1> {
  constexpr static int value = 1;
};

int main() { cout << sum<900>::value << endl; }