/*
	A program to check whether a given array is palindrome.
	i.e.
	Palindrome     {1, 2, 3, 4, 5, 4, 3, 2, 1}
	Not palindrome {1, 2, 3, 4, 5, 6, 7, 8, 9} 
*/

#include <stdio.h>

/* Returns 1 if the array is palindrome,
   Returns 0 if not.
*/

int palindrome(int* arr, int arr_size)
{
	int right = 0;
	int left = arr_size - 1;

	if (arr_size == 1)
	{
		return 1;
	}

	while ((right < (arr_size / 2)) && (left > (arr_size / 2)))
	{
		if (arr[right] != arr[left])
		{
			return 0;
		}
		right++;
		left--;
	}

	return 1;
}

int main(void)
{
	int arr[] = { 0 };

	if (palindrome(arr, 1))
	{
		printf("Palindrome\n");
	}
	else
	{
		printf("Not Palindrome\n");
	}

	return 0;
}