/*
merge sort implemented in c++
runtime: O(nlog(n))
note: merge sort is best for sorting linked lists
written by: dannyallover
date: 08/05/2018
*/
#include<iostream>
#include<vector>

using namespace std;

void merge(int arr[], int low, int high) {
  int temp[high - low + 1];
  int midLow = low + (high - low) / 2;
  int midHigh = midLow + 1;

  int i = low;
  int j = midHigh;
  int k = 0;
  while(i <= midLow && j <= high) {
    if(arr[i] <= arr[j]) {
      cout << arr[i] << endl;
      temp[k] = arr[i];
      i++;
      k++;
    }
    else if(arr[i] >= arr[j]) {
      cout << arr[j] << endl;
      temp[k] = arr[j];
      j++;
      k++;
    }
  }
  while(i <= midLow) {
    cout << arr[i] << endl;
    temp[k] = arr[i];
    i++;
    k++;
  }
  while(j <= high) {
    cout << arr[j] << endl;
    temp[k] = arr[j];
    j++;
    k++;
  }

  k = 0;
  for(int i = low; i < high + 1; i++) {
    arr[i] = temp[k];
    k++;
  }
}

void mergeSort(int arr[], int low, int high) {
  if(low < high) {
    // we want to cut array in half
    int mid = low + (high - low) / 2;
    // call merge sort on left and right part
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, high);
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

  mergeSort(arr, 0, size - 1);

  cout << "Your list after: ";
  for(int i = 0; i < size - 1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[size - 1] << endl;
}
