// C++ program for implementation of Bubble sort  
//#include <bits/stdc++.h> 
using namespace std;

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//implementation of maxSwap in selectionSort
void selectionSort(int arr[], int n)
{
	int i, j, min_idx, max_idx;
	int size = n;
	// One by one move boundary of unsorted subarray  
	for (i = 0; i < n - 1; i++, n--)
	{
		// Find the minimum element in unsorted array  
		min_idx = i;
		max_idx = n - 1;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
			if (arr[j] > arr[max_idx])
				max_idx = j;
		}

		// Swap the found minimum element with the first element  
		swap(&arr[min_idx], &arr[i]);
		swap(&arr[max_idx], &arr[n - 1]);

	}
}

// implementation of even-odd sort on top of bubble sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}


//| 1 | 2 | 3 | 4 | 5 |