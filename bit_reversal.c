#include <stdint.h>


uint32_t bit_reversing(uint32_t num, uint8_t n_bits) {
	uint8_t  bit;
	uint32_t reversed_num;

	reversed_num = 0;

	for ( bit = 0; bit < n_bits; bit++ ) {
		if ((0x01) & num) {
			reversed_num |= (1 << ((n_bits - 1) - bit));
		}
		num >>= 1;
	}
	return reversed_num;
}
