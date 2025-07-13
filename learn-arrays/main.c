#include <stdio.h>
#include <stdlib.h>


#define SIZE 4

int sumArray(int* arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

int findIfKeyInArray(int* arr, int size, int key) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) {
      return 1;
    }
  }
  return 0;
}

int findMax(int* arr, int size) {
  if (size <= 0) {
    return -1;
  }

  int max = arr[0];

  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

double findAverage(int* arr, int size) {
  int sum = sumArray(arr, size);
  return (double)sum / size;
}

void inputArray(int* arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("Enter value #%d: ", i+1);
    scanf("%d", &arr[i]);
  }
}

void printArray(int* arr, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    if (i == size-1) {
      printf("%d", arr[i]);
    } else {
      printf("%d,", arr[i]);
    }
  }
  printf("]\n");
}

void minMax(int* pArr, int size, int* minValue, int* maxValue) {
  int i;
  *minValue = pArr[0];
  *maxValue = pArr[0];
  
  for (i = 1; i < size; i++) {
    if (pArr[i] < *minValue) {
      *minValue = pArr[i];
    }
    if (pArr[i] > *maxValue) {
      *maxValue = pArr[i];
    }
  }
}

void updateAverage(int* pArr, int size, double* average) {
  int sumOfArray = sumArray(pArr, size);
  *average = (double)sumOfArray / size;
}

int main() {
  int arr[SIZE] = {12, 3, 16, 5};
  //int arrSize = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, SIZE);

  double average;
  updateAverage(arr, SIZE, &average);
  printf("Average: %.2f\n", average);

  /*
  printf("Sum of array: %d\n", sumArray(arr, SIZE));
  printf("Does array hold 3? %s\n", findIfKeyInArray(arr, SIZE, 3) ? "true" : "false");
  printf("Largest element: %d\n", findMax(arr, SIZE));
  printf("Average of array: %.2f\n", findAverage(arr, SIZE));

  
  int newInputArray[SIZE];
  inputArray(newInputArray, SIZE);
  printArray(newInputArray, SIZE);

  int min, max;
  minMax(newInputArray, SIZE, &min, &max);
  printf("Min: %d, Max: %d\n", min, max);
  */


}