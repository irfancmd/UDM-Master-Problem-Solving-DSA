#include<iostream>
#include<cstring> // For strlen

#include "../utils.hpp"

char* customStrTok(char* input, char delim) {
    static char* str {nullptr};

    if(input != nullptr) {
        str = input;
    }

    if(str == nullptr) {
        return nullptr;
    }

    char *token = new char[strlen(str) + 1]; // +1 for null character
    int i {0};

    for(; str[i] != '\0'; i++) {
        if(str[i] != delim) {
            token[i] = str[i];
        } else {
            token[i] = '\0';
            str = str + i + 1; // Move the pointer

            return token;
        }
    }

    token[i] = '\0';
    // Reset the input.
    str = nullptr;

    return token;
}

int main() {
    char input[100] {"Hello,world,Earth!"};

    char *token = customStrTok(input, ',');
    cout << token << endl;

    char *token2 = customStrTok(nullptr, ',');
    cout << token2 << endl;

    char *token3 = customStrTok(nullptr, ',');
    cout << token3 << endl;
}
