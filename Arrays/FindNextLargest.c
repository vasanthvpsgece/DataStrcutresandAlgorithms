#include<stdio.h>

int main()
{
   int num = 0;
   int array[100] = {0};
   int i=0, j=0, digit1 = 0, digit2 = 0;
   int exists = 0;

   printf("Enter any positive number : ");
   scanf("%d", &num);

   if (num <= 0)
   {
        printf("Invalid Entry\n");
        return FALSE;
   }

   while (num/10)
   {
        digit1 = num%10;
        num = num/10;
        digit2 = num%10;

        if (digit1 <= digit2)
        {
           array[i++] = digit1;
        }
        else
        {
           array[i++] = digit1;
           num = num/10;
           exists = 1;
           break;
        }
   }

   if (!exists)
   {
        printf("No Next larger number\n");
        return FALSE;
   }

   while ((digit2 < array[j]) && (j < i))
   {
        num = num*10+array[j];
        array[j] = -1;
        break;
   }

   j=0;
   while (j<i)
   {
        if (array[j] == -1)
        {
           j++;
           continue;
        }
        if (digit2 > array[j])
            num = num*10+array[j++];
        else
        {
            num = num*10+digit2;
            digit2 = 99;
        }
   }

   if (digit2 != 99)
        num = num*10+digit2;

   printf("Next large number: %d\n", num);
   return 0;
}
