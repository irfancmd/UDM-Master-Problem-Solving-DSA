#include<iostream>
#include<vector>
#include<algorithm>

#include "../utils.hpp"

using namespace std;

/*
  Given an integer S, find all triplets of integers
  that sum to S. The triplets should be printed in ascending
  order and the numbers within the triplets should also be
  in ascending order.

  Link: https://leetcode.com/problems/3sum/
*/

vector<vector<int>> tripletsOfSum(vector<int> arr, int s){
  vector<vector<int>> result;

  sort(arr.begin(), arr.end());

  int n = arr.size();

  // We will fix one element, and then solve the pair sum problem
  for(int i {0}; i <= n - 3; i++) {
    // Instead of using set, we'll use the two pointer approach
    // for solving the pair sum problem since we've sorted the array.
    // By not using the set based approach, we're saving memory (space complexity).
    int j {i + 1};
    int k {n - 1};

    while(j < k) {
      int currentSum {arr[i]};
      currentSum += arr[j];
      currentSum += arr[k];

      if(currentSum == s) {
        result.push_back({ arr[i], arr[j], arr[k] });
        j++;
        k--;
      } else if (currentSum > s) {
        // currentSum is larger
        k--;
      } else {
        // currentSum is smaller
        j++;
      }
    }
  }

  return result;
}

int main()
{
  // We can initialize a vector direcly in the parameter list using list
  // initialiation syntax. Note that we don't have to write "vector<int>" in
  // the parameter list.
  vector<vector<int>> triplets =  tripletsOfSum({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 15 }, 18);

  for(int i {1}; i <= triplets.size(); i++) {
    // C++ automatically resolves the type here, So, no need to explicitly mention
    // the template/generic type.
    printVector("Triplet " + to_string(i), triplets[i - 1]);
  }

  return 0;
}
