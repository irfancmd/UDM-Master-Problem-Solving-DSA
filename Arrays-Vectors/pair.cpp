#include<iostream>
#include<vector>
#include<unordered_set>

#include "../utils.hpp"

using namespace std;

/*
  Given an integer S, find a pair of two elements of an integer
  array that sum to S.

  Link: https://leetcode.com/problems/two-sum/
*/

vector<int> pairOfSum(vector<int> arr, int s){
  vector<int> pair;

  unordered_set<int> set;

  for(int e : arr) {
    int numberRequired = s - e;

    if(set.find(numberRequired) != set.end()) {
      pair.push_back(e);
      pair.push_back(numberRequired);

      break;
    }

    set.insert(e);
  }

  return pair;
}

int main()
{
  // We can initialize a vector direcly in the parameter list using list
  // initialiation syntax. Note that we don't have to write "vector<int>" in
  // the parameter list.
  vector<int> pair =  pairOfSum({ 10, 5, 2, 3, -6, 9 }, 11);

  if(pair.size() < 2) {
    cout << "No such pair." << endl;
  } else {
    // C++ automatically resolves the type here, So, no need to explicitly mention
    // the template/generic type.
    printVector("Result", pair);
  }

  return 0;
}
