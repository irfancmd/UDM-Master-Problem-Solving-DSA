#include<iostream>

using namespace std;

/*
  Setting bit means flipping a bit to '1'.
*/

void setBitAtPosition(int &n, int i) {
  int mask = (1 << i);

  n = n | mask;
}

int main() {
  int n = 5; // 00000101

  setBitAtPosition(n, 1);

  cout << n << endl;

  return 0;
}
