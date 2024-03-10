#include<iostream>
#include "../utils.hpp"

using namespace std;

void housing(int *arr, int n, int k) {
  int i = 0, j = 0;
  int currentSum = 0;

  while(j < n) {
    // Expand to right
    currentSum += arr[j];
    j++;

    // Remove elemets from left if necessary
    while(currentSum > k && i < j) {
      currentSum -= arr[i];
      i++;
    }

    if(currentSum == k) {
      cout << i << " - " << (j - 1) << endl;
    }
  }
}

int main() {
  int plots[] = { 1, 3, 2, 1, 4, 1, 3, 2, 1, 1 };
  int n = sizeof(plots) / sizeof(int);
  int k = 8;

  housing(plots, n, k);

  return 0;
}
