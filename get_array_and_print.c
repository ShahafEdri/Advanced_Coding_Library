#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
	int* ptrAdress;
	//scanf_s("%d", &size);
	ptrAdress = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &ptrAdress[i]);
		//scanf_s("%d", ptrAdreess + i);
	}
	return ptrAdress;
}

void printArray(int* ptrAdress, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d", *(ptrAdress + i));
		//printf("%d", ptrAdress[i]);
		//ptrAdress++;
	}
}

void main() {
	int arr[20];
	int size;
	scanf_s("%d", size);
	int* ptrGrades = createArray(size);
	printArray(ptrGrades, size);
}