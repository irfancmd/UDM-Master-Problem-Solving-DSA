#include<iostream>
#include<string>
#include<unordered_map>
#include "../utils.hpp"

using namespace std;

string largestUniqueSubstring(string str) {
  int currentWindowLength = 0;
  int maxWindowLength = 0;
  int startIndex = -1;

  int i = 0;
  int j = 0;

  unordered_map<char, int> m;

  while(j < str.length()) {
    char ch = str[j];

    if(m.count(ch) && m[ch] >= i) {
      // The character is already in the current window
      i = m[ch] + 1;
      
      currentWindowLength = j - i;
    }

    m[ch] = j;
    currentWindowLength++;
    j++;

    if(currentWindowLength > maxWindowLength) {
      maxWindowLength = currentWindowLength;
      startIndex = i;
    }
  }

  return str.substr(startIndex, maxWindowLength);
}

int main() {
  string str = "abcabed";

  cout << largestUniqueSubstring(str) << endl; 

  return 0;
}
