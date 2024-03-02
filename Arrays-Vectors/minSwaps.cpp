#include<iostream>
#include<vector>
#include<algorithm>

#include "../utils.hpp"

using namespace std;

/*
  Link: https://practice.geeksforgeeks.org/problems/minimum-swaps/1
*/

int countMinSwaps(vector<int> arr){

  int n = arr.size();

  /* Strategy: First, we'll sort the array to get the correct position of all
     elements. Then, we'll compare the original and sorted arrays to find "cycles" in
     of indices. The number of swaps required to correct the positions of elements
     within that circle is number_of_elements_in_cycle - 1. Thus, by finding all disjoint
     cycles and adding up the number of swaps for all of them, we can get the total number
     of swaps required to sort the original array.
  */
  int minSwapCount = 0;

  // We're using an array of pairs instead of dictionary/map because sorting an
  // array of paris is quite easy, as C++ sorts array of pairs by using the first
  // elements by default, which works for us in this usecase. Thus, we don't need to write
  // a custom comparator function.
  pair<int, int> indices[n];

  for(int i {0}; i < n; i++) {
    indices[i].first = arr[i];
    indices[i].second = i;
  }

  sort(indices, indices + n);

  // We'll take an array to mark visited nodes of a cycle
  vector<bool> visited(n, false);

  for(int i {0}; i < n; i++) {
    int oldPosition = indices[i].second;

    if(visited[i] == true || oldPosition == i) {
      // Do nothing if the node is already visited, or the element is already in
      // the correct position.
      continue;
    }

    int node = i;
    int cycleElementCount = 0;

    while(!visited[node]) {
      visited[node] = true;

      cycleElementCount++;

      int nextNode = indices[node].second;
      node = nextNode;
    }

    minSwapCount += (cycleElementCount - 1);
  }

  return minSwapCount;
}

int main()
{
  // We can initialize a vector direcly in the parameter list using list
  // initialiation syntax. Note that we don't have to write "vector<int>" in
  // the parameter list.
  cout << countMinSwaps({ 5, 4, 3, 2, 1 }) << endl;

  return 0;
}
