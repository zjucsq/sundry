#include <bit>
#include <iostream>
using namespace std;

int main() {
  int i;
  cin >> i;
  auto f{bit_cast<float>(i)};
  cout << i << ' ' << f << endl;
}