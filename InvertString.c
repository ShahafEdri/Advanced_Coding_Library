#include <stdio.h>
#include <stdlib.h>

//#define isDigit(num) (num >= '0') && (num)

void invert(char* arr) {
	int i;
	char tempArr[80];
	for (i = 0; *arr != '\0'; i++) {
		tempArr[i] = *arr;
		arr++;
	}
	arr -= i;
	for (int j = 0; arr[j] != '\0'; j++) {
		arr[j] = tempArr[(i - 1) - j];
	}
	//free(tempArr);
}


//		v                 y
//		0|1|2|3|4|5|6|7|8|9|
//		5|6|4|8|6|2|1|8|9|5|



void main() {
	char* inp;
	*inp = "123456789";
	//for 
	//fgets(inp, 80, stdin);
	invert(inp);
	printf("the value is %s", inp);
}