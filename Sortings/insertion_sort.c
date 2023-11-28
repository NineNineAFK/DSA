#include <stdio.h>

// Objective: Sort an array using insertion sort.

int arr[] = {9, 3, 8, 1, 63, 49};

int n = sizeof(arr) / sizeof(arr[0]);

int i, j, temp;

int main()
{
    for (i = 0; i <= n - 1; i++)
    {
        j = i;

        while (arr[j - 1] > arr[j] && j > 0)
        {
            // swap
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;

            j--;
        }
    }

    printf("Your Desired Array Using Insertion Sort Is: %d %d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);

    return 0;
}