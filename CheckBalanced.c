#include<stdio.h>

#define MAX_SIZE 100

typedef struct {
  char data[MAX_SIZE+1];
  int top;
}stack;

void initStack(stack *s)
{
        s->top = -1;
}

int pushStack(stack *s, char data)
{
    if(s->top < MAX_SIZE)
    {
        s->data[++(s->top)] = data;
        return TRUE;
    }

return FALSE;
}

void popStack(stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is Empty\n");
    }
    (s->top)--;
}

char topStack(stack *s)
{
   if(s->top == -1)
    {
        printf("Stack is Empty\n");
        return FALSE;
    }
    return(s->data[s->top]);
}

int main()
{
    stack *s=NULL;
    char parantheses[MAX_SIZE+1]={0};
    int i=0,balanced=TRUE;
    char ret;

    printf("Enter the sequesnce of Parantheses:");
    scanf("%s", parantheses);

    if(strlen(parantheses)%2 != 0)
    {
        printf("Not Balanced\n");
        return 0;
    }
    s=(stack *)malloc(sizeof(stack *));
    initStack(s);

    for(i=0; i<strlen(parantheses); i++)
    {
        if(parantheses[i] == '(' || parantheses[i] == '{' || parantheses[i] == '[')
        {
            ret = pushStack(s, parantheses[i]);
            if (ret = FALSE)
            {
                printf("Error in Process\n");
                break;
            }
        }
        else if (parantheses[i] == ')' || parantheses[i] == '}' || parantheses[i] == ']')
        {
           ret = topStack(s);
           if (ret == FALSE)
            {
                printf("Not Balanced\n");
                balanced = FALSE;
                break;
            }
            else
            {
                if ((parantheses[i] == ')' && ret != '(') ||
                    (parantheses[i] == '}' && ret != '{') ||
                    (parantheses[i] == ']' && ret != '['))
                {
                    printf("Not Balanced\n");
                    break;
                }
            }
            popStack(s);
        }
        else
        {
            printf("Invalid Input\n");
            balanced = FALSE;
            break;
        }
    }

    if(s->top == -1 && balanced == TRUE)
        printf("Balanced\n");

    free(s);
    s=NULL;
    return 0;
}
