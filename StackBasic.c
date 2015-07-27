#include<stdio.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
}stack;

int main()
{
  stack *s1=NULL;
  int option, exit=FALSE;
  s1=(stack *)malloc(sizeof(stack *));
  initStack(s1);

  while(!exit)
  {
     printf("Stack Operations\n\t1.Push\n\t2.Pop\n\t3.Print Top\n\t4.Display Stack\n\t5.Exit\n\n");
     printf("Enter the Option:");
     scanf("%d", &option);

     switch(option)
     {
        case 1:
            pushStack(s1);
            break;
        case 2:
            popStack(s1);
            break;
        case 3:
            printTop(s1);
            break;
        case 4:
            displayStack(s1);
            break;
        case 5:
            exit = TRUE;
            break;
        default:
            printf("Invalid Option\n");
            break;
     }
  }

return 0;
}

int initStack(stack *s)
{
  if(s==NULL)
    printf("Stack allocation fails\n");
  else
    s->top = -1;
return 0;
}

int pushStack(stack *s)
{
  int data;
  if(s->top == MAX_SIZE)
  {
     printf("Stack is Full\n");
     return 0;
  }
  else
  {
     printf("Enter the data:\n");
     scanf("%d",&data);
     s->data[++(s->top)] = data;
     printf("Stack Updated\n");
  }
  return 0;
}

int popStack(stack *s)
{
  if(s->top == -1)
  {
     printf("Stack is Empty\n");
     return 0;
  }
  else
  {
     (s->top)--;
     printf("Stack Updated\n");
  }
  return 0;
}

int printTop(stack *s)
{
  if(s->top == -1)
  {
     printf("Stack is Empty\n");
     return 0;
  }
  else
  {
     printf("%d\n", s->data[s->top]);
  }
  return 0;
}

int displayStack(stack *s)
{
  int temp=s->top;
  if(temp == -1)
  {
     printf("Stack is Empty\n");
     return 0;
  }
  while(temp != -1)
  {
     printf("%d\n", s->data[temp--]);
  }
  return 0;
}
