#include<iostream>
#include<vector>

#include "../utils.hpp"

using namespace std;

/*
  Link: https://leetcode.com/problems/trapping-rain-water/
*/

int trappedRain(vector<int> arr){
  int n = arr.size();

  /* Strategy: The formula to find the amount of trapped rain water on top of
     a specific block is
     Min(height_of_largest_block_on_left, height_of_largest_block_on_right) - height_of_current_block.
     By using this formula, we can solve this problem. Now, instead of lopping over and over again for
     caltulating this, which would cause O(n^2) compexity, we can create two arrays which will hold the
     heights of the largest wall on each wall's left and right side respectively.
  */

  // Need at least 3 slots to trap water
  if(n <= 2) return 0;

  vector<int> left(n, 0), right(n, 0);

  left[0] = arr[0];
  right[n - 1] = arr[n - 1];

  for(int i {1}; i < n; i++) {
    left[i] = max(left[i - 1], arr[i]);
    right[n - i - 1] = max(right[n - i], arr[n - i - 1]);
  }

  int trappedRainAmount = 0;

  for(int i {0}; i < n; i++) {
    trappedRainAmount += min(left[i], right[i]) - arr[i];
  }

  return trappedRainAmount;
}

int main()
{
  // We can initialize a vector direcly in the parameter list using list
  // initialiation syntax. Note that we don't have to write "vector<int>" in
  // the parameter list.
  cout << trappedRain({ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }) << endl;

  return 0;
}
