#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapInts(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swapIntsNoThird1(int* a, int* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void swapIntsNoThird2(int* a, int* b) {
	*a = *a * *b;
	*b = *a / *b;
	*a = *a / *b;
}

void genericSwap(void* a, void* b, int size) {
	void* tempMemory = malloc(size);
	memcpy(tempMemory, a, size);
	memcpy(a, b, size);
	memcpy(b, tempMemory, size);
	free(tempMemory);
}

int main() {
	int num1 = 6;
	int num2 = 4;
	double double1 = 12.0;
	double double2 = 10.0;
	
	printf("Before Swap\nnum1: %d, num2: %d, double1: %.2f, double2: %.2f\n", 
    num1, num2, double1, double2);
	
	swapInts(&num1, &num2);

	printf("After swapInts\nnum1: %d, num2: %d, double1: %.2f, double2: %.2f\n", 
    num1, num2, double1, double2);

	swapIntsNoThird1(&num1, &num2);

	printf("After swapIntsNoThird1\nnum1: %d, num2: %d, double1: %.2f, double2: %.2f\n", 
    num1, num2, double1, double2);

	swapIntsNoThird2(&num1, &num2);

	printf("After swapIntsNoThird2\nnum1: %d, num2: %d, double1: %.2f, double2: %.2f\n", 
    num1, num2, double1, double2);

	genericSwap(&double1, &double2, sizeof(double));

	printf("After genericSwap\nnum1: %d, num2: %d, double1: %.2f, double2: %.2f\n", num1, 
    num2, double1, double2);
}