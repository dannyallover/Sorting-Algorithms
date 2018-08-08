/*
quick sort implemented in c++
runtime: (O(n^2)), typically acts as O(nlog(n))
written by: dannyallover
date: 08/05/2018
*/
#include<iostream>
#include<vector>

using namespace std;

int partition(int arr[], int low, int high) {
  int i = low - 1;
  for(int j = low; j <= high - 1; j++) {
    if(arr[j] <= arr[high]) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[high]);
  return i + 1;
}

void quickSort(int arr[], int low, int high) {
  if(low < high) {
    int part = partition(arr, low, high);

    quickSort(arr, low, part - 1);
    quickSort(arr, part + 1, high);
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

  quickSort(arr, 0, size - 1);

  cout << "Your list after: ";
  for(int i = 0; i < size - 1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[size - 1] << endl;
}
