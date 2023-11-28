#include <stdio.h>

int main()
{
    int arr[] = {384,4292393,54984,323,49385,33,34,382};
    int i, n, min, j, temp;

    n = sizeof(arr) / sizeof(arr[0]);
    
    for (i = 0; i <= n - 2; i++)
    {
        min = i;
        for (j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    printf("Your Sorted Array is: %d %d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
    return 0;
}