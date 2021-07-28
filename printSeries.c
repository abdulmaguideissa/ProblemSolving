// Write a function that complete the following series given the requested size of the series:
// 1 1 2 4 7 13 24 44 81

#include <stdio.h>
#include <stdlib.h>

void series_print(int num)
{
    int index = 1;
    int *arr = (int*)malloc(num * sizeof(int));

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    for(index = 0; index < num; index++)
    {
        if(index <= 2)
        {
            printf("%d ", arr[index]);
        }

        else
        {
            arr[index] = arr[index - 1] + arr[index - 2] + arr[index - 3]; 
            printf("%d ", arr[index]);
        }     
    }
    printf("\n");
}

int main(void)
{
    series_print(20);

    return 0;
}