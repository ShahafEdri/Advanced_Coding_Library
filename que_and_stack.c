#define isCircleBrackets(chr) (((chr)=='(')||((chr)==')'))
#define isSquereBrackets(chr) (((chr)=='[')||((chr)==']'))
#define isCurlyBrackets(chr) (((chr)=='{')||((chr)=='}'))
#define isOpeningBrackets(chr) (((chr)=='{') || ((chr)=='(') || ((chr)=='['))
#define isBrackets(chr) (isCircleBrackets(chr) || isSquereBrackets(chr) || isCurlyBrackets(chr))


#include <stdio.h>
#include <stdlib.h>
#include "Queue_arr.h"
#include "Stack_arr.h"

int isEven(int num) {
	return 1 - num % 2;
}

int isOdd(int num) {
	return 1 - isEven(num);
}

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

int isPolindrom(char* arr, int size) {
	char var1;
	char var2;
	stack* stack1 = (stack*)malloc(1 * sizeof(stack)); //stack size == 100
	stack* stack2 = (stack*)malloc(1 * sizeof(stack)); //stack size == 100
	create_stack(stack1);
	create_stack(stack2);
	for (int i = 0; i < size / 2; i++) {
		push(arr[i], stack1);
		push(arr[size - 1 - i], stack2);
	}
	for (int i = 0; i < size / 2; i++) {
		pop(stack1, &var1);
		pop(stack2, &var2);
		if (!(var1 == var2)) {
			return 0;
		}
	}
	return 1;
}

//			V
//			1|2|3|4|3|2|1|	==>	size_of_stack %2? 
//			1|2|3|4|5|6|7|

//stack 1	1|3|
//stack 2	2|

queue sortQueByEven(queue que, int sizeOfQue) {
	int tmp;
	queue* evenQue = (queue*)malloc(1 * sizeof(queue));
	queue* oddQue = (queue*)malloc(1 * sizeof(queue));
	create_queue(evenQue);
	create_queue(oddQue);
	for (int i = 0; i < sizeOfQue; i++) {
		dequeue(&que, &tmp);
		if (isEven(tmp))
			enqueue(tmp, evenQue);
		else
			enqueue(tmp, oddQue);
	}
	int evenCount = evenQue->items_num;
	for (int i = 0; i < evenCount; i++) {
		if (dequeue(evenQue, &tmp))
			enqueue(tmp, &que);
	}
	int oddCount = oddQue->items_num;
	for (int i = 0; i < oddCount; i++) {
		if (dequeue(oddQue, &tmp))
			enqueue(tmp, &que);
	}
	return que;
}

int isQueSymmetric(queue* pq1, queue* pq2) {
	//int size = 100;
	stack helpStack;
	create_stack(&helpStack);
	int isSymmeticFlag = 1;
	int tmp1;
	int tmp2;

	if (pq1->items_num == pq2->items_num) {
		int queSize = pq1->items_num;
		for (int i = 0; i < queSize; i++) {
			dequeue(pq2, &tmp1);
			enqueue(tmp1, pq1);
			push(tmp1, &helpStack);
		}
		for (int i = 0; i < queSize; i++) {
			dequeue(pq1, &tmp1);
			pop(&helpStack, &tmp2);
			enqueue(tmp1, pq2);
			if (tmp1 != tmp2)
				isSymmeticFlag = 0;
		}
		for (int i = 0; i < queSize; i++) {
			dequeue(pq1, &tmp1);
			enqueue(tmp1, pq2);
			dequeue(pq2, &tmp1);
			enqueue(tmp1, pq1);
		}
		return isSymmeticFlag;
	}
	return 0;
}

int isValidAritmeticExpresion(char* str) {
	stack stk;
	create_stack(&stk);
	char chr;
	for (int i = 0; str[i] != '\0'; i++) {
		if (isBrackets(str[i])) {
			if (isOpeningBrackets(str[i]))
				push(str[i], &stk);
			else {
				stack_top(&stk, &chr);
				if (str[i] == ')' && chr == '(')
					pop(&stk, &chr);
				else if (str[i] == ']' && chr == '[')
					pop(&stk, &chr);
				else if (str[i] == '}' && chr == '{')
					pop(&stk, &chr);
				else
					return 0;
			}
		}
	}
	return 1;
}

#define SIZE 3
#define SIZE1 8
#define SIZE2 8

int main() {


	//*************
	// UNCOMMENT ME
	//*************
	//char arr[SIZE] = { 'm','o','m' }; // '\0'
	//int size = SIZE;
	//int flag = isPolindrom(arr, size);
	//printf("the arr %s a Polindrom", flag ? "IS" : "IS NOT");

	//*************
	// UNCOMMENT ME
	//*************
	//unsigned int arr1[SIZE1] = { 1,2,3,4,5,6,7,8 };
	//int sizeOfarr1 = SIZE1;
	//int tmp = (int*)malloc(1 * sizeof(int));
	////queue* que = (queue*)malloc(1 * sizeof(queue));
	//queue que;
	//create_queue(&que);
	//for (int i = 0; i < SIZE1; i++) {
	//	enqueue(arr1[i], &que);
	//}
	//que = sortQueByEven(que, sizeOfarr1);
	//for (int i = 0; i < SIZE1; i++) {
	//	dequeue(&que, &tmp);
	//	printf("%d ", tmp);
	//}

	//*************
	// UNCOMMENT ME
	//*************
	//int size = 6;
	//queue que1, que2;
	//int tmp;
	//create_queue(&que1);
	//create_queue(&que2);
	//for (int i = 0; i < size; i++) {
	//	enqueue(i, &que1);
	//	tmp = size - 1 - i;
	//	enqueue(tmp, &que2);
	//}
	//char ch = (isQueSymmetric(&que1, &que1) ? 'T' : 'F');
	//printf("are the Que's symmetrical? -->> %c\n", ch);

	//*************
	// UNCOMMENT ME
	//*************
	char aritmeticExpresion[] = "( a + b ) – [ c + d ] - { f + g } ";
	int flag = isValidAritmeticExpresion(aritmeticExpresion);
	printf("Flag {isValidAritmeticExpresion} returned -->> %d", flag);
}
