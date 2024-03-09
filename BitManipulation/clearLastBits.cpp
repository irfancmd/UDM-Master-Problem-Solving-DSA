#include<iostream>

using namespace std;


void clearLastBits(int &n, int i) {
  int mask = (-1 << i); // We could write ~0 instead of -1.

  n = n & mask;
}

int main() {
  int n = 5; // 00000101

  clearLastBits(n, 2);

  cout << n << endl;

  return 0;
}
