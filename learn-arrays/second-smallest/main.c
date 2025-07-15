#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 5

int findSecondSmallest(int* arr, int size) {
  if (size < 2) return -1;

  int i;
  int min1 = INT_MAX;
  int min2 = INT_MAX;

  for (i = 1; i < size; i++) {
    if (arr[i] < min1) {
      min2 = min1;
      min1 = arr[i];
    } else if (arr[i] < min2) {
      min2 = arr[i];
    }
  }
  return (min2 == INT_MAX) ? -1 : min2;
}

int main() {
  int arr[SIZE] = {1, 3, 5, 7, 9};
  int arr2[SIZE] = {7, 3, 5, 7, 9};
  int arr3[SIZE] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MIN};

  printf("%d is the second smallest element.\n", findSecondSmallest(arr3, SIZE));
}