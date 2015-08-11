/*------------------------------------------------------------/
/ Finding the minimum and maximum value from an Array.        /
/ Used Brute Force algorithm.                                 /
/------------------------------------------------------------*/

#include<stdio.h>
#define MAX_SIZE 100

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

   min = max = array[0];

   while(length)
   {
        if(array[length-1] > max)
            max = array[length-1];
        if(array[length-1] < min)
            min = array[length-1];
        length--;
   }


printf("Minimum: %d     Maximum: %d\n", min, max);
return 0;
}
