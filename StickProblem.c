// Write a Code to find out the number of sticks required to form a given number N. 
// Available sticks are of lenght 2 power of n, like 2^0, 2^1, 2^2 etc.
// Eg, given Number 25, Sticks required 16, 8 and 1. Total number of sticks 3.

#include<stdio.h>

int main()
{
    int length = 5;
    int temp_len = length;
    int result = 0;

    if(length <= 0)
    {
        printf("Invalid length\n");
        return -1;
    }

    while( (temp_len/2) >= 1 )
    {
        if((temp_len%2)==1)
        {
            result++;
        }
        temp_len=temp_len/2;
    }

    printf("Number of stick requires: %d\n", result+1);
    return 0;
}
