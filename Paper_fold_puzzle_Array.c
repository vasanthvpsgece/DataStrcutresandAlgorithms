//A paper consists of a series of consecutive numbers from 1 up to 2^n values. For example, 
//For case 2^1, content of the paper is, 
//1 2 
//For case 2^2, content of the paper is, 
//1 2 3 4 
//For case 2^3, content of the paper is, 
//1 2 3 4 5 6 7 8 
//There will be n number of commands for 2^n case. Below are the commands, 
//L – Fold the paper from Left edge to Right edge 
//R – Fold the paper from Right edge to Left edge 
//After performing the n number of commands, there will be a single number in all layer of paper, you need to write down the numbers in all layers when you see the paper from upside of it. 
//Please provide an efficient algorithm. 

//Example: 
//Content of the paper (2^3): 
//1 2 3 4 5 6 7 8 
//Commands: LRL 
//Output: 
//5 4 1 8 7 2 3 6

#include<stdio.h>

int main()
{
  int n,i,j;
  int arr[100];
  char flag[100];
  char command[10];
  printf("Enter the power value:");
  scanf("%d", &n);

  for(i=0; i<pow(2,n); i++)
  {
    arr[i] = i+1;
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("Enter the command of length %d:", n);
  scanf("%s", command);

  for(j=1; j<=strlen(command); j++)
  {
    prepareFlagArray(flag, n, j);
    if(command[j-1] == 'l' || command[j-1] == 'L')
    {
        performCommandL(arr, flag, n);
    }
    else if(command[j-1] == 'r' || command[j-1] == 'R')
    {
        performCommandR(arr, flag, n);
    }
  }
}

int prepareFlagArray( int *flag, int n, int j)
{
  int i,k,m;

  for(i=0;i<pow(2,n);)
  {
    k=pow(2,n-j);
    while(k--)
    {
        flag[i] = 'L';
        i++;
    }
    k=pow(2,n-j);
    while(k--)
    {
        flag[i] = 'R';
        i++;
    }
  }

  for(i=0;i<pow(2,n);i++)
  {
    printf("%c ", flag[i]);
  }
  printf("\n");

}

int performCommandL( int *arr, int *flag, int n)
{
  int temp[100],i=0,Nn=pow(2,n);

  while(Nn)
  {
    if(flag[Nn-1] == 'L')
    {
      temp[i] = arr[Nn-1];
      i++;
    }
    Nn--;
  }

  for(Nn=0; Nn<pow(2,n); Nn++)
  {
    if(flag[Nn] == 'R')
    {
      temp[i] = arr[Nn];
      i++;
    }
  }

  for (i=0;i<pow(2,n);i++)
  {
    arr[i] = temp[i];
    printf("%d ", temp[i]);
  }
  printf("\n");
}

int performCommandR( int *arr, int *flag, int n)
{
  int temp[100],i=0,Nn=pow(2,n);

  while(Nn)
  {
    if(flag[Nn-1] == 'R')
    {
      temp[i] = arr[Nn-1];
      i++;
    }
    Nn--;
  }

  for(Nn=0; Nn<pow(2,n); Nn++)
  {
    if(flag[Nn] == 'L')
    {
      temp[i] = arr[Nn];
      i++;
    }
  }

  for (i=0;i<pow(2,n);i++)
  {
    arr[i] = temp[i];
    printf("%d ", temp[i]);
  }
  printf("\n");
}


int pow(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = pow(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}
