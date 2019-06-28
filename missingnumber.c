
/*
 missingnumber.c

 Find the smallest positive number that is missing from a given array

 Abdulmaguid Eissa
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int solution(int * arr, int n)
{
	int max_num = INT_MIN;
	int min_num = INT_MAX;

	for(int i = 0; i < n; i++)
	{
		if(arr[i] > max_num)
		{
			max_num = arr[i];
		}
		else
		{
			min_num = arr[i];
		}
	}

	if(max_num < 1)
	{
		return 1;
	}

	if(n == 1)
	{
		if(arr[0] == 1)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}

	int * arr_counts = (int *)calloc(max_num, sizeof(int));

	for(int i = 0; i < n; i++)
	{
		arr_counts[arr[i]]++;
	}

	for(int i = min_num; i < max_num; i++)
	{
		if(arr_counts[i] == 0)
		{
			return i;
		}
	}
	return max_num + 1;
}


int main()
{
	int n;
	scanf("%d", &n);
	int * arr = (int *)malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int result = solution(arr, n);
	printf("%d\n", result);
}
