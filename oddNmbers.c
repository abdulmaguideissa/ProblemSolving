#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32_t;

uint32_t* find_odd_numbers(uint32_t r, uint32_t l, uint32_t* result_count) {
	uint32_t i;
	uint32_t* result;
	*result_count = l - r;
	result = (int*)malloc((*result_count) * sizeof(int));
	*result_count = 0;
	for ( i = r; i <= l; i++ ) {
		if ( (i & 1) == 1 ) {
			result[*result_count] = i;
			(*result_count)++;
		}
	}
	result = (int*)realloc(result, *result_count * sizeof(int));
	return result;
}


int main(void) {
	uint32_t result_count;
	uint32_t i;
	uint32_t r = 2, l = 9;
	uint32_t* arr;
	arr = find_odd_numbers(r, l, &result_count);

	for ( i = 0; i < result_count; i++ ) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
