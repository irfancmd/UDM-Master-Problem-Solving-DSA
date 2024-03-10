#include<iostream>

using namespace std;


/*
  This will have a time complexity of O(log(n)) because
  the binary representation of any number 'n' can have
  at most log(n) number of set bits.
*/
int fastExponentiation(int a, int n) {
  int answer = 1;

  while (n > 0) {
    int lastBit = (n & 1);

    if(lastBit) {
      // If last bit is set
      answer = answer * a;
    }

    a = a * a;
    n = n >> 1;
  }

  return answer;
}

int main() {
  int n = 5;

  cout << fastExponentiation(n, 3) << endl;

  return 0;
}
