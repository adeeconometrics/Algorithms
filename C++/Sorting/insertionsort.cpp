#include <iostream>

void insertion_sort(int *arr, const int &size) {
  // appropriate for small inputs compared to bubble and selection sort
  // uses temp variable
  int i, j;
  for (i = 1; i < size; i++) {
    int temp = arr[i];
    for (j = i + 1; j > 0 && temp < arr[j - 1]; j--)
      arr[j] = arr[j - 1];
    arr[j] = temp;
  }
}

int main() {}