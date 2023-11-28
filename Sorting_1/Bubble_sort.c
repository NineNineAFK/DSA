#include<stdio.h>

void bubblesort(int array[], int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){

            if( array[j]>array[j+1]){

                temp= array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }


}

void printarray(int array[], int n){
    for( int i=0; i<n; i++)
     printf("\narray- %d", array[i]);


}

int main(){
  
  int arr[]={12, 22, 1, 33, 4};
  int n = sizeof(arr)/sizeof (arr[0]);

  bubblesort(arr,n);

  printf("\narray new-");
  printarray(arr,n);



    return 0;
}