#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int * count_sort(int * arr, int n)
{
	int max_num = INT_MIN;

	for(int i = 0; i < n; i++)
	{
		if(arr[i] > max_num)
		{
			max_num = arr[i];
		}
	}

	int * arr_count = (int *)calloc(max_num + 1, sizeof(int));
	int * arr_res   = (int *)calloc(n, sizeof(int));

	for(int i = 0; i < n; i++)
	{
		arr_count[arr[i]]++;
	}

	int res_index = -1;
	for(int i = 0; i <= max_num; i++)
	{
		if(arr_count[i] != 0)
		{
			for(int j = 0; j < arr_count[i]; j++)
			{
				arr_res[++res_index] = i;
				//res_index++;
			}
		}
	}

	free(arr_count);
	return arr_res;
}


int main()
{
	int n;
	scanf("%d", &n);
	int * arr = malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int * res_arr = (int *)malloc(n * sizeof(int));
	res_arr = count_sort(arr, n);

	for(int i = 0; i < n; i++)
	{
		printf("%d ", res_arr[i]);
	}
	printf("\n");
}
