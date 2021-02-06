#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define isReminderZero(num,devisor) (!((num) % (devisor)))

bool isPrime(int n) {
	int sqrtn = (int)sqrt(n);
	for (int i = 2; i <= sqrtn;i++)
		if (isReminderZero(n, i))
			return false;
	return true;
}

void main() {
	int totalPrimeFound = 0;
	printf("prime numbers:\n");
	for (int i = 2;totalPrimeFound <= 100;i++) {
		if (isPrime(i)) {
			printf("%d, ", i);
			totalPrimeFound++;
		}
	}
	printf("\nEND");
}