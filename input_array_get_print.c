#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


void inputArray(int* arr, int n) {
	for (int i = 0;i < n;i++) {
		scanf("%d", arr);
		arr++;
	}
}

//|0|1|2|3
//|1|2|3|4

void printArray(int* arr, int n) {
	for (int i = 0;i < n;i++) {
		printf("%d", *arr);
		arr++;
	}
}

void main() {
	int str[3];
	int len = 3;
	inputArray(str, len);
	printArray(str, len);
}