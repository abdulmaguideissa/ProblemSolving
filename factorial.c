#include <stdio.h>
#include <stdlib.h>

#define SIZEINT       sizeof(int)

// return pointer to integer
// allocate memory for result integer to pointer.
int* factorial(int * n){
	int *result = (int*) malloc(SIZEINT);
	*result = 1;
	while ( *n > 0 ) {
		*result *= *n;
		(*n)--;
	}
	return result;
}


unsigned int fact(unsigned int n) {
	unsigned int i, result = 0;
	unsigned int* factorial = (int*)malloc(n * sizeof(int));
	factorial[0] = 1;
	factorial[1] = 1;
	for ( i = 2; i <= n; i++ )
		factorial[i] = factorial[i - 1] * factorial[i - 2];
	factorial[n] *= n;


}
// return int
/*int factorial(int * n) {
	int result = 1;
	while ( *n > 0 ) {
		result *= *n;
		(*n)--;
	}
	return result;
}*/



int main(void) {
	int *fact, num = 6;
	fact = factorial(&num);
	printf("%d\n", *fact);
	
	return 0;
}
