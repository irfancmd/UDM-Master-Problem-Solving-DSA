#include<iostream>
#include<algorithm>

#include "../utils.hpp"

/*
  Link: https://leetcode.com/problems/subsets/
*/

void subSequence(string s, string output, vector<string> &v) {
    // Base case
    if(s.size() == 0) {
        v.push_back(output);
        return;
    }

    // Recursion
    char ch = s[0];
    string reducedInput = s.substr(1);

    // Includes the current letter
    subSequence(reducedInput, output + ch, v);

    // Excludes the current letter
    subSequence(reducedInput, output, v);
}

bool compareStrings(string s1, string s2) {
    if(s1.length() == s2.length()) {
        return s1 < s2;
    }

    return s1.length() < s2.length();
}

int main() {
    string s;
    cin >> s;

    vector<string> v;

    string result = "";

    subSequence(s, result, v);

    sort(v.begin(), v.end(), compareStrings);

    for(auto s : v){
        cout << s << ",";
    }
    cout << endl;

    return 0;
}
