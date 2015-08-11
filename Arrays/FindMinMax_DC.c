/*------------------------------------------------------------/
/ Finding the minimum and maximum value from an Array.        /
/ Using divide and Conqure method.                            /
/------------------------------------------------------------*/

#include<stdio.h>
#define MAX_SIZE 100

int findMinMax (int [], int, int, int *, int *);
int main()
{
   int array[MAX_SIZE] = {0};
   int length = 0;
   int min = 0, max = 0;

   printf("Enter the Lenght of the Array: ");
   scanf("%d", &length);

   if(length > MAX_SIZE)
   {
        printf("Size exceeds the limit of %d", MAX_SIZE);
        return FALSE;
   }

   printf("Enter the array values:\n");
   for (int i=0; i<length; i++)
   {
        scanf("%d", &array[i]);
   }

   findMinMax (array, 0, length-1, &min, &max);
   printf("Minimum: %d  Maximum: %d\n", min, max);

   return 0;
}

int findMinMax (int array[], int i, int j, int *min, int *max)
{
   int minR = 0, maxR = 0, minL = 0, maxL = 0;

   if (i > j)
        return FALSE;
   if (i == j)
   {
        *min = *max = array [i];
        return TRUE;
   }
   else
   {
        findMinMax (array, i, (i+j)/2, &minL, &maxL);
        findMinMax (array, ((i+j)/2)+1, j, &minR, &maxR);
   }

   if (minL < minR) *min = minL;
   else *min = minR;

   if (maxL > maxR) *max = maxL;
   else *max = maxR;

   return 0;
}
