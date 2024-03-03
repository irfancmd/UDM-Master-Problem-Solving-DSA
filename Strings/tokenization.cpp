#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cstring> // For strtok

#include "../utils.hpp"

int main() {
    string s1 = "This is a string";

    // Tokenization using stringstream
    stringstream ss(s1); 

    string token;

    vector<string> s1Tokens;

    while(getline(ss, token, ' ')) {
        s1Tokens.push_back(token);
    }

    cout << "s1 Tokens..." << endl;
    for(auto token: s1Tokens) {
        cout << token << endl;;
    }

    cout << endl;

    // Tokenization using strtok function. This function internally maintains the last state of the function call using
    // static variables. Note that strtok is a legacy c function and works with C strings in form form of char array. It
    // will NOT WORK FOR char* as they are immutable. strtok requires the input string to be variable, not constant.

    char s2[100] = "This is another string";

    char* s2Token = strtok(s2, " "); 

    cout << "s2 Tokens..." << endl;
    while(s2Token != NULL) {
        cout << s2Token << endl;

        // Pass null to get next tokens
        s2Token = strtok(NULL, " ");
    }

    cout << endl;

    return 0;
}