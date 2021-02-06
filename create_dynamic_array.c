#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
	int* ptrAdress;
	ptrAdress = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &ptrAdress[i]);
	}
	return ptrAdress;
}

void printArray(int* ptrAdress, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d", ptrAdress[i]);
	}
}

void main() {
	int arr[20] = { 0 };
	int size = 0;
	scanf_s("%d", size);
	int* ptrGrades = createArray(size);
	printArray(ptrGrades, size);
}