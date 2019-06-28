#include <stdlib.h>
#include <stdio.h>





// using dynamic allocation
// equal sizes arrays
 /*
void swap_arrays(int* arr1, int* arr2, int size) {
	int i;
	for ( i = 0; i < size; i++ ) {
		*(arr1 + i) ^= *(arr2 + i);
		*(arr2 + i) ^= *(arr1 + i);
		*(arr1 + i) ^= *(arr2 + i);
	}	
}		*/

// Swap different lengths arrays
void swap_diff_arrays(int* arr1, int* arr2, int arr1_size, int arr2_size) {
	int size, i;
	size = (arr1_size > arr2_size) ? arr1_size : arr2_size;

	if ( size == arr1_size )	    // Enlarge the smaller array to size of the big one
		arr2 = realloc(arr2, size * sizeof(int));
	if ( size == arr2_size )
		arr1 = realloc(arr1, size * sizeof(int));

	for ( i = 0; i < size; i++ ) {  // Swapping by looping on each element without temporary array
		arr1[i] ^= arr2[i];
		arr2[i] ^= arr1[i];
		arr1[i] ^= arr2[i];
	}

	if ( size == arr1_size )	   // Reshape the larger array to size of the smaller one
		arr1 = realloc(arr1, arr2_size * sizeof(int));
	if ( size == arr2_size )	   
		arr2 = realloc(arr2, arr1_size * sizeof(int));

}
	   
int main() {
	int i;// size;
	int *arr1 = 0, *arr2 = 0;
	int arr1_size, arr2_size;
	printf("Array1 size: ");
	scanf("%d", &arr1_size);
	printf("Array2 size: ");
	scanf("%d", &arr2_size);

	arr1 = (int *) malloc(arr1_size * sizeof(int));
	arr2 = (int *) malloc(arr2_size * sizeof(int));

	// scan elements of the two arrays
	printf("Array 1 elements: \n");
	for ( i = 0; i < arr1_size; i++ )
		scanf("%d", (arr1 + i));

	printf("Array 2 elements: \n");
	for ( i = 0; i < arr2_size; i++ )
		scanf("%d", (arr2 + i));

	// perform dynamic swapping 
	//swap_arrays(arr1, arr2, size);
	swap_diff_arrays(arr1, arr2, arr1_size, arr2_size);
	// print the results
	printf("Array 1 swaped elements: \n");
	for ( i = 0; i < arr2_size; i++ )
		printf("%d ", *(arr1 + i));
	printf("\n");
	printf("Array 2 swaped elements: \n");
	for ( i = 0; i < arr1_size; i++ )
		printf("%d ", *(arr2 + i));
	printf("\n");						 


	return 0;
}
