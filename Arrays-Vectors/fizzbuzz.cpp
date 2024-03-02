#include<iostream>
#include<vector>
#include <string>

#include "../utils.hpp"

using namespace std;

vector<string> fizzbuzz(int n){
  vector<string> result;

  for(int i {1}; i <= n; i++) {
    if(i % 3 == 0 && i % 5 == 0) {
      result.push_back("FizzBuzz");
    } else if (i % 3 == 0) {
      result.push_back("Fizz");
    } else if (i % 5 == 0) {
      result.push_back("Buzz");
    } else {
      result.push_back(to_string(i));
    }
  }

  return result;
}

int main()
{
  // C++ automatically resolves the type here, So, no need to explicitly mention
  // the template/generic type.
  printVector("Result", fizzbuzz(15));

  return 0;
}
