#include <iostream>

void bubble_sort(int arr[], const int &size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = size - 1; j > i; j--) {
      if (arr[j - 1] > arr[j])
        std::swap(arr[j], arr[j - 1]);
    }
  }
}

int main() {
  int arr[] = {2, 3, 4, 1, 5, 6, 7, 2, 8, 9, 1};
  bubble_sort(arr, 11);
  for (int i = 0; i < 11; i++) {
    std::cout << arr[i] << " ";
  }
}