#include<iostream>
#include<string>

#include "../utils.hpp"

int main() {
  // string s1;
  // getline(cin, s1); // Read string until '\n'.
  // getline(cin, s1, '.'); // Read string until '.'

  string s2 = "Apple ball cat Apple";

  // Find occurrence
  // The find method returns size_t which is basically unsigned long. So, if
  // the substring isn't found, it returns a huge integer. However, if we store this
  // return value to int, which holds signed intergers, the return value will be rounded
  // to -1. Thus we will be able to tell if a substring exists or not.
  int index = s2.find("Apple"); // Will start searching from position 0

  if(index == -1) {
    cout << "Couldn't find substring" << endl;
  } else {
    cout << "First occurrence: " << index << endl;

    // Find second occurence
    int secondOccurenceIndex = s2.find("Apple", index + 1); // Will start searching from position index + 1

    if(secondOccurenceIndex != -1) {
      cout << "Second occurrence: " << secondOccurenceIndex << endl;
    }
  }

  return 0;
}
