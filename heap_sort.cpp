/*
heap sort implemented in c++
complexity: heapify is O(log(n)) and buildheap is O(n), together O(nlog(n))
written by: dannyallover
date: 08/05/2018
*/
#include<iostream>
#include<vector>

using namespace std;

void maxHeapify(int arr[], int i, int size) {
  int largest = i; // initialize largest as root
  int left = 2*i + 1; // how to access left of root in arr
  int right = 2*i + 2; // how to access right of root in arr
  if(left < size && arr[left] > arr[largest]) {
    largest = left;
  }
  if(right < size && arr[right] > arr[largest]) {
    largest = right;
  }

  if(largest != i) {
    swap(arr[i], arr[largest]);
    maxHeapify(arr, largest, size);
  }
}

void buildMaxHeap(int arr[], int size) {
  for(int i = (size / 2) - 1; i >= 0; i--) {
    maxHeapify(arr, i, size);
  }
}

void heapSort(int arr[], int size) {
  buildMaxHeap(arr, size);

  for(int i = size - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);

    maxHeapify(arr, 0, i);
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

  heapSort(arr, size);

  cout << "Your list after: ";
  for(int i = 0; i < size - 1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[size - 1] << endl;
}
