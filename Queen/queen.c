#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int board[20], count; //initialize board array to store the position of the queen in each row
                      //and initialize count to store the number of solutions found

int main()
{
    int n,i,j;
    void queen(int row,int n); //declare the function prototype for queen()
    printf("enter no of queens");
    scanf("%d", &n);
    queen(1,n);
   
    return 0;
}

void print(int n) //print the current solution to the board
{
    int i,j;
    printf("\n\n solution:\n\n", ++count);
   
    for(i=1;i<=n;i++)
    {
        printf("\t%d", i);
    }
    for(i=1;i<=n;i++)
    {
        printf("\n\n%d", i);
        for(j=1;j<=n;j++)
        {
           if(board[i]==j)
           {
              printf("\tQ");
           }
           else
           {
              printf("\t-");
           }
        }

    }
   
}

int place(int row,int column) //check if the queen can be placed at the current position (row, column)
{
int i;
for(i=1;i<=row-1;++i)
{
 if(board[i]==column)
   return 0;
 else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
}
 
return 1;
}

void queen(int row ,int n) //recursive function to solve the problem
{
    int column;
    for(column=1;column<=n;column++)
    {
        if(place(row,column))
        {
            board[row]=column;
            if(row==n)
            {
                print(n);
            }
            else
            {
                queen(row+1,n);
            }
        }
    }
   
   
}