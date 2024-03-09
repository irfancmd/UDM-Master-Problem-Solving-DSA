#include<iostream>

using namespace std;

void clearBitAtPosition(int &n, int i) {
  int mask = ~(1 << i);

  n = n & mask;
}

void updateBit(int &n, int i, int newBit) {
  clearBitAtPosition(n, i);

  int mask = (newBit << i);

  n = n | mask;
}

int main() {
  int n = 5; // 00000101

  updateBit(n, 1, 1);

  cout << n << endl;

  return 0;
}
