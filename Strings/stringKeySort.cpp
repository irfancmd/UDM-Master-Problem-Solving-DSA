#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

#include "../utils.hpp"

/*
  Link: https://leetcode.com/problems/largest-number/
*/

string extractStringAtKey(string str, int key) {
    char *s = strtok((char *)str.c_str(), " ");

    while(key > 1) {
        s = strtok(NULL, " ");
        key--;
    }

    return (string)s;
}

int convertToInt(string s) {
  int answer = 0;
  int position = 1;

  for(int i = s.length() - 1; i >= 0; i--) {
    answer += ((s[i] - '0') * position);
    position *= 10;
  }

  return answer;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
    string key1, key2;

    key1 = s1.second;
    key2 = s2.second;

    // We could use "atoi" function here, but using a custom function here
    // just to show the full process.
    return convertToInt(key1.c_str()) < convertToInt(key2.c_str());
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2) {
    string key1, key2;

    key1 = s1.second;
    key2 = s2.second;

    return key1.c_str() < key2.c_str();
}

int main() {
    int n;
    cin >> n;
    cin.get(); // Consume the \n after that int.

    vector<string> v;

    string tempInput;
    for(int i {0}; i < n; i++) {
        // Using getline instead of cin because we need to read the strings with
        // whitespaces. As we know, cin doesn't take whitespaces but getline does.
        getline(cin, tempInput);
        v.push_back(tempInput);
    }

    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;

    // Extract key information and store them
    vector<pair<string, string>> keyPairVector;

    for(int i = 0; i < n; i++) {
        keyPairVector.push_back({ v[i], extractStringAtKey(v[i], key) });
    }

    // Sorting
    if(ordering == "numeric") {
        sort(keyPairVector.begin(), keyPairVector.end(), numericCompare);
    } else {
        sort(keyPairVector.begin(), keyPairVector.end(), lexicoCompare);
    }

    // Reversal
    if(reversal == "true") {
        reverse(keyPairVector.begin(), keyPairVector.end());
    }

    // Output
    for(int i {0}; i < n; i++) {
        cout << keyPairVector[i].first << endl;
    }

    return 0;
}
