/* Counting sort algorithm. 
   Fits small integer numbers. */
#include <stdlib.h>
#include <stdio.h>
#include "csort.h"

int *counting_sort(int *arr, int len)
{
	int arr_max = -1;       // arr[0...arr_max]
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > arr_max)
			arr_max = arr[i];
	}

	int *count = (int *)calloc(arr_max, sizeof(int));
	int *pos = (int *)calloc(arr_max, sizeof(int));
	int *res = (int *)calloc(len, sizeof(int));

	// number of occurrences loop
	for (int i = 0; i < len; i++)  
	{
		count[arr[i]] += 1;
	}

	// each number begining position loop
	// each number’s position begins at the previous number’s position + 
	// the number of occurrences of that number.
	pos[0] = 0;
	for (int i = 1; i <= arr_max; i++)
	{
		pos[i] = pos[i - 1] + count[i - 1];
	}

	// expanding the counts in array
	for (int i = 0; i < len; i++)
	{
		res[pos[arr[i]]] = arr[i];
		pos[arr[i]]++;
	}
	free(pos);
	free(count);
	return res;
}

int main(void)
{
	int *arr;
	int arr_size;
	int i;

	scanf("%d", &arr_size);
	arr = (int *)malloc(arr_size * sizeof(int));

	for (i = 0; i < arr_size; i++)
	{
		scanf("%d", (arr + i));
	}

	arr = counting_sort(arr, arr_size);

	for (i = 0; i < arr_size; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	free(arr);

	return 0;
}