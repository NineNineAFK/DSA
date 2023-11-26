

#include<stdio.h>

// Function to calculate the maximum profit and the result vector
//n: The number of items in the set.
//weight[]: An array representing the weights of the items.
//profit[]: An array representing the profits associated with the items.
//capacity: The capacity of the knapsack.
void knapsack(int n, float weight[], float profit[], float capacity) 
{
   float x[20], tp = 0;
   int i, j, u;
   u = capacity;

   // Initialize the result vector with zeros
   for (i = 0; i < n; i++)
      x[i] = 0.0;

   // Iterate through each item
   for (i = 0; i < n; i++) {
      // If the current item's weight is greater than the remaining capacity, break the loop
      if (weight[i] > u)
         break;
      else {
         // Include the current item in the knapsack
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }

   // If there is still remaining capacity, include a fraction of the current item
   if (i < n)
      x[i] = u / weight[i];

   tp = tp + (x[i] * profit[i]);

   printf("\nThe result vector is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);    // '\t' add a space (tab) in between
      
   printf("\nMaximum profit is:- %f", tp);

}

int main() {
   float weight[20], profit[20], capacity;
   int objects, i, j;
   float ratio[20], temp;

   printf("\nEnter the no. of objects:- ");
   scanf("%d", &objects);

   printf("\nEnter the wts and profits of each object:- ");
   for (i = 0; i < objects; i++) {
      scanf("%f %f", &weight[i], &profit[i]);
   }

   printf("\nEnter the capacity of knapsack:- ");
   scanf("%f", &capacity);

   // Calculate the profit-to-weight ratio for each item
   for (i = 0; i < objects; i++) {
      ratio[i] = profit[i] / weight[i];
   }

   // Sort the items based on the profit-to-weight ratio in descending order, bubble sort
   for (i = 0; i < objects; i++) {
      for (j = i + 1; j < objects; j++) {
         if (ratio[i] < ratio[j]) {

            //swap ratio
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            //swapping weights
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            // swapping profit
            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }

   knapsack(objects, weight, profit, capacity);
   return(0);
}

//
//This code implements the fractional knapsack problem using a greedy approach. The user is prompted to enter the number of items, their weights, and profits. The program then calculates the maximum profit and the result vector, which indicates the fraction of each item included in the knapsack..</s>