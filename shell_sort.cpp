/*
shell sort implemented in c++
runtime: O(n^2)
written by: dannyallover
date: 08/07/2018
*/
#include<iostream>
#include<vector>

using namespace std;

void shellSort(int arr[], int size) {
  for(int gap = size/2; gap > 0; gap = gap /= 2) {
    for(int i = gap; i < size; i++) {
      for(int j = i; j >= gap && arr[j] < arr[j-1]; j -= gap) {
        swap(arr[j], arr[j-1]);
      }
    }
  }
}

int main(void) {
  cout << "Enter the number of elements in your list: ";
  int size;
  cin >> size;

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

  shellSort(arr, size);

  cout << "Your list after: ";
  for(int i = 0; i < size - 1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[size - 1] << endl;
}
