#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
	int j;
	for ( j = 2; j < n; j++ ) 
		if ( n % j == 0 )
			return false;
	return true;
}

void prime_numbers(int num) {
	if ( num > 1 ) {
		int i;
		for ( i = 2; i <= num; i++ ) {
			if ( is_prime(i) )
				printf("%d ", i);
		}
		printf("\n");
	}
	else
		printf("No prime numbers in range\n");
}



int main() {
	int num;
	scanf_s("%d", &num);
	prime_numbers(num);
	return 0;
}