/*
quick sort implemented in c++
runtime: O(n) if numbers are uniformly disributed
written by: dannyallover
date: 08/05/2018
*/
#include<iostream>
#include<vector>

using namespace std;

void bucketSort(int arr[], int range, int size) {
  int buckets[range + 1];

  memset(buckets, 0, sizeof(buckets));

  for(int i = 0; i < size; i++) {
    buckets[arr[i]]++;
  }

  int k = 0;
  for(int i = 0; i < size && k < range + 1; k++) {
    cout << k << endl;
    cout << buckets[k] << endl;
    while(buckets[k] > 0) {
      arr[i] = k;
      buckets[k]--;
      i++;
    }
  }
}

int main(void) {
  cout << "Enter the number of elements in your list: ";
  int size;
  cin >> size;

  cout << "Enter the range of the elements in your list: ";
  int range;
  cin >> range;

  int arr[size];
  cout << "Enter the numbers in your list now: " << endl;
  for(int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  cout << "Your list before: ";
  for(int i = 0; i < size - 1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[size - 1] << endl;

  bucketSort(arr, range, size);

  cout << "Your list after: ";
  for(int i = 0; i < size - 1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[size - 1] << endl;
}
