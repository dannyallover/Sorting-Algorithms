/*
insertion sort implemented in c++
runtime: O(n^2)
written by: dannyallover
date: 08/05/2018
*/
#include<iostream>
#include<vector>

using namespace std;

void insertionSort(int arr[], int size) {
  for(int i = 1; i < size; i++) {
    int temp = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > temp) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
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

  insertionSort(arr, size);

  cout << "Your list after: ";
  for(int i = 0; i < size - 1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[size - 1] << endl;
}
