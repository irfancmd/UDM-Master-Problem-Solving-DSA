#include<iostream>
#include<vector>

#include "../utils.hpp"

using namespace std;

/*
  Link: https://leetcode.com/problems/longest-mountain-in-array/
*/

int longestMountainLength(vector<int> arr){
  int largestLength = 0;

  int n = arr.size();

  // Strategy: we will visit each peak, and then count their left length and right
  // length.
  // Since the very first and very last element cannot be peak, we will iterate from
  // 1 to n - 2. Also note that we're not updating i in loop declaration. We will do
  // it contitionally inside the loop.
  for(int i {1}; i <= n - 2;) {
    if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
      // arr[i] is a peak
      int length = 1;

      int j {i};

      // Count left slope '/'
      while(j >= 1 && arr[j] > arr[j - 1]) {
        length++;
        j--;
      }

      // Count right slope '\'
      // By using 'i' here isntead of a separate variable, we're automatically
      // reacing to the next peek as we go down the right slope. Thus, we are
      // skipping uncecessary iterations to go to the next peak.
      while(i <= n - 2 && arr[i] > arr[i + 1]) {
        length++;
        i++;
      }

      largestLength = max(largestLength, length);
    } else {
      // Not a peek. Keep moving right.
      i++;
    }
  }

  return largestLength;
}

int main()
{
  // We can initialize a vector direcly in the parameter list using list
  // initialiation syntax. Note that we don't have to write "vector<int>" in
  // the parameter list.
  cout << longestMountainLength({ 5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4 }) << endl;

  return 0;
}
