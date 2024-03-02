#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printVector(const string &message, const vector<int> &vec);

int main()
{
  vector<int> arr {1, 2, 3, 4};

  // Size is the number of elements allocated in the vector
  cout << "Size: " << arr.size() << endl;

  // Capacity is the maximum number of elements the vector can hold
  cout << "Capacity: " << arr.capacity() << endl;

  // Now, let's add one more element
  arr.push_back(5);

  // We will see that the size becomes 5, but capacity doubles. That's how
  // vector scales up and down it's size.
  cout << "Size: " << arr.size() << endl;
  cout << "Capacity: " << arr.capacity() << endl;

  // The pop back method
  printVector("Before pop back", arr);

  arr.pop_back();

  printVector("After pop back", arr);

  // The insert method
  arr.insert(arr.begin() + 2, {100, 200});

  printVector("After insert", arr);

  // Standard library sort method [O(nlog(n))]
  sort(arr.begin(), arr.end());
  printVector("After sort", arr);

  // Vector Fill Constructor
  // We're initializing a vector of size 10 filled with 5.
  vector<int> arr2 (10, 5);

  printVector("Fill constructor example", arr2);

  return 0;
}

void printVector(const string &message, const vector<int> &vec) {
  cout << message << ": ";
  for(auto e : vec) {
    cout << e << " ";
  }
  cout << endl;
}
