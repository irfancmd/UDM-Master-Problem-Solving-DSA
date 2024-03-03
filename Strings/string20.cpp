#include<iostream>
#include<string>

#include "../utils.hpp"

using namespace std;

/*
  Link:
*/

string string20(string input){
  int n = input.length();

  string result;

  /* Strategy: One approach could be to keep iterting the string from left to right. Whenever we face a space,
     we could shift all the elements by 2 place and put %20 in the place of the space. We would have to do it
     for each and every spaces encountered. This would not be efficient, sa it would have O(n^2) time complexity.
     An efficient approach would be to count the total number of characters that need to be shifted. For instance,
     if we have 5 spaces, we have to shift 5 * 2 = 10 characters. Then, we would go to the (n-1) + 10 th index. We
     then will keep iterating the string from right to left and populate the new location with string characters.
     Whenever we face space, we will put %20 there and keep iterating towards left. Thus we will be able to solve this
     problem in linear O(n) time complexity.
 */ 

  return result;
}

int main()
{
  cout << string20("Hello to the inhabitants of planet Earth.") << endl;

  return 0;
}

