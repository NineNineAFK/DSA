
      }
   }

   // If there is still remaining capacity, include a fraction of the current item
   if (i < n)
      x[i] = u / weight[i];

   tp = tp + (x[i] * profit[i]);