#define _CRT_SECURE_NO_WARNINGS

#define isDigit(num) (((num) >= '0') && ((num) <= '9'))
#define isOperator(num) (((num) == '+') || ((num) == '-') || ((num) == '*') || ((num) == '/'))
#define EOS '\0'		//  '\0' = 0

#include <stdio.h>
#include <stdlib.h>

float calculator(char* phrase) {

	int num1 = 0;
	int num2 = 0;

	bool isNum1Finished = false; //index of the last character of the first calculated number
	//int index2 = -1; //index of the first character of the second calculated number
	char op = '\0';

	for (int i = 0; phrase[i] != EOS; i++) {						//iterate the whole loop
		if ((isDigit(phrase[i])) && !isNum1Finished) {
			num1 *= 10;
			num1 += phrase[i] - '0';
		}
		else if (!isNum1Finished) {
			isNum1Finished = true;
		}
		else if (isOperator(phrase[i])) {
			op = phrase[i];
		}
		else if (isDigit(phrase[i])) {
			num2 = num2 * 10;
			num2 += phrase[i] - '0';
		}
	}
	// after this the i var will be equal to the length of str + '\0'

	//0 | 1 | 2 | 3 | 4 | 5 | 6 | = indexes
	//5 | 1 | 3 | 9 | 7 | 6 | 6 | = values

	/*bool isNum1Finished = false
		if (digit && !isNum1Finished)
			insert to num1
		else if (operator)
			insert to op
		else if (digit)
			insert to num2

			if (!digit)
				isNumFinished = true*/
				//parse each number num1 and num2

	switch (op)
	{
	case('+'):
		printf("executing %d %c %d \n\n", num1, op, num2);
		return ((float)num1 + (float)num2);
	case('-'):
		printf("executing %d %c %d \n\n", num1, op, num2);
		return ((float)num1 - (float)num2);
	case('*'):
		printf("executing %d %c %d \n\n", num1, op, num2);
		return ((float)num1 * (float)num2);
	case('/'):
		printf("executing %d %c %d \n\n", num1, op, num2);
		return ((float)num1 / (float)num2);
	default:
		printf("nothing was printed , operator wasn't identified");
	};
};


int main()
{
	float result;
	char phrase[80] = "0123+1111";			// "34 + 32"
	printf("Enter an equation in the following format \"num1 {operator} num2\"\n");
	//fgets(phrase, 80, stdin);
	if (!(isDigit(phrase[0])))
		printf("ERROR - you didnt not follow the format\n first Digit is not a num");
	printf("%s\n", phrase);
	result = calculator(phrase);
	printf("the result of the calculation is %.2f\n", result);

	printf("end\n");
}