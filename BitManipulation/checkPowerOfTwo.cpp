#include<iostream>

using namespace std;

/*
  Lets's take a power of two, for isntance, 16.
  16 -> 00010000
  Now,
  16 - 1 = 15 -> 00001111

  Note what happens if we take "and" o 16 and 15
    00010000
  & 00001111
    --------
    00000000

  So, the & of 16 and (16 - 1) is 0. This property is only true
  for the numbers that are powers of 2. So, this proves that 16
  is a power of 2.
*/

bool isPowerOftwo(int n) {
  int result = n & (n - 1);

  return result == 0;
}

int main() {
  int n = 32;

  bool powerOfTwo = isPowerOftwo(n);

  if (powerOfTwo) {
    cout << n << " is a power of two." << endl;
  } else {
    cout << n << " is not a power of two." << endl;
  }

  return 0;
}
