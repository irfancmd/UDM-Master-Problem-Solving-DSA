#include<iostream>

using namespace std;

int main() {
  int a = 4; // 00000100;
  int b = 7; // 00000111;

  int bitwiseAnd = a & b; // 00000100
  cout << bitwiseAnd << endl;

  int bitwiseOr = a | b; // 00000111
  cout << bitwiseOr << endl;

  int bitwiseNot = ~a; // 11111011
  cout << bitwiseNot << endl;

  int bitwiseXor = a ^ b; // 00000011
  cout << bitwiseXor << endl;

  int leftShift = a << 2; // 00010000
  cout << leftShift << endl;

  int rightShift = a >> 2; // 000000001
  cout << rightShift << endl;

  return 0;
}
