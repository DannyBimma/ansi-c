/*Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Exercise 3-1. Our binary search makes two tests
 * inside the loop, when one would suffice (at the
 * price of more tests outside). Write a version with
 * only one test inside the loop and measure the
 * difference in run-time.*/

#include <stdio.h>

int binsearch2(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;

  while (low < high) {
    mid = (low + high) / 2;
    if (x <= v[mid])
      high = mid;
    else
      low = mid + 1;
  }

  return (x == v[low]) ? low : -1;
}

int main() {
  int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n\n");

  printf("Testing binsearch2 function:\n");
  printf("Search for 2: %d (expected: 0)\n", binsearch2(2, arr, n));
  printf("Search for 10: %d (expected: 4)\n", binsearch2(10, arr, n));
  printf("Search for 20: %d (expected: 9)\n", binsearch2(20, arr, n));
  printf("Search for 5: %d (expected: -1)\n", binsearch2(5, arr, n));
  printf("Search for 1: %d (expected: -1)\n", binsearch2(1, arr, n));
  printf("Search for 25: %d (expected: -1)\n", binsearch2(25, arr, n));

  return 0;
}
