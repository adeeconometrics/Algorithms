#include <iostream>

void merge(int *a, const int &l, const int &m, const int &r) {
  int i, j, k;
  int *L, *R;
  int n1 = (m - 1) + 1;
  int n2 = r - m;
  L = new int[n1];
  R = new int[n2];

  for (i = 0; i < n1; i++)
    L[i] = a[l + i];
  for (j = 0; j < n2; j++)
    R[j] = a[m + 1 + j];

  i = 0;
  j = 0;
  k = 0;
}
// divide and conquer ~ uses recursive functions
void merge_sort(int *a, const int &l, const int &r) {
  // divides list into halves continuously until it reaches the smallest unit
  if (l < r) {
    int m = l + (r - 1) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge(a, l, m, r);
  }
  // sort each halve separately

  // merge the sorted halves into one sorted array
} 

int main() {}