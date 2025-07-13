#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void swap(int* a, int* b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void sortArray(int* pArr, int size) {
  int startIndex, selectedIndex, endIndex;
  endIndex = size - 2;
  for (startIndex = 0; startIndex <= endIndex; startIndex++) {
    for (selectedIndex = startIndex + 1; selectedIndex < size; selectedIndex++) {
      if (pArr[startIndex] > pArr[selectedIndex]) {
        swap(&pArr[startIndex], &pArr[selectedIndex]);
      }
    }
  }
}

int isSortedArray(int* pArr, int size, int* isStrictlySorted) {
  int i;
  *isStrictlySorted = 1;
  for (i = 1; i < size; i++) {
    if (pArr[i-1] > pArr[i]) {
      *isStrictlySorted = 0;
      return 0;
    }
    if (pArr[i] == pArr[i-1]) {
      *isStrictlySorted = 0;
    }
  }
  return 1;
}

int isSortedArrayRecursive(int* pArr, int size, int* isStrictlySorted) {
  int result;
  if (size == 1) { 
    *isStrictlySorted = 1;  
    return 1;
  }

  result = isSortedArrayRecursive(pArr, size-1, isStrictlySorted);
  
  if (result != 0 && pArr[size-1] == pArr[size-2]) { 
    *isStrictlySorted = 0;
  }

  if (result != 0 && pArr[size-1] < pArr[size-2]) {
    *isStrictlySorted = 0;
    return 0;
  }
  return result;
}

void displayArray(int* pArr, int size) {
  int i;
  printf("[");
  for (i = 0; i < size; i++) {
    if (i < size - 1) {
      printf("%d, ", pArr[i]);
    } else {
      printf("%d", pArr[i]);
    }
  }
  printf("]\n");
}

int main() {
  int arr1[] = {1, 2, 5, 7, 10};
  int arr2[] = {1, 2, 2, 5, 10};
  int arr3[] = {1, 2, 5, 3, 10};
  int isStrictlySortedFlag;
  int isSorted;

  displayArray(arr3, SIZE);
  isSorted = isSortedArray(arr3, SIZE, &isStrictlySortedFlag);

  if (isStrictlySortedFlag) {
    printf("Array is strictly sorted.\n");
  } else {
    if (isSorted) {
      printf("Array is sorted.\n");
    } else {
      printf("Array is not sorted.\n");
    }
  }

  sortArray(arr3, SIZE);
  displayArray(arr3, SIZE);
  isSorted = isSortedArrayRecursive(arr3, SIZE, &isStrictlySortedFlag);

  if (isStrictlySortedFlag) {
    printf("Array is strictly sorted.\n");
  } else {
    if (isSorted) {
      printf("Array is sorted.\n");
    } else {
      printf("Array is not sorted.\n");
    }
  }

  

  

}