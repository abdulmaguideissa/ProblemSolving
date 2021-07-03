/*
	A program to count the max number of consective zeros between 2 ones
	of a given number - in its binary format.
*/

#include <stdio.h>

int max_zeros(int number)
{
	int max_zeros = 0;
	int prev_right = 0;
	int curr_right = 0;
	int bit = 0;

	/* Find the rightmost 1 to start counting from it. */
	/* Exit immediately if the number is 0. */
	while (!(number & (1 << prev_right)) & (number != 0))
	{
		prev_right = prev_right + 1;
	}

	/* start counting the zeros, while updating the value of 'prev_right'. */
	curr_right = prev_right;
	for (bit = prev_right + 1; bit < (sizeof(int) * 8); bit++)
	{
		curr_right = curr_right + 1;

		/* Find a new 1 and update max_zeros value. */
		if (number & (1 << bit))
		{
			if (max_zeros < (curr_right - prev_right - 1))
			{
				max_zeros = (curr_right - prev_right - 1);
			}
			prev_right = curr_right;
		}
	}

	return max_zeros;
}

int main(void)
{
	printf("%d\n", max_zeros(16));
	return 0;
}