#pragma once

#include<iostream>
#include<vector>

using namespace std;

template <typename T>
void printVector(const string &message, const vector<T> &vec) {
  cout << message << ": ";
  for(auto e : vec) {
    cout << e << " ";
  }
  cout << endl;
}
