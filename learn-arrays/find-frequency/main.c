#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void displayFrequency(int* arr, int size) {
  int i, j;
  int passFlag;
  int freqCount;

  for (i = 0; i < size; i++) {
    // loop inner index here..
    freqCount = 0;
    for (j = 0; j < size; j++) {
      if (j < i) {
        passFlag = (arr[i] == arr[j]);
      }
      if (passFlag) {
        break;
      }
      if (arr[i] == arr[j]) {
        freqCount++;
      }
    }

    if (passFlag) {
      continue;
    }
    printf("%d has a frequency of %d\n", arr[i], freqCount);
  }

}

int main() {
  int arr[SIZE] = {1, 5, 5, 3, 5};

  displayFrequency(arr, SIZE);
}