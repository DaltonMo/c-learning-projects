#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

void displayArray(char* pArr, int size) {
  int i;
  printf("[");
  for (i = 0; i < size; i++) {
    if (i < size - 1) {
      printf("%c, ", pArr[i]);
    } else {
      printf("%c", pArr[i]);
    }
  }
  printf("]\n");
}

void swap(char* a, char* b) {
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void reverseArray(char* pArr, int size) {
  int i;
  int endIndex = size - 1;
  for (i = 0; i < size/2; i++) {
    swap(&pArr[i], &pArr[endIndex-i]);
  }
}

void reverseArrayRecursive(char* pArr, int size) {
  if (size > 1) {
    swap(&pArr[0], &pArr[size-1]);
    reverseArrayRecursive(pArr + 1, size - 2);
  }
}

int main() {
  char arr[SIZE] = {'a', 'b', 'c', 'd'};

  displayArray(arr, SIZE);
  reverseArrayRecursive(arr, SIZE);
  displayArray(arr, SIZE);
  reverseArray(arr, SIZE);
  displayArray(arr, SIZE);
}