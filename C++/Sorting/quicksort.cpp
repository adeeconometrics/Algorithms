#include <iostream>

int partition(int *a, int low, int high) {
  int pivot, i, j;
  pivot = a[high];

  i = (low - 1);
  for (j = low, j <= high - 1; j++) {
    if (a[j] <= pivot) {
      i++;
      std::swap(a[i], a[j]);
    }
  }
  std::swap(a[i + 1], a[high]);
  return (i + 1);
}
// divide and conquer techniques
void quick_sort(int *arr, const int &size) {
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