#include<iostream>
#include<string>
#include<unordered_map>
#include "../utils.hpp"

using namespace std;

string smallestSubString(string s, string p) {
    // We're assuming that all characters of the input string 
    // are ascii characters. So, were waking 256 for array size. 

    // We're using arrays as frequency maps.l
    int FP[256] = {0};
    int FS[256] = {0};

    for(int i = 0; i < p.length(); i++) {
        FP[p[i]]++;
    }

    int matchCount = 0;
    int startIndex = 0;
    int minWindowSize = INT32_MAX;
    int minWindowStartIndex = -1;

    for(int i = 0; i < s.length(); i++) {
        char ch = s[i];

        FS[ch]++;

        if(FP[ch] != 0 && FS[ch] <= FP[ch]) {
            matchCount++;
        }

        // Remove unwanted characters
        if(matchCount == p.length()) {
            while(FP[s[startIndex]] == 0 || FS[s[startIndex]] > FP[s[startIndex]]) {
                FS[s[startIndex]]--;
                startIndex++;
            }

            int windowSize = i - startIndex + 1;

            if(windowSize < minWindowSize) {
                minWindowSize = windowSize;
                minWindowStartIndex = startIndex;
            }
        }
    }

    if(minWindowStartIndex == -1) {
        return "No window found";
    }

    return s.substr(minWindowStartIndex, minWindowSize);
}

int main() {
    string s = "hello";
    string p = "eo";

    cout << smallestSubString(s, p) << endl;

    return 0;
}