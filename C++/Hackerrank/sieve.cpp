#include <iostream>

// seive of erathosthenes
// 1. list all int from 2 -n.
// 2. set p = 2 (smallest prime).
// 3. identify the multiples of p, and delete all multiples of p.
//	note: the number p should not be deleted
// 4. find the first number that is > p that has been deleted.

// if there is not such number -> STOP
// else let p = new number and goto 3.

// 5. when the algorithm stops, all the remaining numbers are primes.

#include <iostream>

int main() {
  int n = 100;
  int *array = new int[n + 1];

  // fill up the array
  for (int i = 0; i <= n; i++)
    array[i] = i;

  std::cout << "\n";

  for (int i = 2; i * i <= n; i++) {
    if (array[i]) {
      for (int j = i * i; j <= n; j += i) {
        array[j] = 0;
      }
    }
  }

  // display output
  for (int i = 2; i < n; i++) {
    if (array[i] != 0)
      std::cout << array[i] << " ";
  }

  delete array;
  array = nullptr;

  return 0;
}
