#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//creating linked nodes
struct node
{
    int item;
    struct node *next;
};

typedef struct node node;

/* function to create new node and 
to insert it at its correct position 
and function will return the address of the head */
node *insert(node *head, int element)
{
    //creating new node for element
    node *x = (node *)malloc(sizeof(node));
    x->item = element;
    x->next = NULL;

    /* means no element in list so given 
    element will be the first element of the list */
    if (head == NULL)
    {
        return x;
    }

    //node pointer's for transerve
    node *traverse = head;
    node *previous = NULL;

    //traversing list for inserting
    while (traverse != NULL)
    {
        //condition
        if (traverse->item > x->item)
        {
            /* we are inserting element 
            at first position so element will be head*/
            if (traverse == head)
            {
                x->next = traverse;
                return x;
            }

            //inserting in between two nodes
            else
            {
                previous->next = x;
                x->next = traverse;
                return head;
            }
        }

        //going for next iteration
        previous = traverse;
        traverse = traverse->next;
    }

    //means element at the last position
    previous->next = x;
    x->next = NULL;
    return head;
}

//printing all the element of the list in order
void Display(node *stk)
{
    //No element in list
    if (stk == NULL)
    {
        printf("Empty List\n");
        return;
    }

    //printing all elements
    while (stk != NULL)
    {
        printf("%d\n", stk->item);
        stk = stk->next;
    }
}

int main()
{
    // input for no of elements
    int n = 0;
    scanf("\n%d", &n);

    //creating empty list
    node *head = NULL;

    //input with inserting element at correct position
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        scanf("\n%d", &x);
        head = insert(head, x);
    }

    //result
    Display(head);

    return 0;
}