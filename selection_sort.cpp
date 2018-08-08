/*
selection sort in c++
runtime: (O(n^2))
written by: dannyallover
date: 08/07/2018
*/
#include<iostream>
#include<vector>

using namespace std;

void selectionSort(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    int minPos = i;
    for(int j = i + 1; j < size; j++) {
      if(arr[j] < arr[minPos])
        minPos = j;
    }
    swap(arr[i], arr[minPos]);
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

  selectionSort(arr, size);

  cout << "Your list after: ";
  for(int i = 0; i < size - 1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[size - 1] << endl;
}
