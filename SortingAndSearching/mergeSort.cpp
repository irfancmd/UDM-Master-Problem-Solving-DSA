#include<vector>
#include "../utils.hpp"

using namespace std;

void merge(vector<int> &array, int s, int e) {
  int i = s;
  int mid = (s + e) / 2;
  int j = mid + 1;

  vector<int> temp;

  while(i <= e && j <= e) {
    if(array[i] < array[j]) {
      temp.push_back(array[i]);
      i++;
    } else {
      temp.push_back(array[j]);
      j++;
    }
  }

  while(i <= mid) {
    temp.push_back(array[i++]);
  }

  while(j <= e) {
    temp.push_back(array[j++]);
  }

  int k = 0;
  for(int idx {s}; idx <= e; idx++) {
    array[idx] = temp[k++];
  }
}

void mergeSort(vector<int> &array, int s, int e) {
  if(s >= e) {
    return;
  }

  int mid = (s + e) / 2;

  mergeSort(array, s, mid);
  mergeSort(array, mid + 1, e);

  return merge(array, s, e);
}

int main() {
  vector<int> arr {10, 5, 2, 0, 7, 6, 4};

  int s = 0;
  int e = arr.size() - 1;

  mergeSort(arr, s, e);

  printVector("Sorted result", arr);

  return 0;
}
