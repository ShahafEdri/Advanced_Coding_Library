#include <stdio.h>
#include <stdlib.h>


int isEven(int num) {
	return 1 - num % 2;
}

int isOdd(int num) {
	return 1 - isEven(num);
}

void main() {
	int num1 = 2;
	int num2 = 3;
	printf("is %d Even? -->> %s\n", num1, (isEven(num1) ? "true" : "false"));
	printf("is %d Odd? -->> %s\n", num1, (isOdd(num1) ? "true" : "false"));
	printf("is %d Even? -->> %s\n", num2, (isEven(num2) ? "true" : "false"));
	printf("is %d Odd? -->> %s\n", num2, (isOdd(num2) ? "true" : "false"));

}