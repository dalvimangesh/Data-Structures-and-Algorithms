#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//linked node
struct node
{
    int item;
    struct node *next;
};

typedef struct node stack;

/* checking wheather stack is full or not by 
creating one node if it creates then stack is not full */
bool IsFULL(stack *stk)
{
    stack *ptr = (stack *)malloc(sizeof(stack));
    if (ptr == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* checking current stack is empty or not
by checking  pointer is null or not*/
bool IsEmpty(stack *stk)
{
    if (stk == NULL)
    {
        return true;
    }
    return false;
}

/* doing pushing element in top of stack 
by creating new node and then connecting it */
stack *push(stack *stk, int num)
{
    if (IsFULL(stk))
    {
        printf("Push Failure\n");
        return NULL;
    }

    stack *ptr = (stack *)malloc(sizeof(stack));
    ptr->item = num;
    ptr->next = stk;
    return ptr;
}

/* deleting top most element of the stack
with free of its space */
stack *pop(stack *stk)
{

    if (IsEmpty(stk))
    {
        printf("Pop Failure\n");
        return stk;
    }
    printf("%d\n", stk->item);
    stack *ptr = stk;
    stk = stk->next;
    free(ptr);
    return stk;
}

/* printing top most element of the stack */
void top(stack *stk)
{
    if (IsEmpty(stk))
    {
        printf("Invalid\n");
        return;
    }
    printf("%d\n", stk->item);
}

/* printing all the element of the stack if present */
void Display(stack *stk)
{
    if (stk == NULL)
    {
        printf("Empty List\n");
        return;
    }
    while (stk != NULL)
    {
        printf("%d\n", stk->item);
        stk = stk->next;
    }
}

int main()
{
    //creating empty stack
    stack *stk = NULL;

    //taking inputs for function calling
    while (true)
    {
        //
        int call = 0;
        scanf("\n%d", &call);

        if (call == 0) //isempty
        {
            if (IsEmpty(stk))
            {
                printf("Empty\n");
            }
            else
            {
                printf("Non Empty\n");
            }
        }

        if (call == 1) //push
        {
            int x = 0;
            scanf("\n%d", &x);
            stk = push(stk, x);
        }

        if (call == 2) //pop
        {
            stk = pop(stk);
        }

        if (call == 3) //top
        {
            top(stk);
        }

        if (call == 4) //Display
        {
            Display(stk);
        }

        if (call == 5) //end of function calls
            break;
    }

    return 0;
}