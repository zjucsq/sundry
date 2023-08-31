#include <iostream>
using namespace std;

int add(int a, int b) 
{
  cout << __func__ << endl;
  return a + b;
}

int main() 
{
  cout << __func__ << endl;
  add(0, 0);
}