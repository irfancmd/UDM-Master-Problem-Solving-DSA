#include<iostream>

using namespace std;

int getBitAtPosition(int n, int i) {
  int mask = (1 << i);

  return (n & mask) > 0 ? 1 : 0;
}

int main() {
  int n = 5; // 00000101

  cout << getBitAtPosition(n, 2) << endl;

  return 0;
}
