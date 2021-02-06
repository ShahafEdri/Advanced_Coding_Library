#include <stdio.h>
#include <stdlib.h>
#include "doubly_list.h"

int isDoublyListPolindrom(list* lst, int listLen) {
	node* tempNext = NULL;
	node* tempPrev = NULL;
	if (!isEmpty(lst)) {
		tempNext = lst->head;
		tempPrev = lst->tail;
		for (int i = 0; i < listLen / 2; i++) {
			if (tempNext->value != tempPrev->value)
				return 0;
			tempNext = tempNext->next;
			tempPrev = tempPrev->prev;
		}
		return 1;
	}
	return 0;
}

void insertZeroBeforeK(list* lst, int k) {
	for (node* current = lst->head; current != NULL; current = current->next) {
		if (current->value % k == 0)
			insertBefore(lst, allocItem(0), current);
	}
}

void deleteDuplicatesDoublyList(list* lst) {
	int arr[100] = { 0 };
	int arrSize = 0;
	int isValueInArray = 0;
	//for (node* current = lst->head; current != NULL; current = current->next) {
	node* current = lst->head;
	node* temp;
	while (current != NULL) {
		int i;
		for (i = 0; i < arrSize; i++) { // is value already in the array?
			if (arr[i] == current->value) {
				isValueInArray = 1;
				break;
			}
		}
		if (isValueInArray) {
			temp = current;
			current = current->next;
			deleteLink(lst, temp);
		}
		else {
			arr[i] = current->value;
			arrSize++;
			current = current->next;
		}
	}
}

void question1()
{
	list* lst = (list*)malloc(sizeof(list));
	initList(lst);
	node* item = NULL;
	for (int i = 0; i < 10; i++) {
		item = allocItem((char)(i + 48));
		insertLast(lst, item);
		item = allocItem((char)(i + 48));
		insertFirst(lst, item);
	}
	int listLen = length(lst);
	int flagPolindrom = isDoublyListPolindrom(lst, listLen);
	printf("flag polindrom returned %d", flagPolindrom);
}

void question2() {
	list* lst = (list*)malloc(sizeof(list));
	initList(lst);
	node* current = NULL;
	for (int i = 1; i < 10; i++) {
		current = allocItem(i);
		insertLast(lst, current);
		//current = allocItem(i);
		//insertFirst(lst, current);
	}
	int listLen = length(lst);
	printDoublyList(lst);
	printf("\n");
	insertZeroBeforeK(lst, 4);
	printDoublyList(lst);
	printf("\n");
}

void question3() {
	list* lst = (list*)malloc(sizeof(list));
	initList(lst);
	node* current = NULL;
	for (int i = 1; i < 10; i++) {
		current = allocItem(i);
		insertLast(lst, current);
		current = allocItem(i);
		insertFirst(lst, current);
	}
	int listLen = length(lst);
	printDoublyList(lst);
	deleteDuplicatesDoublyList(lst);
	printDoublyList(lst);
}

void main() {
	//question1();
	//question2();
	question3();

}
