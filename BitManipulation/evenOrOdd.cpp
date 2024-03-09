#include<iostream>

using namespace std;

int main() {
  int number;
  cin >> number;

  if((number & 1) == 1) {
    cout << "Odd" << endl;
  } else {

    cout << "Even" << endl;
  }

  return 0;
}
