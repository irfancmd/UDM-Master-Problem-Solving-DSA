#include<iostream>
#include<vector>
#include<unordered_set>

#include "../utils.hpp"

using namespace std;

/*
  Link: https://leetcode.com/problems/longest-consecutive-sequence/
*/

int longestBand(vector<int> arr){
  int longestBandLength = 0;

  int n = arr.size();

  // Strategy: We could start by sorting the array, which would take
  // nLog(n) time. But, we could do better by using an unordered set. Since, sets
  // allow us to look-up elements at O(1) complexity, we can solve this problem
  // close to O(n) time.
  unordered_set<int> set;

  for(auto e : arr) {
    set.insert(e);
  }

  for(auto e : set) {
    int parent {e - 1};

    if(set.find(parent) == set.end()) {
      // Since no parent could be found, this element itself can be the start of a band.
      // So, find next elements of the band.
      int bandLength = 1;
      int next {e + 1};

      while(set.find(next) != set.end()) {
        bandLength++;
        next++;
      }

      longestBandLength = max(longestBandLength, bandLength);
    }
  }

  return longestBandLength;
}

int main()
{
  // We can initialize a vector direcly in the parameter list using list
  // initialiation syntax. Note that we don't have to write "vector<int>" in
  // the parameter list.
  cout << longestBand({ 1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6 }) << endl;

  return 0;
}
