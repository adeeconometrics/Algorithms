#include <iostream>

void selection_sort(int *arr, const int &size) {
  // finding the smallest value and place it to the first element
  for (int i = 0; i < size - 1; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++)
      if (arr[j] < arr[min])
        min = j;
    std::swap(arr[i], arr[min]);
  }
}

int main() {}