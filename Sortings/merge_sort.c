#include <stdio.h>

void Merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int B[100];

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            B[k] = arr[i];
            i++;
        } else {
            B[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        B[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        B[k] = arr[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++) {
        arr[i] = B[i];
    }
}

void MergeSort(int arr[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {9, 4, 4, 8, 7, 5, 6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, 0, arr_size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
