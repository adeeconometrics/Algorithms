#include <iostream>

void shell_sort(int *arr, const int &size) {
  // divides the list into gaps, gap decreases, finalizes to insertion sort
  // faster than insertion and selection sort but have more overhead
  for (int gap = (int)(size / 2); gap > 0; gap /= 2) {
    for (int i = gap; i < size; i++) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}

int main() {}