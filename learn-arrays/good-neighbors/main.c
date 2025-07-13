#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int checkForGoodNeighbors(int* pArr, int size) {
  int i;
  int startIndex = 1;
  int endIndex = size - 2;

  for (i = startIndex; i <= endIndex; i++) {
    int sumOfNeighbors = pArr[i-1] + pArr[i+1];
    if (pArr[i] == sumOfNeighbors) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int arr[SIZE] = {1, 4, 7, 3, 2};
  int arr2[SIZE] = {1, 4, 1, 4, 2};

  printf("Determining if arrays have good neighbors.\n");
  
  printf("Array 1: %s\n", checkForGoodNeighbors(arr, SIZE) ? "true" : "false");

  printf("Array 2: %s\n", checkForGoodNeighbors(arr2, SIZE) ? "true" : "false");

}