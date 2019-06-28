#include <stdio.h>
#include <stdlib.h>





int main() {
	
	int i = 0, result = 0;
	int n;
	scanf_s("%d", &n);
	int* arr = malloc(n * sizeof(int));
	//int arr[6] = { 1, 2, 3, 2, 4, 2 };
	for ( i = 0; i < n; i++ )
		scanf_s("%d", &arr[i]);	 
	int value;
	scanf_s("%d", &value);

	for ( i = 0; i < n; i++ ) {
		if ( arr[i] == value ) {
			result = i;
		}
	}
	printf("%d\n", result);	

	return 0;
}