#include <stdio.h>
#include <stdlib.h>



void main() {
	int arr[10] = { 50,60,60,72,81,81,81,81,93,93 };
	int* ptrArr = NULL;
	int sizeOfptrArr = 0;
	for (int i = 0;i < 10;i++) {
		while (arr[i + 1] == arr[i]) { // after this i will have the value of the lat duplicated number (grades in that case) 
			i++;
		}
		ptrArr = (int*)realloc(ptrArr, (++sizeOfptrArr) * sizeof(int));
		ptrArr[sizeOfptrArr] = arr[i];
	}
	for (int i = 0;i < sizeOfptrArr;i++) {
		printf("%d  ", ptrArr[i]);

	}
}


//						    i
//					        V
//index					| 0|1 |	2| 3| 4| 5| 6|
//arr					|50|60|60|72|81|81|81|81|93|93|
//ptrArr				|50|60|72|81|93|  |
//sizeOfptrArr			|V |  | V|  |  |  |
