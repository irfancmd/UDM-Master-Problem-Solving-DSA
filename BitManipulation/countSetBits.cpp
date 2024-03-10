#include<iostream>

using namespace std;

// Will have time complexity of O(log(n))
int countSetBits(int n) {
  int count = 0;

  while(n > 0) {
    int lastBit = (n & 1);

    count += lastBit;

    n = n >> 1;
  }

  return count;
}

// Faster method. Time Complexity O(number of set bits)
int countSetBitsFast(int n) {
  int count = 0;

  while (n > 0) {
    n = n & (n - 1);
    count++;
  }

  return count;
}

int main() {
  int n = 32;

  cout << countSetBits(n) << endl;
  cout << countSetBitsFast(n) << endl;

  return 0;
}
