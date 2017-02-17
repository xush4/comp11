#include <iostream>
using namespace std;
int main() {
  int y = 3, x = 3;
  switch (x + 3)
  {
    case 6: 
    y = 1;
    default: 
    y += 1;
}
  cout<< y;
  return 0;
}
