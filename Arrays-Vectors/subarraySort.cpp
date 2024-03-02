#include<iostream>
#include<vector>
#include<limits.h>

#include "../utils.hpp"

using namespace std;

/*
  Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/

bool outOfOrder(const vector<int> &arr, const int i);

pair<int, int> subarraySort(vector<int> arr){
  int n = arr.size();

  /* Stragegy: We could solve this problem by sorting the array and comparing
     the differences between the original and the sorted array, which would result
     in O(nLog(n)) time complexity. However, we can do better by indentifying the
     smallerst and largest elemnets that are out of order within the array and then
     finding out the indices where they were supposed to be. This can be done in
     roughly linear O(n) time complexity.
  */
  int smallest = INT_MAX;
  int largest = INT_MIN;

  for(int i {0}; i < n; i++) {
    int current = arr[i];

    if(outOfOrder(arr, i)) {
      smallest = min(smallest, current);
      largest = max(largest, current);
    }
  }

  // Now, find the correct positions of smallest and largest
  if(smallest == INT_MAX) {
    // The array is already sorted
    return { -1, -1 };
  }

  int left = 0;
  while(smallest >= arr[left]) {
    left++;
  }

  int right = n - 1;
  while(largest <= arr[right]) {
    right--;
  }

  return { left, right};
}

bool outOfOrder(const vector<int> &arr, const int i) {
  int current = arr[i];

  if(i == 0) return current > arr[1];

  if(i == arr.size() - 1) return current < arr[i - 1];

  return current > arr[i + 1] || current < arr[i - 1];
}

int main()
{
  // We can initialize a vector direcly in the parameter list using list
  // initialiation syntax. Note that we don't have to write "vector<int>" in
  // the parameter list.
  pair<int, int> indices = subarraySort({ 1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11 });

  cout << indices.first << " and " << indices.second << endl;

  return 0;
}
