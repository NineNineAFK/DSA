#include <stdio.h>

// Objective: To Binary Search An Array of numbers 

int BinarySearch(int arr[],int low,int high,int key)
{   

    if(low<=high)
    {
         int mid= (low+high)/2;

        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            return BinarySearch(arr,mid+1,high,key);
        }
        else
        {
            return BinarySearch(arr,low,mid-1,key);
        }
      
    }

    return -1;
}

int main()
{
    int arr[] = {1, 4, 7, 9, 16, 56, 70};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x= BinarySearch(arr,0, n-1, 70 );
    if(x != -1)
    {
        printf("Element found at index: %d", x);
    }
    else
    {
        printf("Element not found");
    }

    return 0;
}