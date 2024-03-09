#include<iostream>

using namespace std;

/*
  Clearing bit means flipping a bit to '0'.
*/

void clearBitAtPosition(int &n, int i) {
  int mask = ~(1 << i);

  n = n & mask;
}

int main() {
  int n = 5; // 00000101

  clearBitAtPosition(n, 0);

  cout << n << endl;

  return 0;
}
