#include <stdio.h>
#include <stdlib.h>




int main() {
	int i;
	int counter1 = 0, counter2 = 0;
	int last_index = 0;
	int n;
	scanf_s("%d\n", &n);
	int *arr = (int*)calloc(n, sizeof(int));

	for ( i = 0; i < n; i++ )
		scanf_s("%d", &arr[i]);
	//int arr[] = { 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4 };
	int selected_input;
	scanf_s("%d", &selected_input);

	if ( n > 1 ) {
		for ( i = 0; i < n - 1; i++ ) {		 // Find number of input repetitions
			if ( arr[i] == selected_input ) {
				counter1++;
				if ( arr[i + 1] != selected_input ) {
					last_index = i;
					break;
				}
			}
		}

		for ( i = last_index + 1; i < n; i++ ) {
			if ( arr[i] == selected_input ) {
				counter2++;
			}
		}

		if ( counter1 > counter2 )
			printf("(%d)\n", counter1);
		else
			printf("(%d)\n", counter2);
	}

	else {
		if ( selected_input == *arr )
			printf("(1)\n");
		else
			printf("(0)\n");
	}
	free(arr);
	return 0;
}