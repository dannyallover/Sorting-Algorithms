/*
radix sort implemented in c++
runtime: Omega(nlog(n))
written by: dannyallover
date: 08/07/2018
*/
#include<iostream>
#include<vector>

using namespace std;

void countSort(int arr[], int size, int exp) {
  int temp[size];
  int count[10] = {0};

  for(int i = 0; i < size; i++)
    count[(arr[i]/exp)%10]++;

  for(int i = 1; i < 10; i++)
    count[i] += count[i-1];

  for(int i = 0; i < size; i++) {
    temp[count[(arr[i]/exp)%10] - 1] = arr[i];
    count[(arr[i]/exp)%10]--;
  }

  for(int i = 0; i < size; i++)
    arr[i] = temp[i];
}
int getMax(int arr[], int size) {
  int max = arr[0];
  for(int i = 1; i < size; i++) {
    if(max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

void radixSort(int arr[], int size) {
  int max = getMax(arr, size);

  for(int i = 1; max/i > 0; i *= 10) {
    countSort(arr, size, i);
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

  radixSort(arr, size);

  cout << "Your list after: ";
  for(int i = 0; i < size - 1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[size - 1] << endl;
}
