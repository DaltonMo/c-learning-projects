#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void displayArray(int* arr, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if (i < size-1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int findSumOfTwo(int* arr, int size, int value, int* iPtr, int* jPtr) {
	int i, j;
	i = 0;
	j = size-1;
	int currentSum;

	while (i < j) {
		currentSum = arr[i] + arr[j];
		if (currentSum == value) {
			*iPtr = i;
			*jPtr = j;
			return 1;
		} else if (currentSum < value) {
			i++;
		} else {	// currentSum >= value
			j--;
		}
	}
	*iPtr = 0;
	*jPtr = 0;
	return 0;
}

int main() {
	int sortedArray[SIZE] = {1, 3, 5, 7, 9};	
	displayArray(sortedArray, SIZE);

	int sum = 16;
	int indexOne;
	int indexTwo;
	int foundFlag = findSumOfTwo(sortedArray, SIZE, sum, &indexOne, &indexTwo);
	if (foundFlag) {
		printf("Found a match! The two values that sum of %d are %d and %d\n", 
				sum, sortedArray[indexOne], sortedArray[indexTwo]);
	} else {
		printf("Could not find a match for the sum of %d!\n", sum);
	}
}
