/*
quick sort implemented in c++
runtime: (O(n^2)), typically acts as O(nlog(n))
written by: dannyallover
date: 08/05/2018
*/
#include<iostream>
#include<vector>

using namespace std;

void countingSort(int arr[], int range, int size) {
  int arrCount[range + 1];
  int temp[size];

  memset(arrCount, 0, sizeof(arrCount));

  // count number of occurences of elements
  for(int i = 0; i < size; i++) {
    arrCount[arr[i]]++;
  }

  for(int i = 1; i < range + 1; i++) {
    arrCount[i] += arrCount[i - 1];
  }

  for(int i = 0; i < size; i++) {
    temp[arrCount[arr[i]] - 1] = arr[i];
    arrCount[arr[i]]--;
  }

  for(int i = 0; i < size; i++) {
    arr[i] = temp[i];
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

  countingSort(arr, range, size);

  cout << "Your list after: ";
  for(int i = 0; i < size - 1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[size - 1] << endl;
}
