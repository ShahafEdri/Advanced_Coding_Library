#include <stdio.h>
#include<stdlib.h>


int square(int num) {
	return num * num;
}

int cube(int num) {
	return num * num * num;
}

int power(int num, int pwr) {
	int multiplier = num;
	for (int i = 0; i < pwr - 1; i++)
		num *= multiplier;
	return num;
}

void main() {
	int num = 3;
	printf("the number you entered\t-->>\t%d\n", square(num));
	printf("that number squared is \t-->>\t%d\n", cube(num));
	printf("that number cubed is \t-->>\t%d\n", power(num, 4));
	printf("\n\n");

}