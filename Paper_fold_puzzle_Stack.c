#include<stdio.h>

#define MAX_SIZE 100
typedef struct {
  int data[MAX_SIZE];
  int top;
}stack;

typedef struct {
  int data[MAX_SIZE];
  int rear;
  int front;
}queue;

stack s1;
queue q1;

void StackInit()
{
  s1.top = -1;
}

void pushStack(int data)
{
  if(s1.top == MAX_SIZE)
    printf("Stack is Full\n");
  else
    s1.data[++(s1.top)] = data;
}

void popStack()
{
  if(s1.top == -1)
    printf("Stack is Empty\n");
  else
    s1.top--;
}

int topStack()
{
  if(s1.top == -1)
    printf("Stack is Empty\n");
  else
    return s1.data[s1.top];
}

void QueuInit()
{
  q1.rear = -1;
  q1.front = -1;
}

void pushQueue(int data)
{
  if((q1.rear+1)%MAX_SIZE == q1.front)
    printf("Queue is Full\n");
  else if (q1.rear == -1 && q1.front == -1)
  {
     q1.front = q1.rear = 0;
     q1.data[q1.rear] = data;
  }
  else
  {
    q1.rear = (q1.rear+1)%MAX_SIZE;
    q1.data[q1.rear] = data;
  }
}

void popQueue()
{
  if(q1.rear == -1 && q1.front == -1)
    printf("Queue is Empty\n");
  else if (q1.rear == q1.front)
  {
    q1.rear = q1.front = -1;
  }
  else
  {
    q1.front = (q1.front+1)%MAX_SIZE;
  }
}

int frontQueue()
{
  if(q1.front != -1)
    return q1.data[q1.front];
  else
    printf("Queue is Empty\n");
}


int main()
{
  int n,i,j, final;
  int arr[MAX_SIZE];
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
  StackInit();
  QueuInit();

  for(i=0;i<strlen(command);i++)
  {
    j=0;
    if(command[i] == 'L' || command[i] == 'l')
    {
        for(;j<pow(2,n);j++)
        {
          if(j<pow(2,n-i-1))
          {
            pushStack(arr[j]);
            printf("stack[%d] = %d\n", s1.top, s1.data[s1.top]);
          }
          else
          {
            pushQueue(arr[j]);
           /* printf("queue[%d] = %d\n", q1.rear, q1.data[q1.rear]); */
          }
        }
    }

    if(command[i] == 'R' || command[i] == 'r')
    {
        for(;j<pow(2,n);j++)
        {
          if(j<pow(2,n-i-1))
          {
            pushStack(arr[j]);
          }
          else
          {
            pushQueue(arr[j]);
          }
        }
    }

  populateFinal();
  }

  for(final=0; final<pow(2,n); final++)
  {
    printf("%d ", s1.data[final]);
  }
  printf("\n");

}

int populateFinal()
{
  int temp = 0;
  while(s1.top != -1)
  {
    s1.data[temp++] = topStack();
    popStack();
    printf("%d \n", s1.data[temp-1]);
  }

  while(q1.rear != -1 && q1.front != -1)
  {
    s1.data[temp++] = frontQueue();
    popQueue();
  }

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
