#include<iostream>
#include<cstring>

#include "../utils.hpp"

using namespace std;

/*
  Link:
*/

void string20(char* str){
  /* Strategy: One approach could be to keep iterting the string from left to right. Whenever we face a space,
     we could shift all the elements by 2 place and put %20 in the place of the space. We would have to do it
     for each and every spaces encountered. This would not be efficient, sa it would have O(n^2) time complexity.
     An efficient approach would be to count the total number of slots that need to be shifted. For instance,
     if we have 5 spaces, we have to shift 5 * 2 = 10 characters. Then, we would go to the (n-1) + 10 th index. We
     then will keep iterating the string from right to left and populate the new location with string characters.
     Whenever we face space, we will put %20 there and keep iterating towards left. Thus we will be able to solve this
     problem in linear O(n) time complexity.
 */ 

  // Count the number of spaces
  int spaceCount = 0;

  for(int i {0}; str[i] != '\0'; i++) {
    if(str[i] == ' ') {
      spaceCount++;
    }
  }

  int newStringIndex = strlen(str) + (2 * spaceCount);

  // Terminate the expanded string with null character
  str[newStringIndex] = '\0';

  // Caution: Compiler will recommend to put size_t here isntead of int but DON'T DO THAT.
  // Since size_t is unsigned, it will cause this progarm to malfunction and even get
  // stuck in an infinite loop.
  for(int i {strlen(str) - 1}; i >= 0; i--) {
    if(str[i] == ' ') {
      str[newStringIndex - 1] = '0';
      str[newStringIndex - 2] = '2';
      str[newStringIndex - 3] = '%';
      newStringIndex = newStringIndex - 3;
    } else {
      str[newStringIndex - 1] = str[i];
      newStringIndex--;
    }
  }
}

int main()
{
  char input[10000]; 
  cin.getline(input, 10000);

  string20(input);

  cout << input << endl;

  return 0;
}

