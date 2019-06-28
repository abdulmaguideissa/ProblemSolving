#include <stdio.h>
#include <stdlib.h>




int main() {
	int i, j;
	int counter = 0;
	int max_counter = -1;
	int n;
	scanf_s("%d", &n);
	int *arr = (int*)calloc(n, sizeof(int));

	for ( i = 0; i < n; i++ )
		scanf_s("%d", &arr[i]);

	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n - 1; j++ ) {
			if ( arr[i] == arr[j] ) {
				counter++;
				if ( counter > max_counter )
					max_counter = counter;
				if ( arr[j] != arr[j + 1] ) {
					counter = 0;
					break;
				}
			}
		}
	}

	printf("%d\n", max_counter);
	free(arr);
	return 0;
}