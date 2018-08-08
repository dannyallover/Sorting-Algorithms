/*
bubble sort implemented in c++
runtime:
written by: dannyallover
date: 08/05/2018
*/
#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 1; j < size; j++) {
      if(arr[j-1] > arr[j]) {
        swap(arr[j-1], arr[j]);
        j++;
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

  bubbleSort(arr, size);

  cout << "Your list after: ";
  for(int i = 0; i < size - 1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[size - 1] << endl;
}
